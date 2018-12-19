/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include "rtconfig.h"
.section .text, "ax"

#ifdef RT_USING_SMP
#define rt_hw_interrupt_disable rt_hw_local_irq_disable
#define rt_hw_interrupt_enable  rt_hw_local_irq_enable
#endif

/*
 * rt_base_t rt_hw_interrupt_disable();
 */
.globl rt_hw_interrupt_disable
rt_hw_interrupt_disable:
    /* todo: mask interrupt, return previous state

/*
 * void rt_hw_interrupt_enable(rt_base_t level);
 */
.globl rt_hw_interrupt_enable
rt_hw_interrupt_enable:
    /* todo: restore interrupt state with given value

/*
 * #ifdef RT_USING_SMP
 * void rt_hw_context_switch_to(rt_ubase_t to, stuct rt_thread *to_thread);
 * #else
 * void rt_hw_context_switch_to(rt_uint32 to);
 * #endif
 */
.globl rt_hw_context_switch_to
rt_hw_context_switch_to:
    /* todo: sp = *(void*)to; */
#ifdef RT_USING_SMP
    /* todo: rt_cpus_lock_status_restore(to_thread); */
#endif /*RT_USING_SMP*/
    /* todo: restore thread registers from sp
             return from exception
    */

.section .text.isr, "ax"
/*
 * #ifdef RT_USING_SMP
 * void rt_hw_context_switch(rt_ubase_t from, rt_ubase_t to, struct rt_thread *to_thread);
 * #else
 * void rt_hw_context_switch(rt_uint32 from, rt_uint32 to);
 * #endif
 */
    .globl rt_hw_context_switch
rt_hw_context_switch:
    /* todo: push all registers */

    /* todo: *(void*)from = sp; @ store sp in preempted tasks TCB
             sp = *(void*)to;   @ get new task stack pointer
    */

#ifdef RT_USING_SMP
    /* todo: call rt_cpus_lock_status_restore(to_thread); */
#endif /*RT_USING_SMP*/

    /* todo: restore thread registers from sp
             return from exception
    */

/*
 * #ifdef RT_USING_SMP
 * void rt_hw_context_switch_interrupt(void *context, rt_ubase_t from, rt_ubase_t to, struct rt_thread *to_thread);
 * #else
 * void rt_hw_context_switch_interrupt(rt_uint32 from, rt_uint32 to);
 * #endif
 */
.globl rt_hw_context_switch_interrupt
rt_hw_context_switch_interrupt:
#ifdef RT_USING_SMP
    /* Differences with rt_hw_context_switch, in interrupt handle,
       registers are almost always stored in the system stack,
       So we have to transfer them to the thread stack. */

    /* todo: pop registers from system stack (param:context) and push to thread sp */

    /* todo: *(void**)from = sp; @ store sp in preempted tasks TCB
             sp = *(void**)to;   @ get new task stack pointer
    */

    /* todo: call rt_cpus_lock_status_restore(to); */

    /* todo: restore thread registers from sp
             return from exception
    */
#else /*RT_USING_SMP*/
    /* todo:
    if (rt_thread_switch_interrupt_flag == 0)
    {
        rt_interrupt_from_thread = from;
        rt_thread_switch_interrupt_flag = 1;
    }
    rt_interrupt_to_thread = to;
    return;
    */
#endif /*RT_USING_SMP*/


/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

.section .text, "ax"

/*
 * void rt_hw_context_switch_to(rt_ubase_t to, stuct rt_thread *to_thread);
 */
.globl rt_hw_context_switch_to
rt_hw_context_switch_to:
    /* todo: 
    sp = *(void*)to;
    */

    /* todo:
    rt_cpus_lock_status_restore(to_thread);
    */

    /* todo:
    restore thread registers from sp
    return from exception
    */

.section .text.isr, "ax"
/*
 * void rt_hw_context_switch(rt_ubase_t from, rt_ubase_t to, struct rt_thread *to_thread);
 */
    .globl rt_hw_context_switch
rt_hw_context_switch:
    /* todo: 
    push all registers
    */

    /* todo:
    *(void*)from = sp; @ store sp in preempted tasks TCB
    sp = *(void*)to;   @ get new task stack pointer
    */

    /* todo:
    call rt_cpus_lock_status_restore(to);
    */

    /* todo:
    restore thread registers from sp
    return from exception
    */

/*
 * void rt_hw_context_switch_interrupt(void *context, rt_ubase_t from, rt_ubase_t to, struct rt_thread *to_thread);
 */
.globl rt_hw_context_switch_interrupt
rt_hw_context_switch_interrupt:
    /* Differences with rt_hw_context_switch, in interrupt handle,
       registers are almost always stored in the system stack,
       So we have to transfer them to the thread stack. */

    /* todo:
    pop registers from system stack (param:context) and push to thread sp
    */

    /* todo:
    *(void**)from = sp; @ store sp in preempted tasks TCB
    sp = *(void**)to;   @ get new task stack pointer
    */

    /* todo:
    call rt_cpus_lock_status_restore(to);
    */

    /* todo:
    restore thread registers from sp
    return from exception
    */

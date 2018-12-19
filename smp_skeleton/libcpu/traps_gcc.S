/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include "rtconfig.h"
.text
/*irq routine*/
.globl vector_irq
vector_irq:
    /* todo: save regs */

    /* todo: call rt_interrupt_enter() */

    /* todo: call rt_hw_trap_irq() */

    /* todo: call rt_interrupt_leave() */

#ifdef RT_USING_SMP

    /* todo: call rt_scheduler_do_irq_switch(context) */
    /* note: context is the address of saved regs
       note: if need scheduler, rt_scheduler_do_irq_switch will not return
    */

#else /*RT_USING_SMP*/
    /* todo:
    if (rt_thread_switch_interrupt_flag != 0)
    {
        rt_thread_switch_interrupt_flag = 0;

        todo: push regs to [sp]
     
        todo: *rt_interrupt_from_thread = sp;

        todo: sp = *rt_interrupt_to_thread;
    }
    */
#endif /*RT_USING_SMP*/

    /* todo: restore thread registers from sp
             return from exception
    */

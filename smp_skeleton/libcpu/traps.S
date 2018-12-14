/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

.text
/*irq routine*/
.globl vector_irq
vector_irq:

    /* todo: save regs*/

    /* todo: call rt_interrupt_enter*/
    /* todo: call rt_hw_trap_irq*/
    /* todo: call rt_interrupt_leave*/

    /* todo: call rt_scheduler_do_irq_switch
    note: param of rt_scheduler_do_irq_switch is the address of saved regs
    note: if need scheduler, rt_scheduler_do_irq_switch will not return
    */

    /* todo: restore regs*/

    /* todo: exec ret from exception */


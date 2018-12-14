/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

.text
/* reset entry */
.globl _reset
_reset:
    /* todo: arch init */

    /* todo: set stack */

    /* todo: clear .bss */

    /* todo: call C++ constructors of global objects */

    /* start RT-Thread Kernel */
    /* todo: call _rtthread_startup*/

/*todo: exception vector */

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

.global secondary_cpu_start
secondary_cpu_start:
    /* todo: this cpu init */

    /* todo: init stack of this cpu*/

    /* todo: jump to secondary_cpu_c_start*/

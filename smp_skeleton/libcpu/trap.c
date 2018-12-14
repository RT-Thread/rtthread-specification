/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtthread.h>
#include <rthw.h>
#include <board.h>

void rt_hw_trap_irq(void)
{
    void *param;
    unsigned long ir = 0;
    rt_isr_handler_t isr_func;
    extern struct rt_irq_desc isr_table[];

    /* todo: get irq nr
    ir = get hw nr;
    */

    /* get interrupt service routine */
    isr_func = isr_table[ir].handler;
#ifdef RT_USING_INTERRUPT_INFO
    isr_table[ir].counter++;
#endif
    if (isr_func)
    {
        /* Interrupt for myself. */
        param = isr_table[ir].param;
        /* turn to interrupt service routine */
        isr_func(ir, param);
    }

    /* todo: end of interrupt */
}

/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rthw.h>
#include <rtthread.h>
#include <stdint.h>

#include "board.h"

void rt_hw_timer_isr(int vector, void *param)
{
    rt_tick_increase();

    /*todo: clear interrupt */
}

int rt_hw_timer_init(void)
{
    /*todo: timer hw init*/

    /*todo: install timer interrupt
    rt_hw_interrupt_install(TIMER_CPU0, rt_hw_timer_isr, RT_NULL, "tick");
    rt_hw_interrupt_umask(IRQ_TIMER_CPU0);
    */

    return 0;
}
INIT_BOARD_EXPORT(rt_hw_timer_init);

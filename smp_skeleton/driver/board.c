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

#include "board.h"

extern void idle_wfi(void);
extern void rt_hw_ipi_handler_install(int ipi_vector, rt_isr_handler_t ipi_isr_handler);

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

/**
 * This function will initialize beaglebone board
 */
void rt_hw_board_init(void)
{
    /*initialize hardware interrupt */
    rt_hw_interrupt_init();

    /* initialize system heap */
    rt_system_heap_init(HEAP_BEGIN, HEAP_END);

    rt_components_board_init();
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);

    rt_thread_idle_sethook(idle_wfi);

#ifdef RT_USING_SMP
    /* install IPI handle */
    rt_hw_ipi_handler_install(RT_SCHEDULE_IPI, rt_scheduler_ipi_handler);
#endif
}

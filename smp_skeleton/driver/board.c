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
#include "drv_timer.h"

void idle_wfi(void)
{
    /*todo: wait for wakeup or do nothing */
}

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

    /*todo: install IPI interrupt 
    note:RT_SCHEDULE_IPI_IRQ(value is 0) may be different from real IRQ, please adjust it)

    rt_hw_interrupt_install(RT_SCHEDULE_IPI_IRQ + adjust_value, rt_scheduler_ipi_handler, RT_NULL, "ipi");
    rt_hw_interrupt_umask(RT_SCHEDULE_IPI_IRQ + adjust_value);

    */
}

void rt_hw_spin_lock(rt_hw_spinlock_t *lock)
{
    /* todo: */
}

void rt_hw_spin_unlock(rt_hw_spinlock_t *lock)
{
    /* todo: */
}

void rt_hw_mb(void)
{
    /* todo: */
}

void rt_hw_ipi_send(int ipi_vector, unsigned int cpu_mask)
{
    /* todo: send ipi */
    /* note: ipi_vector maybe different with irq_vector */
}


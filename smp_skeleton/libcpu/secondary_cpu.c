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

void rt_hw_timer2_isr(int vector, void *param)
{
    rt_tick_increase();
    /* todo: clear interrupt */
}

void set_secondary_cpu_boot_address(void)
{
    /* todo: Set the startup address of the secondary cpu to <secondary_cpu_start> */
}

void rt_hw_secondary_cpu_up(void)
{

    set_secondary_cpu_boot_address();
    /* todo: arch_mb() */
    /* todo: plat secondary cpu start up */
}

void secondary_cpu_c_start(void)
{
    /* todo: this cpu interrupt vector init */

    rt_hw_spin_lock(&_cpus_lock);

    /* todo: this cpu interrupt controller init */
    /* todo: this cpu timer init */
    /* todo: this cpu timer interrupt config */

    rt_system_scheduler_start();
}

void rt_hw_secondary_cpu_idle_exec(void)
{
    /* todo: wait for wakeup or do nothing*/
}

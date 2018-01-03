/*
 * File      : drv_cputime.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2017 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtdevice.h>
#include <rtthread.h>

#include "drv_cputime.h"
#include <board.h>

static float hw_cputime_getres(void)
{
    return 0;
}

static uint32_t hw_cputime_gettime(void)
{
    return 0;
}

const static struct rt_clock_cputime_ops _hw_cputime_ops = 
{
    hw_cputime_getres,
    hw_cputime_gettime
};

int hw_cputime_init(void)
{
    clock_cpu_setops(&_hw_cputime_ops);

    return 0;
}
INIT_BOARD_EXPORT(hw_cputime_init);

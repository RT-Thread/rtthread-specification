/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
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

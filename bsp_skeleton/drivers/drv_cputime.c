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

#ifdef RT_USING_CPUTIME

static float skt_cputime_getres(void)
{
    return 0;
}

static uint32_t skt_cputime_gettime(void)
{
    return 0;
}

const static struct rt_clock_cputime_ops skt_cputime_ops =
{
    skt_cputime_getres,
    skt_cputime_gettime
};

int rt_hw_cputime_init(void)
{
    clock_cpu_setops(&skt_cputime_ops);

    return 0;
}
INIT_BOARD_EXPORT(rt_hw_cputime_init);

#endif /* RT_USING_CPUTIME */

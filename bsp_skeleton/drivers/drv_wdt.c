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
#include "drv_wdt.h"

#ifdef RT_USING_WDT

static struct rt_watchdog_device wdt_dev;

static rt_err_t skt_wdt_init(rt_watchdog_t *wdt)
{
    rt_err_t ret = RT_EOK;

    /* Todo: init watchdog */
    return ret;
}

static rt_err_t skt_wdt_control(rt_watchdog_t *wdt, int cmd, void *arg)
{
    rt_err_t ret = RT_EOK;

    switch (cmd)
    {
    case RT_DEVICE_CTRL_WDT_SET_TIMEOUT:

        /* Todo:set wdt timeout value */
        break;
    case RT_DEVICE_CTRL_WDT_START:

        /* Todo:enable wdt */
        break;
    case RT_DEVICE_CTRL_WDT_STOP:

        /* Todo:stop wdt */
        break;

    case RT_DEVICE_CTRL_WDT_KEEPALIVE:

        /* Todo:refresh wdt */
        break;
    default:

        break;
    }

    return ret;
}

const static struct rt_watchdog_ops skt_wdt_ops =
{
    skt_wdt_init,
    skt_wdt_control
};

int rt_hw_wdt_init(void)
{
    rt_err_t ret = RT_EOK;

    wdt_dev.ops = &skt_wdt_ops;

    ret = rt_hw_watchdog_register(&wdt_dev, "wdt", RT_DEVICE_FLAG_STANDALONE, RT_NULL);

    return ret;
}
INIT_BOARD_EXPORT(rt_hw_wdt_init);

#endif /* RT_USING_WDT */

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

static rt_err_t hw_wdt_init(rt_watchdog_t *wdt)
{
    /* Todo: init watchdog */

    return RT_EOK;
}

static rt_err_t hw_wdt_control(rt_watchdog_t *wdt, int cmd, void *arg)
{
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

    return RT_EOK;
}

const static struct rt_watchdog_ops _wdt_ops =
{
    hw_wdt_init,
    hw_wdt_control
};

int rt_hw_wdt_init(void)
{
    static struct rt_watchdog_device wdt_device;

    wdt_device.ops = &_wdt_ops;

    rt_hw_watchdog_register(&wdt_device, "wdt", RT_DEVICE_FLAG_STANDALONE, RT_NULL);

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_wdt_init);

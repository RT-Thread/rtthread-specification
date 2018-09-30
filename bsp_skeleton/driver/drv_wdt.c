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

static rt_err_t _wdt_init(rt_watchdog_t *wdt)
{
    return RT_EOK;
}

static rt_err_t _wdt_control(rt_watchdog_t *wdt, int cmd, void *arg)
{
    switch (cmd)
    {
    case RT_DEVICE_CTRL_WDT_SET_TIMEOUT:
        break;
    case RT_DEVICE_CTRL_WDT_START:
        break;
    case RT_DEVICE_CTRL_WDT_STOP:
        break;

    case RT_DEVICE_CTRL_WDT_KEEPALIVE:
        break;
    default:
        break;
    }

    return RT_EOK;
}

struct rt_watchdog_ops _wdt_ops =
{
    _wdt_init,
    _wdt_control
};

static struct rt_watchdog_device _wdt_device;
int rt_hw_wdt_init(void)
{
    _wdt_device.ops = &_wdt_ops;
    rt_hw_watchdog_register(&_wdt_device, "WDT", RT_DEVICE_FLAG_STANDALONE, &_wdt_param);

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_wdt_init);

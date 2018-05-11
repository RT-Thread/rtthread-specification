/*
 * File      : drv_wdt.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2017, RT-Thread Development Team
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

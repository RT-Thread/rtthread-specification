/*
 * File      : drv_rtc.c
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
#include "drv_rtc.h"

static struct rt_device rtc;
static rt_err_t hw_rtc_open(rt_device_t dev, rt_uint16_t oflag)
{
    return RT_EOK;
}

static rt_size_t hw_rtc_read(rt_device_t dev, rt_off_t pos, void* buffer, rt_size_t size)
{
    return 0;
}

static rt_err_t hw_rtc_control(rt_device_t dev, int cmd, void *args)
{
    return RT_EOK;
}

int rt_hw_rtc_init(void)
{
    rtc.type	= RT_Device_Class_RTC;
    /* register rtc device */
    rtc.init 	= RT_NULL;
    rtc.open 	= hw_rtc_open;
    rtc.close	= RT_NULL;
    rtc.read 	= hw_rtc_read;
    rtc.write	= RT_NULL;
    rtc.control = hw_rtc_control;

    /* no private */
    rtc.user_data = RT_NULL;

    rt_device_register(&rtc, "rtc", RT_DEVICE_FLAG_RDWR);

    return;
}
INIT_DEVICE_EXPORT(rt_hw_rtc_init);

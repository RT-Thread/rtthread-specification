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
#include "drv_rtc.h"

static struct rt_device rtc;
static rt_err_t hw_rtc_open(rt_device_t dev, rt_uint16_t oflag)
{
    return RT_EOK;
}

static rt_size_t hw_rtc_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    return 0;
}

static rt_err_t hw_rtc_control(rt_device_t dev, int cmd, void *args)
{
    return RT_EOK;
}

int rt_hw_rtc_init(void)
{
    rtc.type    = RT_Device_Class_RTC;
    /* register rtc device */
    rtc.init    = RT_NULL;
    rtc.open    = hw_rtc_open;
    rtc.close   = RT_NULL;
    rtc.read    = hw_rtc_read;
    rtc.write   = RT_NULL;
    rtc.control = hw_rtc_control;

    /* no private */
    rtc.user_data = RT_NULL;

    rt_device_register(&rtc, "rtc", RT_DEVICE_FLAG_RDWR);

    return;
}
INIT_DEVICE_EXPORT(rt_hw_rtc_init);

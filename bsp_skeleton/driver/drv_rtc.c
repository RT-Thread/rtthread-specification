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


static rt_err_t hw_rtc_open(rt_device_t dev, rt_uint16_t oflag)
{
    /* TBD:enable RTC Hardware */
    return RT_EOK;
}

static rt_size_t hw_rtc_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    /* TBD:get RTC time */
    return 0;
}
static rt_size_t hw_rtc_write(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    /* TBD:set RTC time */
    return 0;
}
static rt_err_t hw_rtc_control(rt_device_t dev, int cmd, void *args)
{
    /* TBD:control RTC */
    return RT_EOK;
}

int rt_hw_rtc_init(void)
{
    static struct rt_device rtc;

    /* TBD: Init RTC Hardware */

    rtc.type    = RT_Device_Class_RTC;
    /* register rtc device */
    rtc.rx_indicate = RT_NULL;
    rtc.tx_complete = RT_NULL;
    rtc.init    = RT_NULL;
    rtc.open    = hw_rtc_open;
    rtc.close   = RT_NULL;
    rtc.read    = hw_rtc_read;
    rtc.write   = hw_rtc_write;
    rtc.control = hw_rtc_control;
    rtc.user_data = RT_NULL;

    rt_device_register(&rtc, "rtc", RT_DEVICE_FLAG_RDWR);

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_rtc_init);

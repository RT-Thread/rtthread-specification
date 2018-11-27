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

static rt_err_t skt_rtc_init(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    /* Todo: init RTC */

    return ret;
}

static rt_err_t skt_rtc_open(rt_device_t dev, rt_uint16_t oflag)
{
    rt_err_t ret = RT_EOK;
    RT_ASSERT(dev != RT_NULL);

    /* Todo:enable RTC Hardware */
    return ret;
}

static rt_err_t skt_rtc_close(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    /* Todo: close RTC */

    return ret;
}

static rt_size_t skt_rtc_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    /* Todo:get RTC time */
    return 0;
}
static rt_size_t skt_rtc_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    /* Todo:set RTC time */
    return 0;
}
static rt_err_t skt_rtc_control(rt_device_t dev, int cmd, void *args)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    /* Todo:control RTC */
    return ret;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops skt_rtc_ops =
{
    skt_rtc_init,
    skt_rtc_open,
    skt_rtc_close,
    skt_rtc_read,
    skt_rtc_write,
    skt_rtc_control
};
#endif

int rt_hw_rtc_init(void)
{
    rt_err_t ret = RT_EOK;
    static struct rt_device rtc_dev;

    rtc_dev.type    = RT_Device_Class_RTC;
    rtc_dev.rx_indicate = RT_NULL;
    rtc_dev.tx_complete = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    lcd_dev.ops        = &skt_lcd_ops;
#else
    rtc_dev.init    = skt_rtc_init;
    rtc_dev.open    = skt_rtc_open;
    rtc_dev.close   = skt_rtc_close;
    rtc_dev.read    = skt_rtc_read;
    rtc_dev.write   = skt_rtc_write;
    rtc_dev.control = skt_rtc_control;
#endif

    rtc_dev.user_data = RT_NULL;

    ret = rt_device_register(&rtc_dev, "rtc", RT_DEVICE_FLAG_RDWR);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_rtc_init);

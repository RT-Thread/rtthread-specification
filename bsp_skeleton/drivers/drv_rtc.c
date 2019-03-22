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

#ifdef RT_USING_RTC

static struct rt_device rtc_dev;

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
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    RT_NULL,
    skt_rtc_control
};
#endif

int rt_hw_rtc_init(void)
{
    rt_err_t ret = RT_EOK;

    rtc_dev.type    = RT_Device_Class_RTC;
    rtc_dev.rx_indicate = RT_NULL;
    rtc_dev.tx_complete = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    rtc_dev.ops        = &skt_rtc_ops;
#else
    rtc_dev.init    = RT_NULL;
    rtc_dev.open    = RT_NULL;
    rtc_dev.close   = RT_NULL;
    rtc_dev.read    = RT_NULL;
    rtc_dev.write   = RT_NULL;
    rtc_dev.control = skt_rtc_control;
#endif

    rtc_dev.user_data = RT_NULL;

    ret = rt_device_register(&rtc_dev, "rtc", RT_DEVICE_FLAG_RDWR);

    return ret;
}
INIT_BOARD_EXPORT(rt_hw_rtc_init);

#endif /* RT_USING_RTC */

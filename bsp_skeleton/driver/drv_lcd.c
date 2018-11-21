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
#include "drv_lcd.h"

static rt_err_t skt_lcd_init(rt_device_t device)
{
    RT_ASSERT(device != RT_NULL);

    /* Todo: Init LCD */

    return RT_EOK;
}

static rt_err_t skt_lcd_open(rt_device_t device)
{
    RT_ASSERT(device != RT_NULL);

    /* Todo: Enable LCD */

    return RT_EOK;
}

static rt_err_t skt_lcd_close(rt_device_t device)
{
    RT_ASSERT(device != RT_NULL);

    /* Todo: Close LCD */

    return RT_EOK;
}

static rt_err_t skt_lcd_read(rt_device_t device)
{
    RT_ASSERT(device != RT_NULL);

    /* Todo: read LCD */

    return RT_EOK;
}

static rt_err_t skt_lcd_write(rt_device_t device)
{
    RT_ASSERT(device != RT_NULL);

    /* Todo: write LCD */

    return RT_EOK;
}

static rt_err_t skt_lcd_control(rt_device_t device, int cmd, void *args)
{
    switch (cmd)
    {
    case RTGRAPHIC_CTRL_RECT_UPDATE:

        /* Todo: update LCD data */
        break;

    case RTGRAPHIC_CTRL_POWERON:
        /* Todo: power on */
        break;

    case RTGRAPHIC_CTRL_POWEROFF:
        /* Todo: power off */
        break;

    case RTGRAPHIC_CTRL_GET_INFO:
        /* Todo: get lcd_info and store to args*/
        break;

    case RTGRAPHIC_CTRL_SET_MODE:

        break;
    default:
        break;
    }

    return RT_EOK;
}

int rt_hw_lcd_init(void)
{
    rt_err_t ret;
    static struct rt_device_graphic_info lcd_info;
    static struct rt_device lcd_dev;

    /* Todo: Init lcd_info */

    lcd_dev.type    = RT_Device_Class_Graphic;
    lcd_dev.init    = skt_lcd_init;
    lcd_dev.open    = skt_lcd_open;
    lcd_dev.close   = skt_lcd_close;
    lcd_dev.read    = skt_lcd_read;
    lcd_dev.write   = skt_lcd_write;
    lcd_dev.control = skt_lcd_control;

    lcd_dev.user_data = (void *)&lcd_info;

    ret = rt_device_register(&lcd_dev, "lcd", RT_DEVICE_FLAG_RDWR);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_lcd_init);

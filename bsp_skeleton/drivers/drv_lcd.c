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

static struct rt_device_graphic_info lcd_info;
static struct rt_device lcd_dev;

static rt_err_t skt_lcd_init(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    /* Todo: init LCD */

    return ret;
}

static rt_err_t skt_lcd_open(rt_device_t dev, rt_uint16_t oflag)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    /* Todo: enable LCD */

    return ret;
}

static rt_err_t skt_lcd_close(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

    /* Todo: close LCD */

    return ret;
}

static rt_size_t skt_lcd_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    /* Todo: read LCD */

    return 0;
}

static rt_size_t skt_lcd_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    RT_ASSERT(dev != RT_NULL);

    /* Todo: write LCD */
    return 0;
}

static rt_err_t skt_lcd_control(rt_device_t dev, int cmd, void *args)
{
    rt_err_t ret = RT_EOK;

    RT_ASSERT(dev != RT_NULL);

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

    return ret;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops skt_lcd_ops =
{
    skt_lcd_init,
    skt_lcd_open,
    skt_lcd_close,
    skt_lcd_read,
    skt_lcd_write,
    skt_lcd_control
};
#endif

int rt_hw_lcd_init(void)
{
    rt_err_t ret = RT_EOK;

    /* Todo: Init lcd_info */

    lcd_dev.type    = RT_Device_Class_Graphic;
    lcd_dev.rx_indicate = RT_NULL;
    lcd_dev.tx_complete = RT_NULL;

#ifdef RT_USING_DEVICE_OPS
    lcd_dev.ops        = &skt_lcd_ops;
#else
    lcd_dev.init    = skt_lcd_init;
    lcd_dev.open    = skt_lcd_open;
    lcd_dev.close   = skt_lcd_close;
    lcd_dev.read    = skt_lcd_read;
    lcd_dev.write   = skt_lcd_write;
    lcd_dev.control = skt_lcd_control;
#endif

    lcd_dev.user_data = (void *)&lcd_info;

    ret = rt_device_register(&lcd_dev, "lcd", RT_DEVICE_FLAG_RDWR);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_lcd_init);

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

    /* TBD: init LCD Hardware */

    return RT_EOK;
}

static rt_err_t skt_lcd_control(rt_device_t device, int cmd, void *args)
{
    switch (cmd)
    {
    case RTGRAPHIC_CTRL_RECT_UPDATE:

        /* TBD */
        break;

    case RTGRAPHIC_CTRL_POWERON:
        /* TBD */
        break;

    case RTGRAPHIC_CTRL_POWEROFF:
        /* TBD */
        break;

    case RTGRAPHIC_CTRL_GET_INFO:
        /* TBD */
        break;

    case RTGRAPHIC_CTRL_SET_MODE:

        /* TBD */
        break;
    }

    return RT_EOK;
}

int rt_hw_lcd_init(void)
{
    rt_err_t ret;
    static struct rt_device_graphic_info lcd_info;
    static struct rt_device lcd_dev;

    /* TBD: Init lcd_info */

    lcd_dev.type    = RT_Device_Class_Graphic;
    lcd_dev.init    = skt_lcd_init;
    lcd_dev.open    = RT_NULL;
    lcd_dev.close   = RT_NULL;
    lcd_dev.read    = RT_NULL;
    lcd_dev.write   = RT_NULL;
    lcd_dev.control = skt_lcd_control;

    lcd_dev.user_data = (void *)&lcd_info;

    ret = rt_device_register(&lcd_dev, "lcd", RT_DEVICE_FLAG_RDWR);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_lcd_init);

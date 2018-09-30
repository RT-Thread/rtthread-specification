/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtthread.h>
#include <rtdevice.h>

#include "drv_gpio.h"

static void hw_pin_mode(struct rt_device *device, rt_base_t pin, rt_base_t mode)
{
    return ;
}

static void hw_pin_write(struct rt_device *device, rt_base_t pin, rt_base_t value)
{
    return ;
}

static int hw_pin_read(struct rt_device *device, rt_base_t pin)
{
    return 0;
}

static rt_err_t hw_pin_attach_irq(struct rt_device *device, rt_int32_t pin,
       rt_uint32_t mode, void (*hdr)(void *args), void *args)
{
    return RT_EOK;
}

static rt_err_t hw_pin_detach_irq(struct rt_device *device, rt_int32_t pin)
{
    return RT_EOK;
}

static rt_err_t hw_pin_irq_enable(struct rt_device *device, rt_base_t pin, rt_uint32_t enabled)
{
    return RT_EOK;
}

struct rt_pin_ops _hw_pin_ops =
{
    hw_pin_mode,
    hw_pin_write,
    hw_pin_read,

    hw_pin_attach_irq,
    hw_pin_detach_irq,
    hw_pin_irq_enable
};

int hw_pin_init(void)
{
    rt_device_pin_register("gpio", &_hw_pin_ops , RT_NULL);

    return 0;
}
INIT_BOARD_EXPORT(hw_pin_init);

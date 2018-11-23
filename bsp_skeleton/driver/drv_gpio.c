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
    /* Todo:set pin mode */
}

static void hw_pin_write(struct rt_device *device, rt_base_t pin, rt_base_t value)
{
    /* Todo:set pin low or high */
}

static int hw_pin_read(struct rt_device *device, rt_base_t pin)
{
    /* Todo:get pin status and return status value */
    return 0;
}

static rt_err_t hw_pin_attach_irq(struct rt_device *device, rt_int32_t pin,
                                  rt_uint32_t mode, void (*hdr)(void *args), void *args)
{
    rt_err_t res = RT_EOK;

    /* Todo:attach hdr to pin ISR */

    return res;
}

static rt_err_t hw_pin_detach_irq(struct rt_device *device, rt_int32_t pin)
{
    rt_err_t res = RT_EOK;

    /* Todo:detach hdr from pin ISR */

    return res;
}

static rt_err_t hw_pin_irq_enable(struct rt_device *device, rt_base_t pin, rt_uint32_t enabled)
{
    rt_err_t res = RT_EOK;

    /* Todo:enable pin ISR */

    return res;
}

const static struct rt_pin_ops _hw_pin_ops =
{
    hw_pin_mode,
    hw_pin_write,
    hw_pin_read,

    hw_pin_attach_irq,
    hw_pin_detach_irq,
    hw_pin_irq_enable
};

int rt_hw_pin_init(void)
{
    rt_device_pin_register("pin", &_hw_pin_ops, RT_NULL);

    return 0;
}
INIT_BOARD_EXPORT(rt_hw_pin_init);

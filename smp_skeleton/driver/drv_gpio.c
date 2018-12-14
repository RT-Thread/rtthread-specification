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

static void skt_pin_mode(struct rt_device *device, rt_base_t pin, rt_base_t mode)
{
    /* Todo:set pin mode */
}

static void skt_pin_write(struct rt_device *device, rt_base_t pin, rt_base_t value)
{
    /* Todo:set pin low or high */
}

static int skt_pin_read(struct rt_device *device, rt_base_t pin)
{
    /* Todo:get pin status and return status value */
    return 0;
}

static rt_err_t skt_pin_attach_irq(struct rt_device *device, rt_int32_t pin,
                                   rt_uint32_t mode, void (*hdr)(void *args), void *args)
{
    rt_err_t ret = RT_EOK;

    /* Todo:attach hdr to pin ISR */

    return ret;
}

static rt_err_t skt_pin_detach_irq(struct rt_device *device, rt_int32_t pin)
{
    rt_err_t ret = RT_EOK;

    /* Todo:detach hdr from pin ISR */

    return ret;
}

static rt_err_t skt_pin_irq_enable(struct rt_device *device, rt_base_t pin, rt_uint32_t enabled)
{
    rt_err_t ret = RT_EOK;

    /* Todo:enable pin ISR */

    return ret;
}

const static struct rt_pin_ops skt_pin_ops =
{
    skt_pin_mode,
    skt_pin_write,
    skt_pin_read,

    skt_pin_attach_irq,
    skt_pin_detach_irq,
    skt_pin_irq_enable
};

int rt_hw_pin_init(void)
{
    rt_err_t ret = RT_EOK;

    ret = rt_device_pin_register("pin", &skt_pin_ops, RT_NULL);

    return ret;
}
INIT_BOARD_EXPORT(rt_hw_pin_init);

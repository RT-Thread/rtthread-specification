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
#include "drv_i2c.h"

#define SKT_I2C_DEVICE(i2c_bus)    (struct skt_i2c_bus *)(i2c_bus)

struct skt_i2c_bus
{
    struct rt_i2c_bus_device parent;
    rt_uint32_t i2c_periph;
};

static rt_size_t hw_i2c_xfer(struct rt_i2c_bus_device *bus, struct rt_i2c_msg msgs[], rt_uint32_t num)
{
    struct skt_i2c_bus *bus = SKT_I2C_DEVICE(bus);
    RT_ASSERT(i2c_bus != RT_NULL);

    /* Todo: transfer msgs[] via I2C hardware(bus->i2c_periph) */
}

const static struct rt_i2c_bus_device_ops _i2c_ops =
{
    hw_i2c_xfer,
    RT_NULL,
    RT_NULL
};

int rt_hw_i2c_init(void)
{
    static struct skt_i2c_bus i2c_bus0;

    i2c_bus0.parent.ops = &_i2c_ops;

    /* Todo: Init I2C Hardware */

    rt_i2c_bus_device_register(&i2c_bus0.parent, "i2c0");

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_i2c_init);

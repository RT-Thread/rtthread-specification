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

#include "skeleton_spi.h"

struct skt_spi_bus
{
    struct rt_spi_bus parent;
};

/* private rt-thread spi ops function */
static rt_err_t configure(struct rt_spi_device *device, struct rt_spi_configuration *configuration);
static rt_uint32_t xfer(struct rt_spi_device *device, struct rt_spi_message *message);

static struct rt_spi_ops _spi_ops =
{
    configure,
    xfer
};

static rt_err_t configure(struct rt_spi_device *device,
                          struct rt_spi_configuration *configuration)
{
    struct skt_spi_bus *bus = (struct skt_spi_bus *)device->bus;

    return RT_EOK;
}

static rt_uint32_t xfer(struct rt_spi_device *device, struct rt_spi_message *message)
{
    struct skt_spi_bus *bus = (struct skt_spi_bus *)device->bus;
    struct rt_spi_configuration *config = &device->config;
}

rt_err_t skt_spi_register(struct skt_spi_bus *spi_bus, const char *bus_name)
{
    return rt_spi_bus_register(&spi_bus->parent, bus_name, &_spi_ops);
}

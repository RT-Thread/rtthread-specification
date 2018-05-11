/*
 * File      : drv_spi.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2017, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
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

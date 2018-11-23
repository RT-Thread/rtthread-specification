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

#include "drv_spi.h"

#define SKT_SPI_DEVICE(spi_bus)    (struct skt_spi_bus *)(spi_bus)

struct skt_spi_bus
{
    struct rt_spi_bus parent;
    rt_uint32_t spi_periph;
};

static rt_err_t hw_spi_configure(struct rt_spi_device *device,
                                 struct rt_spi_configuration *configuration)
{
    rt_err_t res = RT_EOK;
    struct skt_spi_bus *bus = SKT_SPI_DEVICE(device->bus);

    /* Todo:according to (configuration) set (bus->spi_periph) data_width, prescale, mode. */

    /* Todo:enable SPI (bus->spi_periph) */

    return res;
}

static rt_uint32_t hw_spi_xfer(struct rt_spi_device *device, struct rt_spi_message *message)
{
    struct skt_spi_bus *bus = SKT_SPI_DEVICE(device->bus);
    struct rt_spi_configuration *cfg = &device->config;
    rt_base_t cs_pin = (rt_base_t)device->parent.user_data;

    /* Todo: transfer message via SPI Hardware(bus->spi_periph) */
    return 0;
}

const static struct rt_spi_ops _spi_ops =
{
    hw_spi_configure,
    hw_spi_xfer
};

int rt_hw_spi_init(void)
{
    static struct skt_spi_bus spi_bus0;

    /* Todo: Init SPI Hardware */

    rt_spi_bus_register(&spi_bus0.parent, "spi0", &_spi_ops);

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_spi_init);


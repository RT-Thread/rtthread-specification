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
    struct skt_spi_bus *bus = SKT_SPI_DEVICE(device->bus);

    /* TBD:according to (configuration) set (bus->spi_periph) data_width, prescale, mode. */

    /* TBD:enable SPI (bus->spi_periph) */

    return RT_EOK;
}

static rt_uint32_t hw_spi_xfer(struct rt_spi_device *device, struct rt_spi_message *message)
{
    struct skt_spi_bus *bus = SKT_SPI_DEVICE(device->bus);
    struct rt_spi_configuration *cfg = &device->config;
    rt_base_t cs_pin = (rt_base_t)device->parent.user_data;

    /* TBD: transfer message via SPI Hardware(bus->spi_periph) */
}

const static struct rt_spi_ops _spi_ops =
{
    hw_spi_configure,
    hw_spi_xfer
};

int rt_hw_spi_init(void)
{
    static struct skt_spi_bus spi_bus0;

    /* TBD: Init SPI Hardware */

    rt_spi_bus_register(&spi_bus0.parent, "spi0", &_spi_ops);

    /* TBD: register other SPI device */

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_spi_init);


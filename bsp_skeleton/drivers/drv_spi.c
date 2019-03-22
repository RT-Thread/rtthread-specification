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

#ifdef RT_USING_SPI

#define SKT_SPI_DEVICE(spi_bus)    (struct skt_spi_bus *)(spi_bus)

static struct skt_spi_bus spi_bus0;

struct skt_spi_bus
{
    struct rt_spi_bus parent;
    rt_uint32_t spi_periph;
};

static rt_err_t skt_spi_configure(struct rt_spi_device *device,
                                  struct rt_spi_configuration *configuration)
{
    rt_err_t ret = RT_EOK;
    struct skt_spi_bus *bus = SKT_SPI_DEVICE(device->bus);

    RT_ASSERT(bus != RT_NULL);

    /* Todo:according to (configuration) set (bus->spi_periph) data_width, prescale, mode. */

    /* Todo:enable SPI (bus->spi_periph) */

    return ret;
}

static rt_uint32_t skt_spi_xfer(struct rt_spi_device *device, struct rt_spi_message *message)
{
    struct skt_spi_bus *bus = SKT_SPI_DEVICE(device->bus);
    struct rt_spi_configuration *cfg = &device->config;
    rt_base_t cs_pin = (rt_base_t)device->parent.user_data;

    RT_ASSERT(bus != RT_NULL);

    (void)cs_pin;
    (void)cfg;
    /* Todo: transfer message via SPI Hardware(bus->spi_periph) */

    return 0;
}

const static struct rt_spi_ops skt_spi_ops =
{
    skt_spi_configure,
    skt_spi_xfer
};

int rt_hw_spi_init(void)
{
    rt_err_t ret = RT_EOK;

    /* Todo: Init SPI Hardware */

    ret = rt_spi_bus_register(&spi_bus0.parent, "spi0", &skt_spi_ops);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_spi_init);

#endif /* RT_USING_SPI */



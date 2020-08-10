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
#include "board.h"
#include "drv_dac.h"

#define SKT_DAC_DEVICE(dac_dev)    (struct skt_dac_dev *)(dac_dev)

struct skt_dac_dev
{
    struct rt_dac_device parent;
    rt_uint32_t dac_periph;
};

static rt_err_t skt_dac_enabled(struct rt_dac_device *device, rt_uint32_t channel)
{
    rt_err_t ret = RT_EOK;
    struct skt_dac_dev *dac = SKT_DAC_DEVICE(device);

    RT_ASSERT(dac != RT_NULL);

    /* Todo: enable dac->dac_periph */

    return ret;
}

static rt_err_t skt_dac_disabled(struct rt_dac_device *device, rt_uint32_t channel)
{
    rt_err_t ret = RT_EOK;
    struct skt_dac_dev *dac = SKT_DAC_DEVICE(device);

    RT_ASSERT(dac != RT_NULL);

    /* Todo: disable dac->dac_periph */

    return ret;
}

static rt_err_t skt_dac_convert(struct rt_dac_device *device, rt_uint32_t channel, rt_uint32_t *value)
{
    rt_err_t ret = RT_EOK;
    struct skt_dac_dev *dac = SKT_DAC_DEVICE(device);

    RT_ASSERT(dac != RT_NULL);

    /* Todo: convert dac->dac_periph */

    return ret;
}

const static struct rt_dac_ops skt_dac_ops =
{
    skt_dac_enabled,
    skt_dac_disabled,
    skt_dac_convert
};

int rt_hw_dac_init(void)
{
    rt_err_t ret = RT_EOK;
    static struct skt_dac_dev dac_dev0;

    /* Todo: Init dac Hardware */

    ret = rt_hw_dac_register(&dac_dev0.parent, "dac0", &skt_dac_ops, &dac_dev0);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_dac_init);

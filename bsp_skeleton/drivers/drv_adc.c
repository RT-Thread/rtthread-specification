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
#include "drv_adc.h"

#ifdef RT_USING_ADC

#define SKT_ADC_DEVICE(adc_dev)    (struct skt_adc_dev *)(adc_dev)

static struct skt_adc_dev adc_dev0;

struct skt_adc_dev
{
    struct rt_adc_device parent;
    rt_uint32_t adc_periph;
    rt_uint32_t channel;
};

static rt_err_t skt_adc_enabled(struct rt_adc_device *device, rt_uint32_t channel, rt_bool_t enabled)
{
    rt_err_t ret = RT_EOK;
    struct skt_adc_dev *adc = SKT_ADC_DEVICE(device);

    RT_ASSERT(adc != RT_NULL);

    if (enabled)
    {
        /* Todo: enable adc->adc_periph */
    }
    else
    {
        /* Todo: disable adc->adc_periph */
    }
    return ret;
}
static rt_err_t skt_adc_convert(struct rt_adc_device *device, rt_uint32_t channel, rt_uint32_t *value)
{
    rt_err_t ret = RT_EOK;
    struct skt_adc_dev *adc = SKT_ADC_DEVICE(device);

    RT_ASSERT(adc != RT_NULL);

    /* Todo: convert adc->adc_periph */

    return ret;
}

const static struct rt_adc_ops skt_adc_ops =
{
    skt_adc_enabled,
    skt_adc_convert
};

int rt_hw_adc_init(void)
{
    rt_err_t ret = RT_EOK;

    /* Todo: Init adc Hardware */

    ret = rt_hw_adc_register(&adc_dev0.parent, "adc0", &skt_adc_ops, &adc_dev0);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_adc_init);

#endif /* RT_USING_ADC */

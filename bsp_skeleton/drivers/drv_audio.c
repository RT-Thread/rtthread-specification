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
#include "drv_audio.h"

#ifdef BSP_USING_AUDIO

#define SKT_AUDIO_DEVICE(audio_dev)    (struct skt_audio_dev *)(audio_dev)

struct skt_audio_dev
{
    struct rt_audio_device audio;
    struct rt_audio_configure replay_config;
    rt_uint8_t *tx_fifo;
    rt_uint8_t volume;
};
static struct skt_audio_dev audio_dev0;

static rt_err_t skt_audio_getcaps(struct rt_audio_device *device, struct rt_audio_caps *caps)
{
    rt_err_t result = RT_EOK;
    struct skt_audio_device *audio = SKT_AUDIO_DEVICE(device);

    RT_ASSERT(audio != RT_NULL);

    switch (caps->main_type)
    {
        case AUDIO_TYPE_QUERY:
        {
            /* Todo: qurey audio types */
            break;
        }

        case AUDIO_TYPE_OUTPUT:
        {
            /* Todo: get audio functional attribute */
            break;
        }

        case AUDIO_TYPE_MIXER:
        {
            /* Todo : get audio mixer units */
            break;
        }

        default:
            break;
    }

    return result;
}

static rt_err_t skt_audio_configure(struct rt_audio_device *device, struct rt_audio_caps *caps)
{
    rt_err_t result = RT_EOK;
    struct skt_audio_device *audio = SKT_AUDIO_DEVICE(device);

    RT_ASSERT(audio != RT_NULL);

    switch (caps->main_type)
    {
        case AUDIO_TYPE_MIXER:
        {
            /* Todo : set audio mixer units */
            break;
        }

        case AUDIO_TYPE_OUTPUT:
        {
            /* Todo : set audio functional attribute */
            break;
        }

        default:
            break;
    }

    return result;
}

static rt_err_t skt_audio_start(struct rt_audio_device *device, int stream)
{
    rt_err_t result = RT_EOK;
    struct skt_audio_device *audio = SKT_AUDIO_DEVICE(device);

    RT_ASSERT(audio != RT_NULL);

    /* Todo : start audio */

    return result;
}

static rt_err_t skt_audio_stop(struct rt_audio_device *device, int stream)
{
    rt_err_t result = RT_EOK;
    struct skt_audio_device *audio = SKT_AUDIO_DEVICE(device);

    RT_ASSERT(audio != RT_NULL);

    /* Todo : stop audio */

    return result;
}

static rt_size_t skt_audio_transmit(struct rt_audio_device *device, const void *writeBuf, void *readBuf, rt_size_t size)
{
    rt_size_t tsize = 0;
    struct skt_audio_device *audio = SKT_AUDIO_DEVICE(device);

    RT_ASSERT(audio != RT_NULL);

    /* Todo : transmit audio data */

    return tsize;
}

static void skt_audio_buffer_info(struct rt_audio_device *device, struct rt_audio_buf_info *info)
{
    struct skt_audio_device *audio = SKT_AUDIO_DEVICE(device);

    RT_ASSERT(audio != RT_NULL);

    /* Todo : get audio buffer info */
}

static struct rt_audio_ops skt_audio_ops =
{
    skt_audio_getcaps,
    skt_audio_configure,
    skt_audio_start,
    skt_audio_stop,
    skt_audio_transmit,
    skt_audio_buffer_info
};

int rt_hw_audio_init(void)
{
    rt_err_t ret = RT_EOK;

    /* Todo: register audio device */
    audio_dev0.audio.ops = &skt_audio_ops;
    ret = rt_audio_register(&audio_dev0.audio, "audio0", RT_DEVICE_FLAG_RDWR, &audio_dev0);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_audio_init);

#endif /* BSP_USING_AUDIO */

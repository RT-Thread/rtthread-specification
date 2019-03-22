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
#include <netif/ethernetif.h>
#include <lwipopts.h>
#include "drv_emac.h"

#ifdef RT_USING_LWIP

#define MAX_ADDR_LEN            6
#define SKT_EMAC_DEVICE(eth)    (struct skt_emac_dev*)(eth)

static struct skt_emac_dev emac_dev;

struct skt_emac_dev
{
    struct eth_device parent;

    rt_uint8_t dev_addr[MAX_ADDR_LEN];    /* MAC address  */
};

static rt_err_t skt_emac_init(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;
    struct skt_emac_dev *emac = SKT_EMAC_DEVICE(dev);

    RT_ASSERT(emac != RT_NULL);

    /* Todo:init emac */
    return ret;
}

static rt_err_t skt_emac_open(rt_device_t dev, rt_uint16_t oflag)
{
    rt_err_t ret = RT_EOK;
    struct skt_emac_dev *emac = SKT_EMAC_DEVICE(dev);

    RT_ASSERT(emac != RT_NULL);

    /* Todo:enable emac */
    return ret;
}

static rt_err_t skt_emac_close(rt_device_t dev)
{
    rt_err_t ret = RT_EOK;
    struct skt_emac_dev *emac = SKT_EMAC_DEVICE(dev);

    RT_ASSERT(emac != RT_NULL);

    /* Todo:close emac */
    return ret;
}

static rt_err_t skt_emac_control(rt_device_t dev, int cmd, void *args)
{
    rt_err_t ret = RT_EOK;
    struct skt_emac_dev *emac = SKT_EMAC_DEVICE(dev);

    RT_ASSERT(emac != RT_NULL);

    switch (cmd)
    {
    case NIOCTL_GADDR:
        /* get MAC address */
        if (args)
        {
            rt_memcpy(args, emac->dev_addr, 6);
        }
        else
        {
            ret = -RT_ERROR;
        }
        break;

    default :
        break;
    }

    return ret;
}

/* Ethernet device interface */
/* transmit packet */
static rt_err_t skt_emac_tx(rt_device_t dev, struct pbuf *p)
{
    rt_err_t ret = RT_EOK;
    struct skt_emac_dev *emac = SKT_EMAC_DEVICE(dev);

    RT_ASSERT(emac != RT_NULL);

    /* copy pbuf to a whole ETH frame */
    /* pbuf_copy_partial(p, eth_frame, p->tot_len, 0); */

    /* send it out */

    return ret;
}

/* reception packet */
static struct pbuf *skt_emac_rx(rt_device_t dev)
{
    struct pbuf *p = RT_NULL;
    struct skt_emac_dev *emac = SKT_EMAC_DEVICE(dev);

    RT_ASSERT(emac != RT_NULL);

    /* take the emac buffer to the pbuf */
    {
        int length = 0;

        /* get frame length */

        /* allocate pbuf */
        p = pbuf_alloc(PBUF_LINK, length, PBUF_RAM);
        if (p)
        {
            /* pbuf_take(p, buffer, length); */
        }
    }

    return p;
}

#ifdef RT_USING_DEVICE_OPS
const static struct rt_device_ops skt_emac_ops =
{
    skt_emac_init,
    skt_emac_open,
    skt_emac_close,
    RT_NULL,
    RT_NULL,
    skt_emac_control
};
#endif

int rt_hw_emac_init(void)
{
    rt_err_t ret = RT_EOK;
    /* test MAC address */
    emac_dev.dev_addr[0] = 0x00;
    emac_dev.dev_addr[1] = 0x11;
    emac_dev.dev_addr[2] = 0x22;
    emac_dev.dev_addr[3] = 0x33;
    emac_dev.dev_addr[4] = 0x44;
    emac_dev.dev_addr[5] = 0x55;

#ifdef RT_USING_DEVICE_OPS
    emac_dev.parent.parent.ops        = &skt_emac_ops;
#else
    emac_dev.parent.parent.init       = skt_emac_init;
    emac_dev.parent.parent.open       = skt_emac_open;
    emac_dev.parent.parent.close      = skt_emac_close;
    emac_dev.parent.parent.read       = RT_NULL;
    emac_dev.parent.parent.write      = RT_NULL;
    emac_dev.parent.parent.control    = skt_emac_control;
#endif

    emac_dev.parent.parent.user_data  = RT_NULL;
    emac_dev.parent.eth_rx     = skt_emac_rx;
    emac_dev.parent.eth_tx     = skt_emac_tx;

    /* register ETH device */
    ret = eth_device_init(&(emac_dev.parent), "e0");

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_emac_init);

#endif /* RT_USING_LWIP */

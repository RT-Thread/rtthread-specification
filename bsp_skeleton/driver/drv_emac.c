/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtthread.h>

#ifdef RT_USING_LWIP
#include <netif/ethernetif.h>

#include <lwipopts.h>
#include "drv_emac.h"

#define MAX_ADDR_LEN            6
#define SKT_EMAC_DEVICE(eth)    (struct skt_emac*)(eth)

struct skt_emac
{
    /* inherit from Ethernet device */
    struct eth_device parent;

    /* interface address info. */
    rt_uint8_t  dev_addr[MAX_ADDR_LEN];         /* MAC address  */
};
static struct skt_emac _emac;

static rt_err_t skt_emac_init(rt_device_t dev)
{
    return RT_EOK;
}

static rt_err_t skt_emac_open(rt_device_t dev, rt_uint16_t oflag)
{
    return RT_EOK;
}

static rt_err_t skt_emac_close(rt_device_t dev)
{
    return RT_EOK;
}

static rt_size_t skt_emac_read(rt_device_t dev, rt_off_t pos, void *buffer, rt_size_t size)
{
    rt_set_errno(-RT_ENOSYS);
    return 0;
}

static rt_size_t skt_emac_write(rt_device_t dev, rt_off_t pos, const void *buffer, rt_size_t size)
{
    rt_set_errno(-RT_ENOSYS);
    return 0;
}

static rt_err_t skt_emac_control(rt_device_t dev, int cmd, void *args)
{
    struct skt_emac *emac;

    emac = SKT_EMAC_DEVICE(dev);
    RT_ASSERT(emac != RT_NULL);

    switch (cmd)
    {
    case NIOCTL_GADDR:
        /* get MAC address */
        if (args) rt_memcpy(args, emac->dev_addr, 6);
        else return -RT_ERROR;
        break;

    default :
        break;
    }

    return RT_EOK;
}

/* Ethernet device interface */
/* transmit packet. */
rt_err_t skt_emac_tx(rt_device_t dev, struct pbuf *p)
{
    rt_err_t result = RT_EOK;
    struct skt_emac *emac;

    emac = SKT_EMAC_DEVICE(dev);
    RT_ASSERT(emac != RT_NULL);

    /* copy pbuf to a whole ETH frame */
    // pbuf_copy_partial(p, eth_frame, p->tot_len, 0);

    /* send it out */

    return result;
}

/* reception packet. */
struct pbuf *skt_emac_rx(rt_device_t dev)
{
    struct pbuf *p = RT_NULL;
    struct skt_emac *emac;

    emac = SKT_EMAC_DEVICE(dev);
    RT_ASSERT(emac != RT_NULL);

    /* take the emac buffer to the pbuf */
    {
        int length;

        /* get frame length */

        /* allocate pbuf */
        p = pbuf_alloc(PBUF_LINK, length, PBUF_RAM);
        if (p)
        {
            // pbuf_take(p, buffer, length);
        }
    }

    return p;
}

int skt_emac_hw_init(void)
{
    /* test MAC address */
    _emac.dev_addr[0] = 0x00;
    _emac.dev_addr[1] = 0x11;
    _emac.dev_addr[2] = 0x22;
    _emac.dev_addr[3] = 0x33;
    _emac.dev_addr[4] = 0x44;
    _emac.dev_addr[5] = 0x55;

    _emac.parent.parent.init       = skt_emac_init;
    _emac.parent.parent.open       = skt_emac_open;
    _emac.parent.parent.close      = skt_emac_close;
    _emac.parent.parent.read       = skt_emac_read;
    _emac.parent.parent.write      = skt_emac_write;
    _emac.parent.parent.control    = skt_emac_control;
    _emac.parent.parent.user_data  = RT_NULL;

    _emac.parent.eth_rx     = skt_emac_rx;
    _emac.parent.eth_tx     = skt_emac_tx;

    /* register ETH device */
    eth_device_init(&(_emac.parent), "e0");

    return 0;
}
INIT_DEVICE_EXPORT(skt_emac_hw_init);
#endif


/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rtdevice.h>

#if defined(RT_USING_LWIP) && defined(RT_USING_WIFI)

#include <wlan_dev.h>

#include <netif/ethernetif.h>
#include <netif/etharp.h>

#if LWIP_IGMP
#include <lwip/igmp.h>

#define MULTICAST_IP_TO_MAC(ip)       { (uint8_t) 0x01,             \
                                        (uint8_t) 0x00,             \
                                        (uint8_t) 0x5e,             \
                                        (uint8_t) ((ip)[1] & 0x7F), \
                                        (uint8_t) (ip)[2],          \
                                        (uint8_t) (ip)[3]           \
                                      }
#endif

#define NIOCTL_SADDR 0x02

enum wlan_hw_status
{
    WLAN_STATUS_UNINITED = 0,
    WLAN_STATUS_INITED,
    WLAN_STATUS_CONNECTED,
    WLAN_STATUS_AP_MODE,
};

enum wlan_interface
{
    WLAN_IF_STATION,
    WLAN_IF_AP,
};

struct wlan_hw_device
{
    /* inherit from wlan device */
    struct rt_wlan_device parent;

    int interface;
    enum wlan_hw_status status;
};
struct wlan_hw_device _wifi_device;

#if LWIP_IGMP
/**
 * Interface between lwIP IGMP MAC filter and WLAN filter
 */
static err_t wlan_igmp_mac_filter(struct netif *netif, ip_addr_t *group, u8_t action)
{
    uint32_t mac = { MULTICAST_IP_TO_MAC((uint8_t *)group) };

    switch (action)
    {
    case IGMP_ADD_MAC_FILTER:
        /* register multicast address */
        break;

    case IGMP_DEL_MAC_FILTER:
        /* unregister multicast address */
        break;

    default:
        return ERR_VAL;
    }

    return ERR_OK;
}
#endif

static int wlan_hw_init(struct wlan_hw_device *device)
{
    rt_err_t result = -RT_EIO;

    if (device->status == WLAN_STATUS_UNINITED)
    {
        /* to initialize wlan driver */
        if (0)
        {
            rt_kprintf("wifi initialization failed: %d\n", result);
            result = -RT_EIO;
        }
        else
        {
            device->status = WLAN_STATUS_INITED;
            result = RT_EOK;
        }
    }

    return result;
}

static int wlan_hw_scan(struct wlan_hw_device *device, struct rt_wlan_info *info,
                        int number)
{
    rt_err_t result = RT_EOK;

    return result;
}

static int wlan_hw_ready(struct wlan_hw_device *device)
{
    struct eth_device *eth;

    eth = &(device->parent.parent);
    RT_ASSERT(eth);

    /* update MAC address */
    // rt_memcpy(eth->netif->hwaddr, mac_addr, 6);

    return 0;
}

static int wlan_hw_join(struct wlan_hw_device *device, const char *password)
{
    rt_err_t result;

    char *ssid_str;

    ssid_str = device->parent.info->ssid;

    /* join wlan */

    if (0)
    {
        result = -RT_ERROR;
    }
    else
    {
        device->status = WLAN_STATUS_CONNECTED;

        wlan_hw_ready(device);
        result = RT_EOK;
    }

    return result;
}

static int wlan_hw_easy_join(struct wlan_hw_device *device, const char *password)
{
    char *ssid_str;
    rt_err_t result = RT_EOK;

    ssid_str = device->parent.info->ssid;

    /* scan this SSID */

    /* join */

    return result;
}

static rt_err_t wlan_hw_control(rt_device_t dev, int cmd, void *args)
{
    rt_err_t result = RT_EOK;
    struct wlan_hw_device *device = (struct wlan_hw_device *) dev;

    switch (cmd)
    {
    case NIOCTL_GADDR: /* get MAC address */
    {
        if (args == RT_NULL) return -RT_ERROR;

        if (device->status != WLAN_STATUS_UNINITED)
        {
            /* get MAC address */
        }
        else
        {
            rt_memset(args, 0x0, 6);
        }
        break;
    }
    case NIOCTL_SADDR: /* set MAC address */
    {
        if (args == RT_NULL) return -RT_ERROR;

        if (device->status != WLAN_STATUS_UNINITED)
        {
            /* set MAC address */
        }
        break;
    }

    case WIFI_INIT:
    {
        rt_wlan_mode_t mode = *(rt_wlan_mode_t *)args;

        if (device->status == WLAN_STATUS_UNINITED)
        {
            if (mode == WIFI_STATION)
            {
                device->interface = WLAN_IF_STATION;
            }
            else if (mode == WIFI_AP)
            {
                device->interface = WLAN_IF_AP;
            }

            result = wlan_hw_init(device);
            if (result == RT_EOK)
            {
#if LWIP_IGMP
                netif_set_igmp_mac_filter(device->parent.parent.netif, wlan_igmp_mac_filter);
#endif

                device->status = WLAN_STATUS_INITED;
            }
        }
    }
    break;

    case WIFI_SCAN:
    {
        struct rt_wlan_info_request *request;
        request = (struct rt_wlan_info_request *) args;

        if (device->status == WLAN_STATUS_UNINITED)
        {
            result = wlan_hw_init(device);
            if (result != RT_EOK) break;
        }

        if (device->status != WLAN_STATUS_UNINITED)
        {
            int result_num;

            /* scan wifi and get AP list */
            result_num = wlan_hw_scan(device, request->infos, request->req_number);
            if (result_num >= 0)
            {
                request->rsp_number = result_num;
                result = RT_EOK;
            }
            else result = -RT_ERROR;
        }
    }
    break;

    case WIFI_JOIN:
    {
        if (device->status == WLAN_STATUS_UNINITED)
        {
            result = wlan_hw_init(device);
            if (result != RT_EOK) break;
        }

        if (device->status != WLAN_STATUS_UNINITED)
        {
            device->interface = WLAN_IF_STATION;
            result = wlan_hw_join(device, (char *)args);
            if (result == RT_EOK)
            {
                /* TODO: set event handler */
            }
        }
    }
    break;

    case WIFI_EASYJOIN:
    {
        char *password = (char *)args;

        if (device->status == WLAN_STATUS_UNINITED)
        {
            result = wlan_hw_init(device);
            if (result != RT_EOK) break;
        }

        if (device->status != WLAN_STATUS_UNINITED)
        {
            device->interface = WLAN_IF_STATION;

            result = wlan_hw_easy_join(device, password);
            if (result == RT_EOK)
            {
                /* TODO: set event handler */
            }
        }
    }
    break;

    case WIFI_SOFTAP:
    {
        if (device->status == WLAN_STATUS_UNINITED)
        {
            result = wlan_hw_init(device);
            if (result != RT_EOK) break;
        }

        if (device->status != WLAN_STATUS_UNINITED)
        {
            uint8_t channel;
            char    *ssid_str;
            char    *password = (char *)args;

            /* set to soft-AP */
            device->interface = WLAN_IF_AP;

            /* initialize SSID */
            ssid_str = device->parent.info->ssid;
            /* get channel */
            channel = device->parent.info->channel;

            /* startup AP mode */

            /* check result */
            if (1)
            {
                wlan_hw_ready(device);
            }
        }
    }
    break;

    case WIFI_DISCONNECT:
    {
        if (device->interface == WLAN_IF_AP)
        {
            /* stop soft-AP */
        }
        else if (device->interface == WLAN_IF_STATION)
        {
            /* leave wlan network */
        }
        else
        {
            /* bad interface */
            RT_ASSERT(0);
        }

        /* check result */
        if (1)
        {
            /* initialized but not connected. */
            device->status = WLAN_STATUS_INITED;
            result = RT_EOK;
        }
    }
    break;

    case WIFI_GET_RSSI:
    {
        int32_t rssi = 0;

        if (device->status != WLAN_STATUS_CONNECTED || device->status != WLAN_STATUS_AP_MODE)
        {
            result = -RT_EIO;
            break;
        }

        /* get RSSI */

        /* check result */
        if (1)
        {
            result = RT_EOK;
            *((int *)args) = rssi;
        }
    }
    break;

    case WIFI_ENTER_POWERSAVE:
    {
        int pm_mode = *(int *)args;

        if (pm_mode == WIFI_PWR_SLEEP)
        {
            /* sleep */
        }
        else
        {
            /*not sleep */
        }

        /* check result */
        if (0) result = -RT_EIO;
    }
    break;

    default :
        break;
    }

    return result;
}

/* transmit packet. */
static rt_err_t wlan_hw_tx(rt_device_t dev, struct pbuf *p)
{
    struct wlan_hw_device *device;

    device = (struct wlan_hw_device *) dev;

    /* not ready */
    if (0)
    {
        return -RT_ERROR;
    }

    /* tx package */
    device = device;

    return RT_EOK;
}

static struct pbuf *wlan_hw_rx(rt_device_t dev)
{
    struct pbuf *p = RT_NULL;

    /* not always need to implement this interface */
    return p;
}

int rt_hw_wlan_init(void)
{
    struct rt_device *dev;
    struct eth_device *eth;

    rt_uint16_t flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP;

    _wifi_device.interface   = WLAN_IF_STATION;
    _wifi_device.status      = WLAN_STATUS_UNINITED;
    _wifi_device.parent.info = RT_NULL;

    eth = &(_wifi_device.parent.parent);
    dev = &(eth->parent);

    eth->eth_tx  = wlan_hw_tx;
    eth->eth_rx  = wlan_hw_rx;

    dev->init    = RT_NULL;
    dev->close   = RT_NULL;
    dev->read    = RT_NULL;
    dev->write   = RT_NULL;
    dev->control = wlan_hw_control;

#if LWIP_IGMP
    /* IGMP support */
    flags |= NETIF_FLAG_IGMP;
#endif

    /* register eth device */
    eth_device_init_with_flag(eth, "w0", ETHIF_LINK_PHYUP | flags);

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_wlan_init);

#endif

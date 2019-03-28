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

#ifdef RT_USING_WIFI

#define WIFI_STA_INTERFACE  (0x00)
#define WIFI_AP_INTERFACE   (0x01)

#define WIFI_EVENT_LINK_UP      (0x00)
#define WIFI_EVENT_DISASSOC_IND (0x01)

#define WIFI_EVENT_ASSOC_IND    (0x02)
#define WIFI_EVENT_REASSOC_IND  (0x03)
#define WIFI_EVENT_DEAUTH_IND   (0x04)
#define WIFI_EVENT_DEAUTH       (0x05)
#define WIFI_EVENT_DISASSOC     (0x06)

enum wifi_status
{
    WIFI_UNINITED = 0,
    WIFI_INITED,
    WIFI_CONNECTED,
    WIFI_AP_MODE,
};

struct wifi
{
    struct rt_wlan_device *wlan;
    rt_uint32_t interface;
    enum wifi_status status;
};

static struct wifi wifi_sta;
static struct wifi wifi_ap;

rt_inline struct wifi *wifi_get_dev(rt_uint32_t wwd_if)
{
    if (wwd_if == WIFI_STA_INTERFACE)
    {
        return &wifi_sta;
    }
    if (wwd_if == WIFI_AP_INTERFACE)
    {
        return &wifi_ap;
    }
    return RT_NULL;
}

rt_inline struct wifi *wifi_get_dev_by_wlan(struct rt_wlan_device *wlan)
{
    if (wlan == wifi_sta.wlan)
    {
        return &wifi_sta;
    }
    if (wlan == wifi_ap.wlan)
    {
        return &wifi_ap;
    }
    return RT_NULL;
}

void scan_results_handler(void)
{
    struct rt_wlan_buff ind_buffer;
    struct rt_wlan_info wlan_info;

    INVALID_INFO(&wlan_info);

#if 0
    /* BSSID */
    memcpy(&wlan_info.bssid[0], &record->BSSID.octet[0], RT_WLAN_BSSID_MAX_LENGTH);
    /* SSID value */
    strncpy((char *)&wlan_info.ssid.val[0], (char *)&record->SSID.value[0], record->SSID.length);
    /* SSID length */
    wlan_info.ssid.len = record->SSID.length;
    /* security */
    wlan_info.security = record->security;
    /* channel */
    wlan_info.channel = record->channel;
    /* RATE */
    wlan_info.datarate = record->max_data_rate * 1000;
    /* RSSI */
    wlan_info.rssi = record->signal_strength;
#endif

    ind_buffer.len = sizeof(struct rt_wlan_info);
    ind_buffer.data = &wlan_info;

    rt_wlan_dev_indicate_event_handle(wifi_sta.wlan, RT_WLAN_DEV_EVT_SCAN_REPORT, &ind_buffer);

    return ;
}

void join_events_handler(rt_uint32_t event_type)
{

    switch (event_type)
    {
    case WIFI_EVENT_LINK_UP:
    {
        /* report connect event */
        rt_wlan_dev_indicate_event_handle(wifi_sta.wlan, RT_WLAN_DEV_EVT_CONNECT, RT_NULL);
        break;
    }
    case WIFI_EVENT_DISASSOC_IND:
    {
        rt_wlan_dev_indicate_event_handle(wifi_sta.wlan, RT_WLAN_DEV_EVT_DISCONNECT, RT_NULL);
        break;
    }
    default :
    {
        break;
    }
    }
}

void softap_event_handler(rt_uint32_t event_type)
{
    struct rt_wlan_info info;
    struct rt_wlan_buff buff;

    switch (event_type)
    {
    case WIFI_EVENT_ASSOC_IND:
    case WIFI_EVENT_REASSOC_IND:
    {
        INVALID_INFO(&info);
#if 0
        /* copy sta mac addr */
        memcpy(info.bssid, event_header->addr.octet, 6);
#endif
        buff.data = &info;
        buff.len = sizeof(info);
        rt_wlan_dev_indicate_event_handle(wifi_ap.wlan, RT_WLAN_DEV_EVT_AP_ASSOCIATED, &buff);
        break;
    }
    case WIFI_EVENT_DEAUTH_IND:
    case WIFI_EVENT_DISASSOC_IND:
    case WIFI_EVENT_DEAUTH:
    case WIFI_EVENT_DISASSOC:
    {
        INVALID_INFO(&info);
#if 0
        /* copy sta mac addr */
        memcpy(info.bssid, event_header->addr.octet, 6);
#endif
        buff.data = &info;
        buff.len = sizeof(info);
        rt_wlan_dev_indicate_event_handle(wifi_ap.wlan, RT_WLAN_DEV_EVT_AP_DISASSOCIATED, &buff);
        break;
    }
    default:
    {
        break;
    }
    }
}

static rt_err_t wlan_init(struct rt_wlan_device *wlan)
{
    rt_err_t ret = -RT_EIO;
    struct wifi *wifi;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->status != WIFI_UNINITED)
    {
        /* this wlan already inited */
        ret = RT_EOK;
    }

    /* Todo:wifi init */

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_mode(struct rt_wlan_device *wlan, rt_wlan_mode_t mode)
{
    struct wifi *wifi;
    rt_err_t ret = RT_EOK;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (mode == RT_WLAN_STATION)
    {
        /* set wifi station mode */
        wifi->interface = WIFI_STA_INTERFACE;
    }
    else if (mode == RT_WLAN_AP)
    {
        /* set wifi ap mode */
        wifi->interface = WIFI_AP_INTERFACE;
    }

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_scan(struct rt_wlan_device *wlan, struct rt_scan_info *scan_info)
{
    struct wifi *wifi;
    rt_err_t ret = RT_EOK;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_STA_INTERFACE)
    {
        /* this wlan not support scan mode */
        return -RT_ERROR;
    }

    /* Todo: wifi scan operation */

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_join(struct rt_wlan_device *wlan, struct rt_sta_info *sta_info)
{
    rt_err_t ret;
    struct wifi *wifi;

    if ((wlan == RT_NULL) || (sta_info == RT_NULL))
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_STA_INTERFACE)
    {
        /* this wlan not support scan mode */
        return -RT_ERROR;
    }

    /* Todo: wifi join operation */

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_softap(struct rt_wlan_device *wlan, struct rt_ap_info *ap_info)
{
    rt_err_t ret = RT_EOK;
    struct wifi *wifi;

    if ((wlan == RT_NULL) || (ap_info == RT_NULL))
    {
        /* parameter error */
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_AP_INTERFACE)
    {
        /* this wlan not support ap mode */
        return -RT_ERROR;
    }

    /* Todo: start ap operation */

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_disconnect(struct rt_wlan_device *wlan)
{
    rt_err_t ret;
    struct wifi *wifi;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_STA_INTERFACE)
    {
        /* this wlan not support sta mode */
        return -RT_ERROR;
    }

    /* Todo: wifi disconnect operation */

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_ap_stop(struct rt_wlan_device *wlan)
{
    struct wifi *wifi;
    rt_err_t ret;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_AP_INTERFACE)
    {
        /* this wlan not support ap mode */
        return -RT_ERROR;
    }

    /* Todo: stop soft-AP operation */

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static rt_err_t wlan_ap_deauth(struct rt_wlan_device *wlan, rt_uint8_t mac[])
{
    struct wifi *wifi;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_AP_INTERFACE)
    {
        return -RT_ERROR;
    }

    /* Todo: death sta operation */

    return RT_EOK;
}

static rt_err_t wlan_scan_stop(struct rt_wlan_device *wlan)
{
    struct wifi *wifi;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    /* Todo: wifi scan abort operation */

    return RT_EOK;
}

static int wlan_get_rssi(struct rt_wlan_device *wlan)
{
    int32_t rssi = 0;
    struct wifi *wifi;

    if (wlan == RT_NULL)
    {
        return -RT_ERROR;
    }

    wifi = wifi_get_dev_by_wlan(wlan);
    if (wifi == RT_NULL)
    {
        return -RT_ERROR;
    }

    if (wifi->interface != WIFI_STA_INTERFACE)
    {
        return -RT_ERROR;
    }

    /* get rssi */
    rssi = rssi;

    return rssi;
}

static rt_err_t wlan_set_powersave(struct rt_wlan_device *wlan, int level)
{
    rt_err_t ret;

    if (level)
    {
        /* enable  power save */
    }
    else
    {
        /* disable power save */
    }

    /* check result */
    if (1)
    {
        ret = RT_EOK;
    }

    return ret;
}

static int wlan_get_powersave(struct rt_wlan_device *wlan)
{
    int level = 0;

    /* get power save level */
    level = level;

    return level;
}

static rt_err_t wlan_cfg_promisc(struct rt_wlan_device *wlan, rt_bool_t start)
{
    if (start == RT_TRUE)
    {
        /* enable promisc */
    }
    else
    {
        /* disable promisc */
    }

    return RT_EOK;
}

static rt_err_t wlan_cfg_filter(struct rt_wlan_device *wlan, struct rt_wlan_filter *filter)
{
    if (filter == RT_NULL)
    {
        return -RT_ERROR;
    }

    /* config filter */

    return RT_EOK;
}

static rt_err_t wlan_set_channel(struct rt_wlan_device *wlan, int channel)
{
    if (channel < 0)
    {
        return -RT_ERROR;
    }

    /* set channel */

    return RT_EOK;
}

static int wlan_get_channel(struct rt_wlan_device *wlan)
{
    int channel = -1;

    /* get channel */
    channel = channel;

    return channel;
}

static rt_err_t wlan_set_country(struct rt_wlan_device *wlan, rt_country_code_t country_code)
{
    if (country_code == RT_COUNTRY_UNKNOWN)
    {
        return -RT_ERROR;
    }

    /* set country code */

    return RT_EOK;
}

static rt_country_code_t wlan_get_country(struct rt_wlan_device *wlan)
{
    rt_country_code_t country_code = RT_COUNTRY_UNKNOWN;

    /* get country code */
    country_code = country_code;

    return country_code;
}

static rt_err_t wlan_set_mac(struct rt_wlan_device *wlan, rt_uint8_t mac[])
{
    if (mac == RT_NULL)
    {
        return -RT_ERROR;
    }

    /* set MAC address */

    return RT_EOK;
}

static rt_err_t wlan_get_mac(struct rt_wlan_device *wlan, rt_uint8_t mac[])
{
    if (mac == RT_NULL)
    {
        return -RT_ERROR;
    }

    /* get MAC address */

    return RT_EOK;
}

static int wlan_recv(struct rt_wlan_device *wlan, void *buff, int len)
{
    /* not always need to implement this interface */

    return RT_EOK;
}

static int wlan_send(struct rt_wlan_device *wlan, void *buff, int len)
{
    /* not ready */
    if (0)
    {
        return -RT_ERROR;
    }

    /* tx package */

    return RT_EOK;
}

const static struct rt_wlan_dev_ops ops =
{
    .wlan_init          = wlan_init,
    .wlan_mode          = wlan_mode,
    .wlan_scan          = wlan_scan,
    .wlan_join          = wlan_join,
    .wlan_softap        = wlan_softap,
    .wlan_disconnect    = wlan_disconnect,
    .wlan_ap_stop       = wlan_ap_stop,
    .wlan_ap_deauth     = wlan_ap_deauth,
    .wlan_scan_stop     = wlan_scan_stop,
    .wlan_get_rssi      = wlan_get_rssi,
    .wlan_set_powersave = wlan_set_powersave,
    .wlan_get_powersave = wlan_get_powersave,
    .wlan_cfg_promisc   = wlan_cfg_promisc,
    .wlan_cfg_filter    = wlan_cfg_filter,
    .wlan_set_channel   = wlan_set_channel,
    .wlan_get_channel   = wlan_get_channel,
    .wlan_set_country   = wlan_set_country,
    .wlan_get_country   = wlan_get_country,
    .wlan_set_mac       = wlan_set_mac,
    .wlan_get_mac       = wlan_get_mac,
    .wlan_recv          = wlan_recv,
    .wlan_send          = wlan_send,
};

static struct rt_wlan_device wlan_sta;
static struct rt_wlan_device wlan_ap;

int rt_hw_wlan_init(void)
{
    rt_err_t ret = RT_EOK;

    wifi_sta.wlan = &wlan_sta;
    wifi_ap.wlan = &wlan_ap;

    ret = rt_wlan_dev_register(&wlan_sta, RT_WLAN_DEVICE_STA_NAME, &ops, 0, &wifi_sta);
    if (ret != RT_EOK)
    {
        return ret;
    }
    ret = rt_wlan_dev_register(&wlan_ap, RT_WLAN_DEVICE_AP_NAME, &ops, 0, &wifi_ap);
    if (ret != RT_EOK)
    {
        return ret;
    }

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_wlan_init);

#endif /* RT_USING_WIFI */


/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "drv_hwtimer.h"

#ifdef RT_USING_HWTIMER

#define SKT_HWTIMER_DEVICE(hwtimer)    (struct skt_hwtimer_dev *)(hwtimer)

static struct skt_hwtimer_dev hwtimer0;

struct skt_hwtimer_dev
{
    rt_hwtimer_t parent;
    rt_uint32_t hwtimer_periph;
    rt_uint32_t irqno;
};

void skt_hwtimer_isr(int irqno, void *param)
{
    struct skt_hwtimer_dev *hwtimer = SKT_HWTIMER_DEVICE(param);

    RT_ASSERT(hwtimer != RT_NULL);

    rt_device_hwtimer_isr(&hwtimer->parent);
}

static rt_err_t skt_hwtimer_control(rt_hwtimer_t *timer, rt_uint32_t cmd, void *args)
{
    rt_err_t ret = RT_EOK;
    struct skt_hwtimer_dev *hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    switch (cmd)
    {
    case HWTIMER_CTRL_FREQ_SET:

        /* Todo:set the count frequency */
        break;

    case HWTIMER_CTRL_STOP:

        /* Todo:stop timer */
        break;

    case HWTIMER_CTRL_INFO_GET:

        /* Todo:get a timer feature information */
        break;

    case HWTIMER_CTRL_MODE_SET:

        /* Todo:Set the timing mode(oneshot/period) */
        break;
    default:

        break;
    }
    return ret;
}

static rt_uint32_t skt_hwtimer_count_get(rt_hwtimer_t *timer)
{
    struct skt_hwtimer_dev *hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* Todo: get hwtimer(hwtimer->hwtimer_periph) counter value*/
    return 0;
}

static void skt_hwtimer_init(rt_hwtimer_t *timer, rt_uint32_t state)
{
    struct skt_hwtimer_dev *hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* Todo:init hwtimer(hwtimer->hwtimer_periph)*/
}

static rt_err_t skt_hwtimer_start(rt_hwtimer_t *timer, rt_uint32_t cnt, rt_hwtimer_mode_t mode)
{
    rt_err_t ret = RT_EOK;
    struct skt_hwtimer_dev *hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* Todo:start hwtimer(hwtimer->hwtimer_periph)*/

    /* install interrupt */
    /*
    rt_hw_interrupt_install(hwtimer->irqno, skt_hwtimer_isr,
                            hwtimer, hwtimer->parent.parent.parent.name);
    */
    /* Enable Interrupt */
    /* rt_hw_interrupt_umask(hwtimer->irqno);*/

    return ret;
}

static void skt_hwtimer_stop(rt_hwtimer_t *timer)
{
    struct skt_hwtimer_dev *hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* Todo:stop hwtimer(hwtimer->hwtimer_periph)*/
}

const static struct rt_hwtimer_ops hwtimer_ops =
{
    skt_hwtimer_init,
    skt_hwtimer_start,
    skt_hwtimer_stop,
    skt_hwtimer_count_get,
    skt_hwtimer_control
};

const static struct rt_hwtimer_info hwtimer_info =
{
    25000000,               /* the maximum count frequency can be set */
    6103,                   /* the minimum count frequency can be set */
    0xFFFFFFFF,             /* counter maximum value */
    HWTIMER_CNTMODE_UP,     /* count mode (inc/dec) */
};

int rt_hw_hwtimer_init(void)
{
    rt_err_t ret = RT_EOK;
    hwtimer0.parent.info = &hwtimer_info;
    hwtimer0.parent.ops  = &hwtimer_ops;

    ret = rt_device_hwtimer_register(&hwtimer0.parent, "timer0", &hwtimer0);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_hwtimer_init);

#endif /* RT_USING_HWTIMER */

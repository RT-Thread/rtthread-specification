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
#include "drv_hwtimer.h"

#define SKT_HWTIMER_DEVICE(hwtimer)    (struct skt_hwtimer *)(hwtimer)

struct skt_hwtimer
{
    rt_hwtimer_t parent;
    rt_uint32_t hwtimer_periph;
    rt_uint32_t irqno;
};

static rt_err_t skt_hwtimer_control(rt_hwtimer_t *timer, rt_uint32_t cmd, void *args)
{
    rt_err_t res = RT_EOK;
    struct skt_hwtimer *hwtimer;
    hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    switch (cmd)
    {
    case HWTIMER_CTRL_FREQ_SET:

        /* TBD:set the count frequency */
        break;

    case HWTIMER_CTRL_STOP:

        /* TBD:stop timer */
        break;

    case HWTIMER_CTRL_INFO_GET:

        /* TBD:sget a timer feature information */
        break;

    case HWTIMER_CTRL_MODE_SET:

        /* TBD:Setting the timing mode(oneshot/period) */
        break;
    default:

        /* TBD */
        break;
    }
    return res;
}

static rt_uint32_t skt_hwtimer_count_get(rt_hwtimer_t *timer)
{
    struct skt_hwtimer *hwtimer;
    hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* TBD */

}

static void skt_hwtimer_init(rt_hwtimer_t *timer, rt_uint32_t state)
{
    struct skt_hwtimer *hwtimer;
    hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* TBD:init hwtimer(hwtimer->hwtimer_periph)*/
}

static rt_err_t skt_hwtimer_start(rt_hwtimer_t *timer, rt_uint32_t cnt, rt_hwtimer_mode_t mode)
{
    rt_err_t res = RT_EOK;
    struct skt_hwtimer *hwtimer;
    hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* TBD:start hwtimer(hwtimer->hwtimer_periph)*/

    /* install interrupt */
    rt_hw_interrupt_install(hwtimer->irqno, rt_device_hwtimer_isr,
                            hwtimer, hwtimer->parent.parent.name);
    /* Enable the UART Interrupt */
    rt_hw_interrupt_umask(hwtimer->irqno);

    return res;
}

static void skt_hwtimer_stop(rt_hwtimer_t *timer)
{
    struct skt_hwtimer *hwtimer;
    hwtimer = SKT_HWTIMER_DEVICE(timer->parent.user_data);

    RT_ASSERT(hwtimer != RT_NULL);

    /* TBD:stop hwtimer(hwtimer->hwtimer_periph)*/
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
    int res = RT_EOK;
    static struct skt_hwtimer hwtimer0
    hwtimer0.parent.info = &hwtimer_info;
    hwtimer0.parent.ops  = &hwtimer_ops;

    res = rt_device_hwtimer_register(&hwtimer0.parent, "timer0", &hwtimer0);

    return res;
}
INIT_DEVICE_EXPORT(rt_hw_hwtimer_init);


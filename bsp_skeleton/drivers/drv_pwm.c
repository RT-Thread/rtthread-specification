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
#include "drv_pwm.h"

#ifdef RT_USING_PWM

#define SKT_PWM_DEVICE(pwm)    (struct skt_pwm_dev *)(pwm)

static struct skt_pwm_dev pwm_dev0;

struct skt_pwm_dev
{
    struct rt_device_pwm parent;
    rt_uint32_t pwm_periph;
};

static rt_err_t skt_pwm_enable(void *user_data, struct rt_pwm_configuration *cfg, rt_bool_t enable)
{
    rt_err_t ret = RT_EOK;

    /* start/stop pwm_x chanel_x output */
    return ret;
}

static rt_err_t skt_pwm_get(void *user_data, struct rt_pwm_configuration *cfg)
{
    rt_err_t ret = RT_EOK;

    /* get pluse ,period ... */
    return ret;
}
static rt_err_t skt_pwm_set(void *user_data, struct rt_pwm_configuration *cfg)
{
    rt_err_t ret = RT_EOK;

    /* set pluse ,period ... */
    return ret;
}

static rt_err_t skt_pwm_control(struct rt_device_pwm *device, int cmd, void *arg)
{
    rt_err_t ret = RT_EOK;
    struct skt_pwm_dev *pwm = SKT_PWM_DEVICE(device->parent.user_data);
    struct rt_pwm_configuration *cfg = (struct rt_pwm_configuration *)arg;

    RT_ASSERT(pwm != RT_NULL);

    switch (cmd)
    {
    case PWM_CMD_ENABLE:

        ret = skt_pwm_enable((void *)pwm->pwm_periph, cfg, RT_TRUE);
        break;
    case PWM_CMD_DISABLE:

        ret = skt_pwm_enable((void *)pwm->pwm_periph, cfg, RT_FALSE);
        break;
    case PWM_CMD_SET:

        ret = skt_pwm_set((void *)pwm->pwm_periph, cfg);
        break;
    case PWM_CMD_GET:

        ret = skt_pwm_get((void *)pwm->pwm_periph, cfg);
        break;
    default:
        ret = RT_EINVAL;
        break;
    }

    return ret;
}

const static struct rt_pwm_ops skt_pwm_ops =
{
    skt_pwm_control
};

int rt_hw_pwm_init(void)
{
    rt_err_t ret = RT_EOK;

    /* Todo: Init PWM Hardware */

    ret = rt_device_pwm_register(&pwm_dev0.parent, "pwm0", &skt_pwm_ops, &pwm_dev0);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_pwm_init);

#endif /* RT_USING_PWM */

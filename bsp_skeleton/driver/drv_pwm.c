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

#define SKT_PWM_DEVICE(pwm)    (struct skt_pwm_dev *)(pwm)

struct skt_pwm_dev
{
    struct rt_device_pwm parent;
    rt_uint32_t pwm_periph;
};

static rt_err_t skt_pwm_control(struct rt_device_pwm *device, int cmd, void *arg)
{
    rt_err_t res = RT_EOK;
    struct skt_pwm_dev *pwm = SKT_PWM_DEVICE(device->parent.user_data);
    struct rt_pwm_configuration *cfg = (struct rt_pwm_configuration *)arg;
    RT_ASSERT(pwm != RT_NULL);

    switch (cmd)
    {
    case PWM_CMD_ENABLE:

        /* Todo: enable PWM(pwm->pwm_periph) */
        break;
    case PWM_CMD_DISABLE:

        /* Todo: disable PWM(pwm->pwm_periph) */
        break;
    case PWM_CMD_SET:

        /* Todo: according to (cfg) configure PWM(pwm->pwm_periph) */
        break;
    case PWM_CMD_GET:

        /* Todo: get PWM(pwm->pwm_periph) configuration data */
        break;
    default:

        break;
    }

    return res;
}

const static struct rt_pwm_ops _pwm_ops =
{
    skt_pwm_control
};

int rt_hw_pwm_init(void)
{
    static struct skt_pwm_dev pwm_dev0;

    /* Todo: Init PWM Hardware */

    rt_device_pwm_register(&pwm_dev0.parent, "pwm0", &_pwm_ops, &pwm_dev0);

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_pwm_init);

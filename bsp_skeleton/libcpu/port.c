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

rt_base_t rt_hw_interrupt_disable(void)
{
    return 0;
}

void rt_hw_interrupt_enable(rt_base_t level)
{
    return ;
}

rt_uint8_t *rt_hw_stack_init(void       *entry,
                             void       *parameter,
                             rt_uint8_t *stack_addr,
                             void       *exit)
{
    return RT_NULL;
}

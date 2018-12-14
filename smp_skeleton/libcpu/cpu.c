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
#include <board.h>

int rt_hw_cpu_id(void)
{
    int cpu_id = 0;
    /*todo: arch get cpu id to cpu_id*/
    return cpu_id;
};

/**
 * @addtogroup ARM CPU
 */
/*@{*/

/** shutdown CPU */
void rt_hw_cpu_shutdown()
{
	rt_uint32_t level;
	rt_kprintf("shutdown...\n");

	level = rt_hw_interrupt_disable();
	while (level)
	{
		RT_ASSERT(0);
	}
}

/*@}*/

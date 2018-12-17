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

int rt_hw_cpu_id(void)
{
    int cpu_id = 0;
    /*todo: arch get cpu id to cpu_id*/
    return cpu_id;
}

rt_base_t rt_hw_local_irq_disable(void)
{
    return 0;
}

void rt_hw_local_irq_enable(rt_base_t level)
{
    return ;
}

void rt_hw_spin_lock(rt_hw_spinlock_t *lock)
{
    /* todo: */
}

void rt_hw_spin_unlock(rt_hw_spinlock_t *lock)
{
    /* todo: */
}

void idle_wfi(void)
{
    /*todo: wait for wakeup or do nothing */
}

void rt_hw_ipi_send(int ipi_vector, unsigned int cpu_mask)
{
    /* todo: send ipi */
    /* note: ipi_vector maybe different with irq_vector */
}

void rt_hw_ipi_handler_install(int ipi_vector, rt_isr_handler_t ipi_isr_handler)
{
    /* todo: set ipi handler */
    /* note: ipi_vector maybe different with irq_vector */
}

rt_uint8_t *rt_hw_stack_init(void       *entry,
                             void       *parameter,
                             rt_uint8_t *stack_addr,
                             void       *exit)
{
    return RT_NULL;
}

/**
 * @addtogroup CPU
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

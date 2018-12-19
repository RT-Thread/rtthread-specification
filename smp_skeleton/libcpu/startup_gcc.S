/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#include "rtconfig.h"
.text
/* reset entry */
.globl _reset
_reset:
    /* todo: arch init */

    /* todo: set stack */

    /* todo: clear .bss */

    /* todo: call C++ constructors of global objects */

    /* start RT-Thread Kernel */
    /* todo: call _rtthread_startup*/

/*todo: exception vector */

#ifdef RT_USING_SMP
.global secondary_cpu_start
secondary_cpu_start:
    /* todo: this cpu init */

    /* todo: init stack of this cpu*/

    /* todo: jump to secondary_cpu_c_start*/
#endif
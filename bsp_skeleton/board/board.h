/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_SRAM_SIZE        (96)
#define BOARD_SRAM_END         (0x20000000 + BOARD_SRAM_SIZE * 1024)

#define BOARD_FLASH_START_ADRESS     ((uint32_t)0x08000000)
#define BOARD_FLASH_SIZE             (1024 * 1024)
#define BOARD_FLASH_END_ADDRESS      ((uint32_t)(BOARD_FLASH_START_ADRESS + BOARD_FLASH_SIZE))

#if defined(__CC_ARM) || defined(__CLANG_ARM)
extern int Image$$RW_IRAM1$$ZI$$Limit;
#define HEAP_BEGIN      ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
#pragma section="CSTACK"
#define HEAP_BEGIN      (__segment_end("CSTACK"))
#else
extern int __bss_end;
#define HEAP_BEGIN      ((void *)&__bss_end)
#endif

#define HEAP_END        SCM_SRAM_END

#ifdef __cplusplus
}
#endif

#endif


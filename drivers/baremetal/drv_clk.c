/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-04-05     luobeihai    first version
 */

#include <apm32s10x.h>

static unsigned long tick = 0;

void systick_init(void)
{
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000);
}

void clk_init(char *clk_source, int source_freq, int target_freq)
{
    SystemInit();
    systick_init();
}

void wait_ms(unsigned long ms_time)
{
    tick = 0;

    while(tick < ms_time);
}

void SysTick_Handler(void)
{
    tick++;
}

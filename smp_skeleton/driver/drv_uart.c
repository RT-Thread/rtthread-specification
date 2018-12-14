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

#include "board.h"
#include "drv_uart.h"

#define SKT_UART_DEVICE(uart)    (struct skt_uart_dev *)(uart)

struct skt_uart_dev
{
    struct rt_serial_device parent;
    rt_uint32_t uart_periph;
    rt_uint32_t irqno;
};

void skt_uart_isr(int irqno, void *param)
{
    struct skt_uart_dev *uart = SKT_UART_DEVICE(param);

    RT_ASSERT(uart != RT_NULL);

    /* read interrupt status and clear it */
    if (0) /* rx ind */
    {
        rt_hw_serial_isr(&uart->parent, RT_SERIAL_EVENT_RX_IND);
    }

    if (0) /* tx done */
    {
        rt_hw_serial_isr(&uart->parent, RT_SERIAL_EVENT_TX_DONE);
    }
}

/*
 * UART interface
 */
static rt_err_t skt_uart_configure(struct rt_serial_device *serial, struct serial_configure *cfg)
{
    rt_err_t ret = RT_EOK;
    struct skt_uart_dev *uart;

    RT_ASSERT(serial != RT_NULL);

    serial->config = *cfg;

    uart = SKT_UART_DEVICE(serial->parent.user_data);
    RT_ASSERT(uart != RT_NULL);

    /* Init UART Hardware(uart->uart_periph) */

    /* Enable UART clock */

    /* Set both receiver and transmitter in UART mode (not SIR) */

    /* according to (cfg) set databits, baudrate, stopbits and parity. (8-bit data, 1 stopbit, no parity) */

    return ret;
}

static rt_err_t skt_uart_control(struct rt_serial_device *serial, int cmd, void *arg)
{
    rt_err_t ret = RT_EOK;
    struct skt_uart_dev *uart = SKT_UART_DEVICE(serial->parent.user_data);

    RT_ASSERT(uart != RT_NULL);

    rt_ubase_t ctrl_arg = (rt_ubase_t)arg;

    switch (cmd)
    {
    case RT_DEVICE_CTRL_CLR_INT:
        /* Disable the UART Interrupt */
        /* rt_hw_interrupt_mask(uart->irqno); */
        break;

    case RT_DEVICE_CTRL_SET_INT:
        /* install interrupt */
        /*
        rt_hw_interrupt_install(uart->irqno, skt_uart_isr,
                                serial, serial->parent.parent.name);
        */
        /* Enable the UART Interrupt */
        /* rt_hw_interrupt_umask(uart->irqno);*/

        break;

    case RT_DEVICE_CTRL_CONFIG:
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_RX)
        {
            /* Todo: DMA configuration  */
        }
        break;
    }

    return ret;
}

static int skt_uart_putc(struct rt_serial_device *serial, char c)
{
    struct skt_uart_dev *uart = SKT_UART_DEVICE(serial->parent.user_data);

    RT_ASSERT(uart != RT_NULL);

    /* FIFO status, contain valid data */

    /* Todo:write data (ch) to (uart->uart_periph) */

    return 1;
}

static int skt_uart_getc(struct rt_serial_device *serial)
{
    int ch;
    struct skt_uart_dev *uart = SKT_UART_DEVICE(serial->parent.user_data);

    RT_ASSERT(uart != RT_NULL);

    ch = -1;

    /* Todo:receive data from (uart->uart_periph) and store it in (ch) */

    return ch;
}

static rt_size_t skt_uart_dma_transmit(struct rt_serial_device *serial, rt_uint8_t *buf, rt_size_t size, int direction)
{
    struct skt_uart_dev *uart = SKT_UART_DEVICE(serial->parent.user_data);

    RT_ASSERT(uart != RT_NULL);

    return 0;
}

const static struct rt_uart_ops _uart_ops =
{
    skt_uart_configure,
    skt_uart_control,
    skt_uart_putc,
    skt_uart_getc,
    skt_uart_dma_transmit
};

/*
 * UART Initiation
 */
int rt_hw_uart_init(void)
{
    rt_err_t ret = RT_EOK;
    static struct skt_uart_dev uart0_dev;
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;

    uart0_dev.parent.ops = &_uart_ops;
    uart0_dev.parent.config = config;

    /* Todo: Init uart0_dev other data */

    /* Todo: Init uart0 hardware */

    ret = rt_hw_serial_register(&uart0_dev.parent,
                                "uart0",
                                RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX,
                                &uart0_dev);

    return ret;
}
INIT_DEVICE_EXPORT(rt_hw_uart_init);

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

struct skt_uart_device
{
    struct rt_serial_device parent;
    rt_uint32_t uart_periph;
    rt_uint32_t irqno;
};

/*
 * UART interface
 */
static rt_err_t hw_uart_configure(struct rt_serial_device *serial, struct serial_configure *cfg)
{
    struct skt_uart_device *uart;

    RT_ASSERT(serial != RT_NULL);

    uart = (struct skt_uart_device *)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    /* Init UART Hardware(uart->uart_periph) */

    /* Enable UART clock */

    /* Set both receiver and transmitter in UART mode (not SIR) */

    /* according to (cfg) set databits, baudrate, stopbits and parity. (8-bit data, 1 stopbit, no parity) */

    return RT_EOK;
}

static rt_err_t hw_uart_control(struct rt_serial_device *serial, int cmd, void *arg)
{
    struct skt_uart_device *uart;

    uart = (struct skt_uart_device *)serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);

    rt_ubase_t ctrl_arg = (rt_ubase_t)arg;

    switch (cmd)
    {
    case RT_DEVICE_CTRL_CLR_INT:
        /* Disable the UART Interrupt */
        rt_hw_interrupt_mask(uart->irqno);
        break;

    case RT_DEVICE_CTRL_SET_INT:
        /* install interrupt */
        rt_hw_interrupt_install(uart->irqno, uart_irq_handler,
                                serial, serial->parent.parent.name);
        /* Enable the UART Interrupt */
        rt_hw_interrupt_umask(uart->irqno);

        break;

    case RT_DEVICE_CTRL_CONFIG:
        if (ctrl_arg == RT_DEVICE_FLAG_DMA_RX)
        {
            /* TBD: DMA configuration  */
        }
        break;
    }

    return RT_EOK;
}

static int hw_uart_putc(struct rt_serial_device *serial, char c)
{
    struct skt_uart_device *uart;

    uart = (struct skt_uart_device *)serial->parent.user_data;

    /* FIFO status, contain valid data */

    /* TBD:write data (ch) to (uart->uart_periph) */

    return 1;
}

static int hw_uart_getc(struct rt_serial_device *serial)
{
    int ch;
    struct skt_uart_device *uart;

    uart = (struct skt_uart_device *)serial->parent.user_data;

    ch = -1;

    /* TBD:receive data from (uart->uart_periph) and store it in (ch) */

    return ch;
}

static rt_size_t hw_uart_dma_transmit(struct rt_serial_device *serial, rt_uint8_t *buf, rt_size_t size, int direction)
{
    return 0;
}

/* UART ISR */
static void uart_irq_handler(struct rt_serial_device *serial)
{
    struct skt_uart_device *uart;
    RT_ASSERT(serial != RT_NULL);

    uart = (struct skt_uart_device)serial->parent.user_data;

    /* read interrupt status and clear it */
    if (0) /* rx ind */
    {
        rt_hw_serial_isr(serial, RT_SERIAL_EVENT_RX_IND);
    }

    if (0) /* tx done */
    {
        rt_hw_serial_isr(serial, RT_SERIAL_EVENT_TX_DONE);
    }
}


const struct rt_uart_ops _uart_ops =
{
    hw_uart_configure,
    hw_uart_control,
    hw_uart_putc,
    hw_uart_getc,
    hw_uart_dma_transmit
};

/*
 * UART Initiation
 */
int rt_hw_uart_init(void)
{
    static struct skt_uart_device uart0_dev;

    uart0_dev.parent.ops = &_uart_ops;
    uart0_dev.parent.config = RT_SERIAL_CONFIG_DEFAULT;

    /* TBD: Init skt_uart0 other data */

    rt_hw_serial_register(&uart0_dev.parent,
                          "uart0",
                          RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX,
                          &uart0_dev);

    /* TBD: register other I2C device */

    return 0;
}
INIT_DEVICE_EXPORT(rt_hw_uart_init);

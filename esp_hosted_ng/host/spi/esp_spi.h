// SPDX-License-Identifier: GPL-2.0-only
/*
 * SPDX-FileCopyrightText: 2015-2023 Espressif Systems (Shanghai) CO LTD
 *
 */

#ifndef _ESP_SPI_H_
#define _ESP_SPI_H_

#include "esp.h"

#define HANDSHAKE_PIN           113
#define SPI_IRQ                 gpio_to_irq(HANDSHAKE_PIN)
#define SPI_DATA_READY_PIN      112
#define SPI_DATA_READY_IRQ      gpio_to_irq(SPI_DATA_READY_PIN)
#define SPI_BUF_SIZE            1600

struct esp_spi_context {
	struct esp_adapter          *adapter;
	struct spi_device           *esp_spi_dev;
	struct sk_buff_head         tx_q[MAX_PRIORITY_QUEUES];
	struct sk_buff_head         rx_q[MAX_PRIORITY_QUEUES];
	struct workqueue_struct     *spi_workqueue;
	struct work_struct          spi_work;
	struct workqueue_struct     *nw_cmd_reinit_workqueue;
	struct work_struct          nw_cmd_reinit_work;
	uint8_t                     spi_clk_mhz;
	uint8_t                     spi_gpio_enabled;
	uint8_t                     reserved[2];
};

enum {
	CLOSE_DATAPATH,
	OPEN_DATAPATH,
};


#endif

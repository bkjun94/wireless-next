/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC SPI Module Parameters Header
 */

#ifndef _NRC_SPI_PARAMS_H
#define _NRC_SPI_PARAMS_H

/* Linux kernel headers */
#include <linux/types.h>

/* SPI Configuration Parameters */
extern int spi_bus_num;
extern int spi_cs_num;
extern int spi_gpio_irq;
extern int spi_reset_gpio;
extern int spi_polling_interval;
extern int spi_gdma_irq;
extern bool enable_hspi_init;
extern int hifspeed;
extern int power_save_gpio[3];

/* SPI Parameter initialization function */
void nrc_spi_params_init(void);

#endif /* _NRC_SPI_PARAMS_H */

/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC SPI Device Registration Interface
 */

#ifndef _NRC_SPI_DEVICE_H
#define _NRC_SPI_DEVICE_H

/* Linux kernel headers */
#include <linux/spi/spi.h>

/* Forward declarations */
struct nrc_spi_device_info;
struct nrc_hif_ops;

/* SPI device registration functions - exported via EXPORT_SYMBOL */
struct nrc_spi_device_info *nrc_spi_get_device_info(void);
bool nrc_spi_is_device_available(void);

/* Register/Unregister SPI device for HAL layer */
int nrc_spi_register_device(struct spi_device *spi, void *priv, struct nrc_hif_ops *ops);
void nrc_spi_unregister_device(struct spi_device *spi);

#endif /* _NRC_SPI_DEVICE_H */

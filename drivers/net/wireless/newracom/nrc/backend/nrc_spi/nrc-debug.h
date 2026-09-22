/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2025 Newracom, Inc.
 *
 * NRC SPI Backend Debug Functions Header
 */

#ifndef _NRC_SPI_DEBUG_H_
#define _NRC_SPI_DEBUG_H_

#include <linux/spi/spi.h>

/* Include common debug interface */
#include "nrc-debug-common.h"

/* Backend layer aliases */
#ifndef ERR_SPI
#define ERR_SPI(fmt, ...) ERR(fmt, ##__VA_ARGS__)
#endif
#ifndef WARN_SPI
#define WARN_SPI(fmt, ...) WRN(fmt, ##__VA_ARGS__)
#endif
#ifndef INFO_SPI
#define INFO_SPI(fmt, ...) INFO(fmt, ##__VA_ARGS__)
#endif
#ifndef DBG_SPI
#define DBG_SPI(fmt, ...) DBG(CAT(BASIC), fmt, ##__VA_ARGS__)
#endif
#ifndef VBS_SPI
#define VBS_SPI(fmt, ...) VBS(CAT(BASIC), fmt, ##__VA_ARGS__)
#endif


/* ===========================================================================
 * SPI Debug Function Prototypes
 * =========================================================================== */

/* Debug functions */
void nrc_spi_init_debugfs(struct spi_device *spi);
void nrc_spi_exit_debugfs(void);
void nrc_spi_debug_info(struct spi_device *spi);

#endif /* _NRC_SPI_DEBUG_H_ */

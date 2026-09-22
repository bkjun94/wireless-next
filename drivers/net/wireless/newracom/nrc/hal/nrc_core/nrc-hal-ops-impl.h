/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC HAL Operations Implementation Header
 */

#ifndef _NRC_HAL_OPS_IMPL_H_
#define _NRC_HAL_OPS_IMPL_H_

#include "nrc.h"

/* ===========================================================================
 * HAL Operations Structure Access
 * =========================================================================== */

/**
 * nrc_hal_get_default_ops - Get default HAL operations structure
 *
 * Returns: Pointer to default HAL operations
 */
struct nrc_hal_ops *nrc_hal_get_default_ops(void);

#endif /* _NRC_HAL_OPS_IMPL_H_ */

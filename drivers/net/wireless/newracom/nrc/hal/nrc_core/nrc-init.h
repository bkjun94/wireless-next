/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 */
#ifndef _NRC_INIT_H_
#define _NRC_INIT_H_

#include "nrc-hif.h"

struct nrc_test_ops;
struct nrc_uart_priv;

/* HIF Device Management Functions */
int nrc_hal_fw_init(struct nrc_hif_device *hdev);
void nrc_hal_fw_cleanup(struct nrc_hif_device *hdev);
int nrc_nw_start(void);
int nrc_nw_start_fusing(void);
int nrc_nw_stop(void);

/* Parameters Management Functions */
struct nrc_params *nrc_params_alloc(void);
void nrc_params_free(struct nrc_params *params);

/* Hardware Configuration Functions */
void nrc_init_credit_queue(struct nrc_hif_device *hdev);

#endif

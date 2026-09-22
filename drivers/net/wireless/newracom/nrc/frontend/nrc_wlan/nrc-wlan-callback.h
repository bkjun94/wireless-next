/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC WLAN Callback Interface
 */

#ifndef _NRC_WLAN_CALLBACK_H
#define _NRC_WLAN_CALLBACK_H

#include <linux/types.h>
#include "nrc-hal-core-callback.h"

/* WLAN Event Processing Functions */
int nrc_wlan_handle_spi_irq(struct nrc_hal_event_data *event);
int nrc_wlan_handle_rx_ready(struct nrc_hal_event_data *event);
int nrc_wlan_handle_tx_complete(struct nrc_hal_event_data *event);
int nrc_wlan_handle_fw_ready(struct nrc_hal_event_data *event);
int nrc_wlan_handle_error(struct nrc_hal_event_data *event);
int nrc_wlan_handle_reg_notifier(struct nrc_hal_event_data *event);

/* WLAN Callback System */
int nrc_wlan_callback_init(void);
void nrc_wlan_callback_cleanup(void);

#endif /* _NRC_WLAN_CALLBACK_H */

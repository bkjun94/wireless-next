/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * NRC MCP Callback Interface
 *
 * Copyright (c) 2016-2019 Newracom, Inc.
 */

#ifndef _NRC_MCP_CALLBACK_H_
#define _NRC_MCP_CALLBACK_H_

#include <linux/types.h>
#include "nrc-hal-core-callback.h"

/*
 * MCP Event Processing Functions
 */
int nrc_mcp_handle_spi_irq(struct nrc_hal_event_data *event);
int nrc_mcp_handle_rx_ready(struct nrc_hal_event_data *event);
int nrc_mcp_handle_tx_complete(struct nrc_hal_event_data *event);
int nrc_mcp_handle_fw_ready(struct nrc_hal_event_data *event);
int nrc_mcp_handle_error(struct nrc_hal_event_data *event);
// int nrc_mcp_handle_reg_notifier(struct nrc_hal_event_data *event);

/* MCP Callback System */
int nrc_mcp_callback_init(void);
void nrc_mcp_callback_cleanup(void);

#endif /* _NRC_MCP_CALLBACK_H */

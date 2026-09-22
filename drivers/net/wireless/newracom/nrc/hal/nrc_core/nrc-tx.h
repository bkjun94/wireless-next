/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 */

#ifndef __NRC_TX_H__
#define __NRC_TX_H__

#include <linux/workqueue.h>

/* Forward declarations */
struct nrc;
struct sk_buff;

/**
 * nrc_hif_wlan_work - WLAN frontend HIF transmission work handler
 * @work: work structure
 *
 * Handles transmission of WLAN frames and WIM commands through the HIF layer.
 * Processes queues in priority order with special handling for deauth frames.
 */
void nrc_hif_wlan_work(struct work_struct *work);

/**
 * nrc_hif_mcp_work - MCP frontend HIF transmission work handler
 * @work: work structure
 *
 * Handles transmission of MCP frames and commands through the HIF layer.
 */
void nrc_hif_mcp_work(struct work_struct *work);

void nrc_tx_flush_wq(struct nrc_hif_device *hdev);
void nrc_tx_cleanup_queues(void);

#endif /* __NRC_TX_H__ */

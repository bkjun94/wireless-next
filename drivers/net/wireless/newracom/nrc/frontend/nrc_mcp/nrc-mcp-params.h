/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC MCP Module Parameters Header
 */

#ifndef _NRC_MCP_PARAMS_H_
#define _NRC_MCP_PARAMS_H_

/* ===========================================================================
 * Parameter Synchronization Functions
 * =========================================================================== */

/* Forward declaration */
struct mcp_priv;

/**
 * nrc_mcp_sync_params - Synchronize MCP parameters to mcp_priv structure
 * @mcp: MCP device structure
 *
 * This function copies MCP module parameters to the mcp_priv device structure
 * so that the MCP layer can access them without direct parameter references.
 */
void nrc_mcp_sync_params(struct mcp_priv *mcp);

/* CQM initialization and cleanup handled in MAC80211 layer */

#endif /* _NRC_MCP_PARAMS_H_ */

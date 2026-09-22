/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC WLAN Module Parameters Header
 */

#ifndef _NRC_WLAN_PARAMS_H_
#define _NRC_WLAN_PARAMS_H_

/* ===========================================================================
 * Parameter Synchronization Functions
 * =========================================================================== */

/**
 * nrc_wlan_sync_params - Synchronize WLAN parameters to nrc structure
 * @nw: NRC device structure
 *
 * This function copies WLAN module parameters to the nrc device structure
 * so that the HAL layer can access them without direct parameter references.
 */
void nrc_wlan_sync_params(struct nrc *nw);

/* CQM initialization and cleanup handled in MAC80211 layer */

#endif /* _NRC_WLAN_PARAMS_H_ */

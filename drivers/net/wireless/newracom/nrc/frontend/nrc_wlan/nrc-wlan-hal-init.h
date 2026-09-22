/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC WLAN HAL Early Initialization Header
 */

#ifndef _NRC_WLAN_HAL_INIT_H_
#define _NRC_WLAN_HAL_INIT_H_

#include "nrc.h"

/* WLAN HAL Early Initialization Functions */
int nrc_wlan_hal_early_init(void);
void nrc_wlan_hal_early_cleanup(void);

/* Network device access from WLAN layer */
struct nrc *nrc_wlan_get_nw(void);  /* Get nrc(NetWork) */
struct ieee80211_hw *nrc_wlan_get_hw(void);  /* Get MAC80211 hardware */
bool nrc_wlan_is_initialized(void);  /* Check if WLAN is initialized */
struct device *nrc_wlan_get_device(void);  /* Get device pointer */

/* WLAN-specific initialization functions */
int nrc_wlan_nw_init(struct nrc *nw);
void nrc_wlan_nw_deinit(struct nrc *nw);

#endif /* _NRC_WLAN_HAL_INIT_H_ */

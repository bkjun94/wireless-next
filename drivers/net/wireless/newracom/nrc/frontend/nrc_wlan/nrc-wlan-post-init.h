/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC WLAN Post-HAL Initialization Header
 */

#ifndef _NRC_WLAN_POST_INIT_H_
#define _NRC_WLAN_POST_INIT_H_

int nrc_wlan_post_hal_init(bool restart);

void nrc_wlan_post_hal_cleanup(bool restart);

#endif /* _NRC_WLAN_POST_INIT_H_ */

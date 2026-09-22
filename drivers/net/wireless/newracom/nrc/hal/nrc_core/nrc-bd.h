/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 */

#ifndef _NRC_BD_H_
#define _NRC_BD_H_

struct BDF {
	uint8_t ver_major;
	uint8_t ver_minor;
	uint16_t total_len;

	uint16_t num_data_groups;
	uint16_t reserved[4];
	uint16_t checksum_data;

	uint8_t data[];
};

#if defined(CONFIG_SUPPORT_BD)
struct wim_bd_param *nrc_read_bd_tx_pwr(struct nrc_hif_device *hdev,
					uint8_t *cc);
int nrc_check_bd(struct nrc_hif_device *hdev);
#endif /* defined(CONFIG_SUPPORT_BD) */

#endif //_NRC_BD_H_

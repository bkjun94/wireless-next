/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2024 Newracom, Inc.
 */

#ifndef __NRC_APF_H__
#define __NRC_APF_H__


int nrc_apf_get_enable (struct nrc *nw, int *enable);
int nrc_apf_set_enable (struct nrc *nw, int enable);
int nrc_apf_get_version (struct nrc *nw);
int nrc_apf_get_maxlen (struct nrc *nw);
int nrc_apf_set_packet_filter (struct nrc *nw, u8 *program, size_t len);
int nrc_apf_read_packet_filter (struct nrc *nw, u32 src_offset, u8 *host_dst, u32 len);

void nrc_apf_debugfs_init (struct dentry *root, void *nw);

#endif

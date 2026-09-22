/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright(c) 2016-2024 Newracom, Inc.
 */

#ifndef _NRC_PS_H_
#define _NRC_PS_H_

#include "nrc.h"
#include "nrc-ps-common.h"

/* Note: enum NRC_PS_REASON is now defined in nrc-ps-common.h
 * to allow all layers (Backend, HAL, Frontend) to access it */

int nrc_ps_set_mode(struct nrc *nw, enum NRC_PS_MODE mode, u64 timeout,
		    struct cfg80211_wowlan *wowlan,
		    enum NRC_PS_REASON reason);

/*
 * Default PS timer timeout (ms) used when mac80211 has not configured
 * dynamic_ps_timeout (i.e. the value is 0).  Applies to:
 *   - Deep sleep auto-start after association (nrc_bss_handle_assoc)
 */
#define NRC_PS_DEFAULT_TIMEOUT_MS	3000

/* Dynamic PS functions - runtime controlled via hdev->ps.supports_dynamic_ps */
void nrc_ps_dyn_init(struct nrc *nw);
void nrc_ps_dyn_deinit(struct nrc *nw);
void nrc_ps_dyn_start(struct nrc *nw, int busy_delay_ms,
		      enum NRC_PS_REASON reason);/* Start PS timer with a busy-guard delay (ms) to defer sleep entry.
 * Pass 0 for a normal base-timeout start. */
void nrc_ps_dyn_stop(struct nrc *nw, enum NRC_PS_REASON reason);

int nrc_ps_set_idle_mode(struct nrc *nw, char *msg);
int nrc_ps_set_idle_mode_delay(struct nrc *nw, char *msg, int delay_ms);
void nrc_ps_set_idle_mode_work_handler(struct work_struct *work);
const char *nrc_ps_get_state_str(struct nrc *nw);

#endif

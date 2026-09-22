/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2016-2019 Newracom, Inc.
 *
 * NRC MCP Log Interface - Unified debug system integration
 */

#ifndef NRC_LOG_H
#define NRC_LOG_H

#include "nrc-debug.h"

/* Legacy log level definitions - for backward compatibility only */
#define LOG_LEVEL_NONE (0)
#define LOG_LEVEL_ERR (1)
#define LOG_LEVEL_WARN (2)
#define LOG_LEVEL_INFO (3)
#define LOG_LEVEL_DBG (4)

/**
 * Legacy log macros - mapped to new optimized debug macros
 *
 * These macros maintain backward compatibility while using the unified
 * nrc-debug-common infrastructure underneath.
 */
#define LOG_ERR(...) ERR(__VA_ARGS__)
#define LOG_WARN(...) WRN(__VA_ARGS__)
#define LOG_INFO(...) INFO(__VA_ARGS__)
#define LOG_WIM(...) DBG_WIM(__VA_ARGS__)

/**
 * nrc_logger_set - Legacy string-based log level control
 * @str_module: Module name (currently ignored)
 * @str_level: Log level string ("none", "err", "warn", "info", "dbg")
 *
 * Provides backward compatibility for netlink-based log control.
 */
void nrc_logger_set(const char *str_module, const char *str_level);

#endif /* NRC_LOG_H */

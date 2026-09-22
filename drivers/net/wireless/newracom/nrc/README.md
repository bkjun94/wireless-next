<!-- SPDX-License-Identifier: BSD-3-Clause-Clear -->

# Newracom NRC7394 802.11ah (HaLow) driver

Three-layer modular Linux kernel driver for the Newracom NRC7394 Wi-Fi HaLow
(IEEE 802.11ah / S1G) chipset attached over SPI.

This directory contains the driver source only. Firmware, board-data files,
userland tools, test packages and developer documentation are distributed
separately.

## Modules

```
  nrc_spi.ko  ->  nrc_core.ko  ->  nrc_wlan.ko   (mac80211 frontend)
  (backend)       (HAL)            nrc-mcp.ko    (optional MCP frontend)
```

| Module      | Layer    | Role                                                  |
|-------------|----------|-------------------------------------------------------|
| nrc_spi     | Backend  | C-SPI transport, slot/credit management, GPIO (reset, wakeup, IRQ) |
| nrc_core    | HAL      | Firmware lifecycle, WIM protocol, power-save state machine, board data |
| nrc_wlan    | Frontend | mac80211 driver: STA/AP, S1G, TWT, power save, private genl interface |
| nrc-mcp     | Frontend | Optional management/control-plane netlink interface   |

Layers communicate only through the interface and callback structures
declared in `common/`; no layer includes another layer's private headers.

## Directory layout

```
nrc/
├── Kconfig                 CONFIG_NRC7394, CONFIG_NRC7394_DEBUG, CONFIG_NRC7394_MCP
├── Kbuild                  In-tree build entry (recurses into the layers below)
├── Makefile                Out-of-tree build helper
├── common/                 Shared headers and cross-layer interfaces
├── backend/
│   ├── dts/                Example device-tree overlay
│   └── nrc_spi/            SPI backend module
├── hal/
│   └── nrc_core/           HAL core module
└── frontend/
    ├── nrc_wlan/           mac80211 frontend module
    └── nrc_mcp/            MCP frontend module (optional)
```

## Kernel configuration

```
Device Drivers -> Network device support -> Wireless LAN
  -> Newracom NRC7394 802.11ah HaLow driver (modular)   [CONFIG_NRC7394=m]
     -> Enable debug support                             [CONFIG_NRC7394_DEBUG]
     -> NRC7394 MCP Frontend (nrc_mcp.ko)                [CONFIG_NRC7394_MCP]
```

Dependencies: `CONFIG_MAC80211`, `CONFIG_SPI`, `CONFIG_FW_LOADER`.

## Building

As part of the kernel tree:

```sh
make menuconfig                                  # enable CONFIG_NRC7394=m
make -j$(nproc) modules
make -j$(nproc) M=drivers/net/wireless/newracom/nrc modules   # this driver only
```

## Firmware and board data

The driver loads its firmware and board-data files through the kernel
firmware loader (`request_firmware()`), so they must be present under
`/lib/firmware`. The file names are given by the `fw_name` and `bd_name`
module parameters of the frontend module. The firmware files themselves are
not part of this tree.

## Loading

The modules are loaded in dependency order. With the modules installed,
`modprobe` resolves the chain automatically:

```sh
modprobe nrc_wlan          # loads nrc_spi -> nrc_core -> nrc_wlan
modprobe nrc-mcp           # optional MCP frontend
```

Module parameters can be set on the command line or in `/etc/modprobe.d/`.
Use `modinfo nrc_spi`, `modinfo nrc_core` and `modinfo nrc_wlan` to list the
available parameters.

Unload in reverse order:

```sh
modprobe -r nrc_wlan       # or nrc-mcp
modprobe -r nrc_core
modprobe -r nrc_spi
```

## Debugging

Runtime debug controls are exposed through debugfs under
`/sys/kernel/debug/nrc_core/` (for example `debug_mask` and `skb_stats`).
Kernel log output can be followed with `dmesg -wH`.

## License

See the SPDX identifiers and license headers in the individual source files.

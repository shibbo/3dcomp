#pragma once

#include "nvn.h"
#include "nvn_FuncPtr.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline void nvnDeviceFinalize(NVNdevice* device) {
    pfnc_nvnDeviceFinalize(device);
}

#ifdef __cplusplus
}
#endif
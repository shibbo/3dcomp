#pragma once

#include "nvn.h"

extern PFNNVNDEVICEINITIALIZEPROC pfnc_nvnDeviceInitialize;
extern PFNNVNDEVICEFINALIZEPROC pfnc_nvnDeviceFinalize;

extern PFNNVNSAMPLERBUILDERSETDEVICEPROC pfnc_nvnSamplerBuilderSetDevice;

extern PFNNVNSAMPLERBUILDERSETREDUCTIONFILTERPROC pfnc_nvnSamplerBuilderSetReductionFilter;

extern PFNNVNSAMPLERINITIALIZEPROC pfnc_nvnSamplerInitialize;
extern PFNNVNSAMPLERFINALIZEPROC pfnc_nvnSamplerFinalize;
extern PFNNVNSAMPLERSETDEBUGLABELPROC pfnc_nvnSamplerSetDebugLabel;
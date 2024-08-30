#pragma once

#include <stdint.h>

typedef struct NVNdeviceBuilder NVNdeviceBuilder;
typedef struct NVNdevice NVNdevice;

typedef struct NVNsamplerBuilder NVNsamplerBuilder;
typedef struct NVNsampler NVNsampler;

#define NVN_PRE_ALIGN(ALIGN)

#ifdef __INTELLISENSE__
#define NVN_POST_ALIGN(ALIGN)
#else
#define NVN_POST_ALIGN(ALIGN) __attribute__((aligned(ALIGN)))
#endif

#define NVNAPIENTRY

#ifndef NVNAPIENTRYP
#define NVNAPIENTRYP NVNAPIENTRY*
#endif

#ifndef NVN_ENUM_32BIT
#define NVN_ENUM_32BIT(ENUMTYPE) NVN_##ENUMTYPE##_LARGE = 0x7FFFFFFF
#endif

typedef uint8_t NVNboolean;

typedef enum NVNsamplerReduction {
    NVN_SAMPLER_REDUCTION_AVERAGE = 0x00000000,
    NVN_SAMPLER_REDUCTION_MIN = 0x00000001,
    NVN_SAMPLER_REDUCTION_MAX = 0x00000002,

    NVN_ENUM_32BIT(SAMPLER_REDUCTION),
} NVNsamplerReduction;

NVN_PRE_ALIGN(8) struct NVNdeviceBuilder {
    char reserved[64];
} NVN_POST_ALIGN(8);

NVN_PRE_ALIGN(8) struct NVNdevice {
    char reserved[12288];
} NVN_POST_ALIGN(8);

NVN_PRE_ALIGN(8) struct NVNsamplerBuilder {
    char reserved[96];
} NVN_POST_ALIGN(8);

NVN_PRE_ALIGN(8) struct NVNsampler {
    char reserved[96];
} NVN_POST_ALIGN(8);

typedef NVNboolean(NVNAPIENTRYP PFNNVNDEVICEINITIALIZEPROC)(NVNdevice* device,
                                                            const NVNdeviceBuilder* builder);
typedef void(NVNAPIENTRYP PFNNVNDEVICEFINALIZEPROC)(NVNdevice* device);

typedef void(NVNAPIENTRYP PFNNVNSAMPLERBUILDERSETDEVICEPROC)(NVNsamplerBuilder* builder,
                                                             NVNdevice* device);

typedef void(NVNAPIENTRYP PFNNVNSAMPLERBUILDERSETREDUCTIONFILTERPROC)(NVNsamplerBuilder* builder,
                                                                      NVNsamplerReduction filter);

typedef NVNboolean(NVNAPIENTRYP PFNNVNSAMPLERINITIALIZEPROC)(NVNsampler* sampler,
                                                             const NVNsamplerBuilder* builder);

typedef void(NVNAPIENTRYP PFNNVNSAMPLERFINALIZEPROC)(NVNsampler*);
typedef void(NVNAPIENTRYP PFNNVNSAMPLERSETDEBUGLABELPROC)(NVNsampler*, const char*);
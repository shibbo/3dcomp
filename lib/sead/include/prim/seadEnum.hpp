#pragma once

#define SEAD_ENUM(NAME, ...)                                                                       \
    class NAME {                                                                                   \
    public:                                                                                        \
        enum ValueType { __VA_ARGS__ };                                                            \
                                                                                                   \
        NAME() : mIdx(0) {}                                                                        \
                                                                                                   \
    private:                                                                                       \
        int mIdx;                                                                                  \
    };
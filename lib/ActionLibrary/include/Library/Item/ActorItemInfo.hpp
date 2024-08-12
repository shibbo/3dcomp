#pragma once

namespace al {
    class ActorItemInfo {
    public:
        ActorItemInfo(const char*, const char*, const char*);

        bool isEqualTiming(const char*) const;
        bool isEqualFactor(const char*) const;

        const char* mItemKind;  // 0x00
        const char* mTiming;    // 0x08
        const char* mFactor;    // 0x10
    };
};  // namespace al
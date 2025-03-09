#pragma once

namespace al {
class ActorItemInfo {
public:
    ActorItemInfo(const char*, const char*, const char*);

    bool isEqualTiming(const char*) const;
    bool isEqualFactor(const char*) const;

    const char* mItemKind;
    const char* mTiming;
    const char* mFactor;
};
}  // namespace al

#pragma once

#include <basis/seadTypes.h>

namespace al {
struct UnkStruct {
    s32 num;
};

template <typename T>
class AudioInfoList {
public:
    s32 getInfoNum() const {
        s32 num = _0->num;

        if (mInfoList != nullptr)
            return mInfoList->getInfoNum() + num;

        return num;
    }

    void sortInfo();

    UnkStruct* _0;
    AudioInfoList<T>* mInfoList;
};
}  // namespace al

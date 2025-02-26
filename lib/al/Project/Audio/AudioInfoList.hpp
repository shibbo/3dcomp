#pragma once

namespace al {
    struct UnkStruct {
        int num;  // 0x00
    };

    template <typename T>
    class AudioInfoList {
    public:
        int getInfoNum() const {
            int num = _0->num;

            if (mInfoList != nullptr) {
                return mInfoList->getInfoNum() + num;
            }

            return num;
        }

        void sortInfo();

        UnkStruct* _0;
        AudioInfoList<T>* mInfoList;  // 0x08
    };
};  // namespace al
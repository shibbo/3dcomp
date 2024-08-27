#include "Project/Message/MessageTag.hpp"

namespace al {
    /*MessageTag::MessageTag(const nn::font::PrintContext<u16>* pContext) {
        mTag = nullptr;

        const u16* str = pContext->str;
        u16 v5 = *(str - 1);
        const u16* v3 = (str - 1);

        if (v5 == 15 || v5 == 14) {
            mTag = v3;
        } else {
            mTag = nullptr;
        }
    }*/

    MessageTag::MessageTag(const char16_t* pTag) {
        mTag = nullptr;

        switch (*pTag) {
        case 14:
            mTag = pTag;
            break;
        case 15:
            mTag = pTag;
            break;
        default:
            mTag = nullptr;
        }
    }

    /*s8 MessageTag::getParam8(s32 idx) const {
        return *(mTag + idx + 4);
    }*/

    s16 MessageTag::getParam16(s32 idx) const {
        return *(mTag + idx + 4);
    }

    /*s32 MessageTag::getParam32(s32 idx) const {
        return (mTag + idx)[4];
    }*/

};  // namespace al
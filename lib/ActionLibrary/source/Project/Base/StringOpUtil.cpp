#include "Project/Base/StringOpUtil.hpp"
#include <basis/seadNew.hpp>
#include <cstdio>
#include <cstring>
#include "Project/Base/StringUtil.hpp"

namespace al {
    const char* getBaseName(const char* pStr) {
        const char* nameOcc = strrchr(pStr, '/');

        if (nameOcc != nullptr) {
            return nameOcc + 1;
        }

        return pStr;
    }

    const char* createStringIfInStack(const char* pStr) {
        if (al::isInStack(pStr)) {
            size_t len = int(strlen(pStr)) + 1;
            char* buf = new char[len];
            snprintf(buf, len, "%s", pStr);
            return buf;
        }

        return pStr;
    }

    char* createConcatString(const char* pStr1, const char* pStr2) {
        size_t len = int(strlen(pStr1) + strlen(pStr2)) + 1;
        char* buf = new char[len];
        snprintf(buf, len, "%s%s", pStr1, pStr2);
        return buf;
    }

    void removeExtensionString(char* pOut, u32 length, const char* pSource) {
        snprintf(pOut, length, "%s", pSource);
        char* extOccur = strrchr(pOut, '.');
        char* slashOccur = strrchr(pOut, '/');

        if (extOccur != nullptr && extOccur >= slashOccur && slashOccur + 1 != extOccur) {
            *extOccur = 0;
        }
    }

    bool isEqualString(const char16_t* pStr1, const char16_t* pStr2) {
        while (*pStr1 == *pStr2) {
            char16_t cur = *pStr1;
            if (!cur) {
                return true;
            }

            ++pStr2;
            ++pStr1;
        }

        return false;
    }

    bool isEqualSubString(const char* pString1, const char* pString2) {
        return strstr(pString1, pString2) != 0;
    }

    bool isEqualSubString(const sead::SafeString& rString1, const sead::SafeString& rString2) {
        rString1.assureTerminationImpl_();
        const char* str1 = rString1.mString;
        rString2.assureTerminationImpl_();
        const char* str2 = rString2.mString;

        return isEqualSubString(str1, str2);
    }

    bool isStartWithString(const char* pString1, const char* pString2) {
        if (!*pString2) {
            return true;
        }

        while (*pString1 && *pString1 == *pString2) {
            ++pString1;
            ++pString2;

            if (!*pString2) {
                return true;
            }
        }

        return false;
    }

    bool isEndWithString(const char* pString1, const char* pString2) {
        s32 len_1 = strlen(pString1);
        s32 len_2 = strlen(pString2);

        if (len_1 < len_2) {
            return false;
        }

        return isEqualString(&pString1[len_1 - len_2], pString2);
    }
};  // namespace al
#include "Project/Base/StringOpUtil.hpp"
#include <cstring>
#include "Project/Base/StringUtil.hpp"

namespace al {
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
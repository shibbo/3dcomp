#include "Project/Base/StringUtil.hpp"
#include <cstring>

namespace al {
    bool isEqualString(const char* pStr1, const char* pStr2) {
        while (*pStr1 == *pStr2) {
            char cur = *pStr1;
            if (!cur) {
                return true;
            }

            ++pStr2;
            ++pStr1;
        }

        return false;
    }

    bool isEqualString(const sead::SafeString& rString1, const sead::SafeString& rString2) {
        rString1.assureTerminationImpl_();
        const char* str1 = rString1.mString;
        rString2.assureTerminationImpl_();
        const char* str2 = rString2.mString;

        return isEqualString(str1, str2);
    }

    bool isEqualStringCase(const char* pString1, const char* pString2) {
        return strcasecmp(pString1, pString2) == 0;
    }

    bool isEqualStringCase(const sead::SafeString& rString1, const sead::SafeString& rString2) {
        rString1.assureTerminationImpl_();
        const char* str1 = rString1.mString;
        rString2.assureTerminationImpl_();
        const char* str2 = rString2.mString;

        return isEqualStringCase(str1, str2);
    }

};  // namespace al
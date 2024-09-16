#include "ui2d/ui2d_Pane.hpp"
#include "util/util_MatrixApi.hpp"
#include "util/util_StringUtil.hpp"

namespace nn {
    namespace ui2d {
        namespace detail {
            PaneBase::PaneBase() {}

            PaneBase::~PaneBase() {}
        };  // namespace detail

        void Pane::InitializeParams() {
            mParent = nullptr;
            mFlag = 0;
            mFlagEx = 0;
            mSystemFlags = 0;
            mExtUserDataList = nullptr;
            nn::util::MatrixIdentity(&mGlobalMtx);
            mUserMtx = nullptr;
        }

        void Pane::SetName(const char* pName) {
            nn::util::Strlcpy(mName, pName, sizeof(mName));
        }

        void Pane::SetUserData(const char* pUserData) {
            nn::util::Strlcpy(mUserData, pUserData, sizeof(mUserData));
        }
    };  // namespace ui2d
};  // namespace nn
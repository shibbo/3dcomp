#include "Project/Bgm/BgmLineKeeper.hpp"
#include "Project/Base/StringUtil.hpp"

namespace al {
    BgmLineKeeper::BgmLineKeeper(f32 val) : _8C(val) {}

    s32 BgmLineKeeper::checkIfIsIslandBgm(const BgmPlayingRequest& rReq) {
        if (rReq.mName == nullptr) {
            return -1;
        }

        if (al::isEqualString(rReq.mName, "Island01")) {
            return 0;
        }

        if (al::isEqualString(rReq.mName, "Island02")) {
            return 1;
        }

        if (al::isEqualString(rReq.mName, "Island03")) {
            return 2;
        }

        if (al::isEqualString(rReq.mName, "Island04")) {
            return 3;
        }

        if (al::isEqualString(rReq.mName, "Island05")) {
            return 4;
        }

        if (al::isEqualString(rReq.mName, "Island06")) {
            return 5;
        }

        if (al::isEqualString(rReq.mName, "Island07")) {
            return 6;
        }

        if (al::isEqualString(rReq.mName, "Island08")) {
            return 7;
        }

        if (al::isEqualString(rReq.mName, "Island09")) {
            return 8;
        }

        if (al::isEqualString(rReq.mName, "Island10")) {
            return 9;
        }

        if (al::isEqualString(rReq.mName, "Island11")) {
            return 10;
        }

        if (al::isEqualString(rReq.mName, "Island12")) {
            return 11;
        }

        return -1;
    }

    s32 BgmLineKeeper::checkPhaseBgm(const BgmPlayingRequest& rReq) {
        if (al::isEqualString(rReq.mName, "Phase1")) {
            return 0;
        }

        if (al::isEqualString(rReq.mName, "Phase2")) {
            return 1;
        }

        if (al::isEqualString(rReq.mName, "Phase3")) {
            return 2;
        }

        if (al::isEqualString(rReq.mName, "Phase4")) {
            return 3;
        }

        return -1;
    }

    void BgmLineKeeper::pauseActiveBgmLine(s32 idx) {
        if (mLines != nullptr) {
            mLines->getPtrAt(mCurrentLine)->pauseBgm(idx);
        }
    }

    void BgmLineKeeper::resumeActiveBgmLine(s32 idx) {
        if (mLines != nullptr) {
            mLines->getPtrAt(mCurrentLine)->resumeBgm(idx);
        }
    }

    BgmLine* BgmLineKeeper::getBgmLineByLineName(const char* pName) const {
        if (mLines != nullptr) {
            for (s32 i = 0; i < mLines->mNumPtrs; i++) {
                auto line = mLines->getPtrAt(i);

                if (al::isEqualString(line->getLineName(), pName)) {
                    return line;
                }
            }
        }

        return nullptr;
    }

    void BgmLineKeeper::resumeIslandBgm(s32 bgm) {
        auto line = getBgmLineByLineName("Island");

        if (line != nullptr) {
            line->resumeBgm(bgm);
        }
    }

    void BgmLineKeeper::pauseOceanBgm(s32 bgm) {
        auto line = getBgmLineByLineName("Main");

        if (line != nullptr) {
            line->pauseBgm(bgm);
        }
    }

    void BgmLineKeeper::resumeOceanBgm(s32 bgm) {
        auto line = getBgmLineByLineName("Main");

        if (line != nullptr) {
            line->resumeBgm(bgm);
        }
    }

    bool BgmLineKeeper::isPauseActiveBgmLine() {
        if (mLines != nullptr) {
            return mLines->getPtrAt(mCurrentLine)->isPause();
        }

        return false;
    }

    void BgmLineKeeper::stopAllBgmLine(s32 bgm) {
        if (mLines != nullptr && mLines->mNumPtrs != 0) {
            for (u32 i = 0; i < mLines->mNumPtrs; i++) {
                auto line = mLines->getPtrAt(i);
                line->stopAllBgmPlayer(bgm);
            }
        }
    }

    void BgmLineKeeper::changeSituation(const char* pSituation) {
        if (mLines != nullptr && mLines->mNumPtrs != 0) {
            for (u32 i = 0; i < mLines->mNumPtrs; i++) {
                auto line = mLines->getPtrAt(i);
                line->changeSituation(pSituation, false);
            }
        }
    }

    BgmLine* BgmLineKeeper::getActiveBgmLine() const {
        if (mLines != nullptr) {
            auto line = mLines->getPtrAt(mCurrentLine);
            return line->isRunning() ? line : nullptr;
        }

        return nullptr;
    }

};  // namespace al
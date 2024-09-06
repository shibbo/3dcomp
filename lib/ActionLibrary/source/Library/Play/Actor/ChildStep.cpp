#include "Library/Play/Actor/ChildStep.hpp"
#include "Library/Actor/ActorInitInfo.hpp"
#include "Util.hpp"

namespace al {
    NERVE_DECL(ChildStep, Wait);
    NERVE_IMPL(ChildStep, Wait);

    ChildStep::ChildStep(const char* pName, LiveActor* pActor) : LiveActor(pName), _148(pActor) {}

    void ChildStep::init(const ActorInitInfo& rInfo) {
        al::initActorPoseTQSV(this);
    }

    void ChildStep::exeWait() {
        al::multVecPose(al::getTransPtr(this), _148, _150);
    }

    void createChildStep(const ActorInitInfo& rInfo, LiveActor* pActor, bool isSyncClipping) {
        s32 linkNum = al::calcLinkChildNum(rInfo, "ChildStep");

        for (s32 i = 0; i < linkNum; i++) {
            auto step = new ChildStep("子供足場", pActor);
            al::initLinksActor(step, rInfo, "ChildStep", i);
            step->_142 = 1;

            if (isSyncClipping) {
                al::invalidateClipping(step);
                al::registerSubActorSyncClipping(pActor, step, false);
            }
        }
    }
};  // namespace al
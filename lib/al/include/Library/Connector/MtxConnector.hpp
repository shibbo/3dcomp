#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
class LiveActor;

class MtxConnector {
public:
    MtxConnector();
    MtxConnector(const sead::Quatf&, const sead::Vector3f&);

    virtual ~MtxConnector();
    virtual bool isConnecting() const;
    virtual void clear();

    void init(const sead::Matrix34f*, const sead::Matrix34f&);
    void init(const sead::Matrix34f*);

    void multMtx(sead::Matrix34f*, const sead::Matrix34f&);

private:
    sead::Matrix34f mBaseMtx = sead::Matrix34f::zero;
    const sead::Matrix34f* mParentMtx = nullptr;
    sead::Quatf mBaseQuat = sead::Quatf::unit;
    sead::Vector3f mBaseTrans = sead::Vector3f::zero;
};

static_assert(sizeof(MtxConnector) == 0x60);

MtxConnector* createMtxConnector(const LiveActor*);

void attachMtxConnectorToCollision(MtxConnector*, const LiveActor*, bool);

const sead::Vector3f& getConnectBaseTrans(const MtxConnector*);

void connectPoseTrans(LiveActor*, const MtxConnector*, const sead::Vector3f&);
}  // namespace al

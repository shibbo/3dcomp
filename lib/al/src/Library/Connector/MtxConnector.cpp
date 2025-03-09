#include "Library/Connector/MtxConnector.hpp"

namespace al {
MtxConnector::MtxConnector() = default;

MtxConnector::MtxConnector(const sead::Quatf& rQuad, const sead::Vector3f& rVec)
    : mBaseQuat(rQuad), mBaseTrans(rVec) {}

void MtxConnector::init(const sead::Matrix34f* parent, const sead::Matrix34f& base) {
    if (parent == nullptr) {
        clear();
        return;
    }
    mBaseMtx = base;
    mParentMtx = parent;
}
}  // namespace al

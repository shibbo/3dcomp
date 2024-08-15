#include "Project/Collision/PartsConnector.hpp"

namespace al {
    MtxConnector::MtxConnector() {
        _8 = sead::Matrix34f::ident;
        _38 = nullptr;
        _40 = sead::Quatf::unit;
        _50 = sead::Vector3f::zero;
    }

    MtxConnector::MtxConnector(const sead::Quatf& rQuad, const sead::Vector3f& rVec) {
        _8 = sead::Matrix34f::ident;
        _38 = nullptr;
        _40 = rQuad;
        _50 = rVec;
    }

    void MtxConnector::init(const sead::Matrix34f* a1, const sead::Matrix34f& a2) {
        if (a1 != nullptr) {
            _8 = a2;
            _38 = a1;
        } else {
            clear();
        }
    }
};  // namespace al
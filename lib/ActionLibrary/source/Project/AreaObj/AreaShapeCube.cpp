#include "Project/AreaObj/AreaShapeCube.hpp"
#include <limits>

namespace al {
    const f32 vals[2] = {500.0f, 1000.0f};

    AreaShapeCube::AreaShapeCube(OriginType originType) : AreaShape() {
        mOriginType = originType;
    }

    /*
    bool AreaShapeCube::calcLocalBoundingBox(sead::BoundBox3f* pBound) const {
        pBound->setMin(std::numeric_limits<f32>::max());
        pBound->setMax(-std::numeric_limits<f32>::max());
        pBound->setMin(-500.0f, 500.0f, -500.0f);
        pBound->setMax((mOriginType != Base) ? -500.0f : 0.0f, 500.0f, vals[mOriginType]);
        return true;
    }
    */

    bool AreaShapeCube::calcWorldBoundingBox(sead::BoundBox3f* pBound) const {
        pBound->setMin(std::numeric_limits<f32>::max());
        pBound->setMax(-std::numeric_limits<f32>::max());
        return true;
    }
};  // namespace al
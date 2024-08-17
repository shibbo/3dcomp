#include "Project/AreaObj/AreaObjDirector.hpp"
#include <limits>

namespace al {
    AreaObjDirectorGrid::AreaObjDirectorGrid(s32 a1, s32 a2)
        : _0(a1), _4(a2), _8(std::numeric_limits<f32>::max()),
          _14(std::numeric_limits<f32>::max()) {}
};  // namespace al
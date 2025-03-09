#pragma once

namespace al {
class NerveKeeper;

class IUseNerve {
public:
    virtual NerveKeeper* getNerveKeeper() const = 0;
};
}  // namespace al

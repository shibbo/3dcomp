#pragma once

#include "Project/AreaObj/AreaObj.hpp"

namespace al {
    class SePlayArea : public AreaObj {
    public:
        SePlayArea(const char*);

        virtual void init(const AreaInitInfo&);

        const char* mPlayName = nullptr;  // 0x88
    };
};  // namespace al
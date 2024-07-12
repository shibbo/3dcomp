#pragma once

namespace sead {
    template<typename T>
    class Matrix34 {
    public:
        T mMtx[3][4];
    };

    typedef Matrix34<float> Matrix34f;
};
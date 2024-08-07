#pragma once

namespace sead {
    template<typename T>
    class BaseMtx34 {
    public:
        T mMtx[3][4];
    };

    template<typename T>
    class Matrix34 : public BaseMtx34<T> {
    public:
        
    };

    typedef Matrix34<float> Matrix34f;
};
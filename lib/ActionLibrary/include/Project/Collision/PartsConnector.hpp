#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
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

        sead::Matrix34f _8;
        const sead::Matrix34f* _38;
        sead::Quatf _40;
        sead::Vector3f _50;
    };
};  // namespace al
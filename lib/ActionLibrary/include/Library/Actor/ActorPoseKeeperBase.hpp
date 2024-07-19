#pragma once

#include <types.hpp>
#include <math/seadMatrix.hpp>
#include <math/seadQuat.hpp>
#include <math/seadVector.hpp>

namespace al {
    class ActorPoseKeeperBase {
    public:
        ActorPoseKeeperBase();

        virtual const sead::Vector3f& getRotate() const;
        virtual const sead::Vector3f& getScale() const;
        virtual const sead::Vector3f& getVelocity() const;
        virtual const sead::Vector3f& getFront() const;
        virtual const sead::Quatf& getQuat() const;
        virtual const sead::Vector3f& getGravity() const;
        virtual const sead::Matrix34f& getMtx() const;
        virtual sead::Vector3f* getRotatePtr();
        virtual sead::Vector3f* getScalePtr();
        virtual sead::Vector3f* getVelocityPtr();
        virtual sead::Vector3f* getFrontPtr();
        virtual sead::Quatf* getQuatPtr();
        virtual sead::Vector3f* getGravityPtr();
        virtual sead::Matrix34f* getMtxPtr();
        virtual void updatePoseRotate(const sead::Vector3f &) = 0;
        virtual void updatePoseQuat(const sead::Quatf &) = 0;
        virtual void updatePoseMtx(const sead::Matrix34f *) = 0;
        virtual void copyPose(const ActorPoseKeeperBase *);
        virtual void calcBaseMtx(sead::Matrix34f *) const = 0;

        sead::Vector3f mTranslation;            // 0x08
    };
};
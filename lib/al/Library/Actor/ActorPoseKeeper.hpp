#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>
#include <seadTypes.h>

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
        virtual void updatePoseRotate(const sead::Vector3f&) = 0;
        virtual void updatePoseQuat(const sead::Quatf&) = 0;
        virtual void updatePoseMtx(const sead::Matrix34f*) = 0;
        virtual void copyPose(const ActorPoseKeeperBase*);
        virtual void calcBaseMtx(sead::Matrix34f*) const = 0;

        sead::Vector3f mTranslation{0, 0, 0};  // 0x08
    };

    class ActorPoseKeeperTRSV : public ActorPoseKeeperBase {
    public:
        ActorPoseKeeperTRSV();

        virtual const sead::Vector3f& getRotate() const;
        virtual const sead::Vector3f& getScale() const;
        virtual const sead::Vector3f& getVelocity() const;
        virtual sead::Vector3f* getRotatePtr();
        virtual sead::Vector3f* getScalePtr();
        virtual sead::Vector3f* getVelocityPtr();

        sead::Vector3f mRotate = {0.0, 0.0, 0.0};
        sead::Vector3f mScale = {1.0, 1.0, 1.0};
        sead::Vector3f mVelocity = {0.0, 0.0, 0.0};
    };

    class ActorPoseKeeperTRMSV : public ActorPoseKeeperBase {
    public:
        ActorPoseKeeperTRMSV();

        sead::Vector3f mRotate = {0.0, 0.0, 0.0};
        sead::Vector3f mScale = {1.0, 1.0, 1.0};
        sead::Vector3f mVelocity = {0.0, 0.0, 0.0};
        sead::Matrix34f mMtx;
    };

    class ActorPoseKeeperTFSV : public ActorPoseKeeperBase {
    public:
        ActorPoseKeeperTFSV();

        sead::Vector3f mFront = sead::Vector3f::ez;
        sead::Vector3f mScale = {1.0, 1.0, 1.0};
        sead::Vector3f mVelocity = {0.0, 0.0, 0.0};
    };

    class ActorPoseKeeperTFGSV : public ActorPoseKeeperTFSV {
    public:
        ActorPoseKeeperTFGSV();

        sead::Vector3f mGravity = {0.0, -1.0, 0.0};
    };

    class ActorPoseKeeperTQSV : public ActorPoseKeeperBase {
    public:
        ActorPoseKeeperTQSV();

        sead::Quatf mQuat = sead::Quatf::unit;
        sead::Vector3f mScale = {1.0, 1.0, 1.0};
        sead::Vector3f mVelocity = {0.0, 0.0, 0.0};
    };
};  // namespace al
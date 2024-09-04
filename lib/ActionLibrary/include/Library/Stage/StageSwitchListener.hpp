#pragma once

#include "Library/Thread/Functor.hpp"

namespace al {
    class StageSwitchListener {
    public:
        virtual void listenOn() = 0;
        virtual void listenOff() = 0;
    };

    class StageSwitchFunctorListener : public StageSwitchListener {
    public:
        StageSwitchFunctorListener();

        virtual void listenOn();
        virtual void listenOff();

        void setOnFunctor(const FunctorBase&);
        void setOffFunctor(const FunctorBase&);

        FunctorBase* mOnFunctor = nullptr;   // 0x08
        FunctorBase* mOffFunctor = nullptr;  // 0x10
    };
};  // namespace al
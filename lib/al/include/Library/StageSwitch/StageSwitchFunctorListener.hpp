#pragma once

namespace al {
class FunctorBase;

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

    FunctorBase* mOnFunctor = nullptr;
    FunctorBase* mOffFunctor = nullptr;
};
}  // namespace al

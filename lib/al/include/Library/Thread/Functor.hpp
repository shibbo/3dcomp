#pragma once

namespace al {
class FunctorBase {
public:
    inline FunctorBase() = default;
    inline FunctorBase(const FunctorBase&) = default;

    virtual void operator()() const = 0;
    virtual FunctorBase* clone() const = 0;
};

template <class T, class F>
class FunctorV0M : public FunctorBase {
public:
    inline FunctorV0M() = default;

    inline FunctorV0M(T obj, F func) {
        mObjPtr = obj;
        mFunc = func;
    }

    inline FunctorV0M(const FunctorV0M<T, F>&) = default;

    void operator()() const override { (mObjPtr->*mFunc)(); }

    FunctorV0M<T, F>* clone() const override { return new FunctorV0M<T, F>(*this); }

    T mObjPtr = nullptr;
    F mFunc = nullptr;
};

template <class T, class F, class Arg>
class FunctorV1M : public FunctorBase {
public:
    inline FunctorV1M() = default;

    inline FunctorV1M(T obj, F func, Arg arg) {
        mObjPtr = obj;
        mFunc = func;
        mArg = arg;
    }

    inline FunctorV1M(const FunctorV1M<T, F, Arg>&) = default;

    void operator()() const override { (mObjPtr->*mFunc)(mArg); }

    FunctorV1M<T, F, Arg>* clone() const override { return new FunctorV1M<T, F, Arg>(*this); }

    T mObjPtr = nullptr;
    F mFunc = nullptr;
    Arg mArg = nullptr;
};

template <class T>
static FunctorV0M<T*, void (T::*)()> Functor(T* a1, void (T::*a2)()) {
    return FunctorV0M<T*, void (T::*)()>(a1, a2);
}
}  // namespace al

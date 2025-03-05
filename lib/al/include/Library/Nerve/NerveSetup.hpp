#pragma once

#include <prim/seadStorageFor.h>
#include "Library/Nerve/Nerve.hpp"
#include "Library/Nerve/NerveAction.hpp"
#include "Project/Base/Macro.hpp"

#define NERVE_DECL(Class, Action)                                                                                                                    \
    class Class##Nrv##Action : public al::Nerve {                                                                                                    \
    public:                                                                                                                                          \
        void execute(al::NerveKeeper* pKeeper) const override {                                                                                      \
            (pKeeper->getParent<Class>())->exe##Action();                                                                                            \
        }                                                                                                                                            \
    };

#define NERVE_IMPL(Class, Action) Class##Nrv##Action Action;

#define NERVE_HOST_TYPE_IMPL(Class, Action) NERVE_HOST_TYPE_IMPL_(Class, Action, Action)

#define NERVE_MAKE(Class, Action) Class##Nrv##Action Action;

#define NERVES_MAKE_STRUCT(Class, ...)                                                                                                               \
    struct {                                                                                                                                         \
        FOR_EACH(NERVE_MAKE, Class, __VA_ARGS__)                                                                                                     \
    } Nrv##Class;

#define NERVE_ACTION_IMPL_(Class, Action, ActionFunc)                                                                                                \
    class Class##Nrv##Action : public al::NerveAction {                                                                                              \
    public:                                                                                                                                          \
        void execute(al::NerveKeeper* keeper) const override {                                                                                       \
            (keeper->getParent<Class>())->exe##ActionFunc();                                                                                         \
        }                                                                                                                                            \
                                                                                                                                                     \
        const char* getActionName() const override {                                                                                                 \
            return #Action;                                                                                                                          \
        }                                                                                                                                            \
    };

#define NERVE_ACTION_IMPL(Class, Action) NERVE_ACTION_IMPL_(Class, Action, Action)
#define NERVE_ACTION_MAKE(Class, Action) sead::StorageFor<Class##Nrv##Action> Action;
#define NERVE_ACTION_CONSTRUCT(Class, Action) Action.constructDefault();

#define NERVE_ACTIONS_MAKE_STRUCT(Class, ...)                                                                                                        \
    struct NrvStruct##Class {                                                                                                                        \
        FOR_EACH(NERVE_ACTION_MAKE, Class, __VA_ARGS__)                                                                                              \
                                                                                                                                                     \
        alNerveFunction::NerveActionCollector mCollector;                                                                                            \
                                                                                                                                                     \
        NrvStruct##Class() {                                                                                                                         \
            FOR_EACH(NERVE_ACTION_CONSTRUCT, Class, __VA_ARGS__)                                                                                     \
        }                                                                                                                                            \
    } Nrv##Class;
#pragma once

namespace al {
    class IUseExecutor {
    public:
        virtual void execute() = 0;
        virtual void draw() const;
        virtual const char* executorName() const = 0;
        virtual void executeOnThread() = 0;
    };
};
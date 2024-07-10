#pragma once

namespace sead {
    class IDisposer;

    class Heap {
    public:
        void appendDisposer_(IDisposer *);
        void removeDisposer_(IDisposer *);
    };
};
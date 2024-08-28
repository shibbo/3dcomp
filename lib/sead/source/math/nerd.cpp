#include "math/nerd.hpp"

namespace nerd {
    static u8 sUseFastSqrte;

    void setUseFastsqrte(bool use) {
        sUseFastSqrte = use;
    }
}; 
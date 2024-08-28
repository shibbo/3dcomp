#include "random/seadRandom.hpp"
#include "os/os_TickApi.hpp"

namespace sead {

    void Random::init() {
        init(nn::os::GetSystemTick().GetInt64Value());
    }

    void Random::init(u32 seed) {
        const u32 m = 0x6C078965;
        mX = m * (seed ^ (seed >> 30)) + 1;
        mY = m * (mX ^ (mX >> 30)) + 2;
        mZ = m * (mY ^ (mY >> 30)) + 3;
        mW = m * (mZ ^ (mZ >> 30)) + 4;
    }

    void Random::init(u32 x, u32 y, u32 z, u32 w) {
        if ((x | y | z | w) == 0) {
            w = 0x48077044;
            z = 0x714ACB41;
            y = 0x6C078967;
            x = 1;
        }

        mX = x;
        mY = y;
        mZ = z;
        mW = w;
    }

    u32 Random::getU32() {
        u32 x = mX ^ (mX << 11);
        mX = mY;
        mY = mZ;
        mZ = mW;
        mW = mW ^ (mW >> 19) ^ x ^ (x >> 8);
        return mW;
    }

    u64 Random::getU64() {
        return u64(getU32()) << 32 | getU32();
    }

    void Random::getContext(u32* x, u32* y, u32* z, u32* w) const {
        *x = mX;
        *y = mY;
        *z = mZ;
        *w = mW;
    }

};  // namespace sead
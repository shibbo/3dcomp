#include "Library/Math/MathUtil.hpp"
#include <math/nerd.hpp>

namespace al {
    bool isNear(f32 a2, f32 a3, f32 a4) {
        f32 v3 = a2 - a3;

        if (0.0f >= v3) {
            v3 = -v3;
        }

        f32 v4 = -a4;
        if (a4 > 0.0f) {
            v4 = a4;
        }

        return v3 < v4;
    }

    bool isInRange(f32 a1, f32 a2, f32 a3) {
        if (a3 < a2) {
            if (a1 < a3 || a2 < a1)
                return false;
            else
                return true;
        } else {
            if (a1 < a2 || a3 < a1)
                return false;
            else
                return true;
        }
    }

    void normalize(sead::Vector2f* pVec) {
        f32 sqrt = nerd::sqrt(pVec->dot());

        if (sqrt > 0.0f) {
            f32 inv = 1.0f / sqrt;
            pVec->scale(inv);
        }
    }

    void normalize(sead::Vector3f* pVec) {
        f32 sqrt = nerd::sqrt(pVec->dot());

        if (sqrt > 0.0f) {
            f32 inv = 1.0f / sqrt;
            pVec->scale(inv);
        }
    }

    /* seems to just be some scheduling issues */
    void normalize(sead::Matrix33f* pMtx) {
        f32 a00 = pMtx->m[0][0];
        f32 a01 = pMtx->m[0][1];
        f32 a10 = pMtx->m[1][0];
        f32 a11 = pMtx->m[1][1];
        f32 a20 = pMtx->m[2][0];
        f32 a21 = pMtx->m[2][1];
        f32 a02 = pMtx->m[0][2];
        f32 a12 = pMtx->m[1][2];
        f32 a22 = pMtx->m[2][2];

        f32 v10 = nerd::sqrt((a00 * a00) + (a10 * a10) + (a20 * a20));
        if (v10 > 0.0f) {
            f32 v11 = 1.0f / v10;
            a00 *= v11;
            a10 *= v11;
            a20 *= v11;
        }

        f32 v17 = a20;
        f32 v12 = nerd::sqrt((a01 * a01) + (a11 * a11) + (a21 * a21));
        if (v12 > 0.0f) {
            f32 v13 = 1.0f / v12;
            a01 *= v13;
            a11 *= v13;
            a21 *= v13;
        }
        f32 v14 = a02;
        f32 v15 = nerd::sqrt((v14 * v14) + (a12 * a12) + (a22 * a22));

        if (v15 > 0.0f) {
            f32 v16 = 1.0f / v15;
            v14 *= v16;
            a12 *= v16;
            a22 *= v16;
        }

        pMtx->m[0][0] = a00;
        pMtx->m[0][1] = a01;
        pMtx->m[1][0] = a10;
        pMtx->m[1][1] = a11;
        pMtx->m[2][0] = v17;
        pMtx->m[2][1] = a21;
        pMtx->m[0][2] = v14;
        pMtx->m[1][2] = a12;
        pMtx->m[2][2] = a22;
    }

    void normalize(sead::Matrix34f* pMtx) {
        f32 a00 = pMtx->m[0][0];
        f32 a01 = pMtx->m[0][1];
        f32 a10 = pMtx->m[1][0];
        f32 a11 = pMtx->m[1][1];
        f32 a20 = pMtx->m[2][0];
        f32 a21 = pMtx->m[2][1];
        f32 a02 = pMtx->m[0][2];
        f32 a12 = pMtx->m[1][2];
        f32 a22 = pMtx->m[2][2];
        f32 v10 = nerd::sqrt((a00 * a00) + (a10 * a10) + (a20 * a20));

        if (v10 > 0.0f) {
            f32 inv = 1.0f / v10;
            a00 *= inv;
            a10 *= inv;
            a20 *= inv;
        }
        f32 v17 = a20;
        f32 v12 = nerd::sqrt((a01 * a01) + (a11 * a11) + (a21 * a21));

        if (v12 > 0.0f) {
            f32 v13 = 1.0f / v12;
            a01 *= v13;
            a11 *= v13;
            a21 *= v13;
        }

        f32 v14 = a02;
        f32 v15 = nerd::sqrt((v14 * v14) + (a12 * a12) + (a22 * a22));

        if (v15 > 0.0f) {
            f32 v16 = 1.0f / v15;
            v14 *= v16;
            a12 *= v16;
            a22 *= v16;
        }

        pMtx->m[0][0] = a00;
        pMtx->m[0][1] = a01;
        pMtx->m[1][0] = a10;
        pMtx->m[1][1] = a11;
        pMtx->m[2][0] = v17;
        pMtx->m[2][1] = a21;
        pMtx->m[0][2] = v14;
        pMtx->m[1][2] = a12;
        pMtx->m[2][2] = a22;
    }

    void normalize(sead::Vector2f* pOut, const sead::Vector2f& rVec) {
        f32 x = rVec.x;
        pOut->x = x;
        f32 dot = (rVec.y * rVec.y) + (x * x);
        pOut->y = rVec.y;
        f32 sqrt = nerd::sqrt(dot);

        if (sqrt > 0.0f) {
            f32 inv_sqrt = 1.0f / sqrt;
            pOut->x *= inv_sqrt;
            pOut->y *= inv_sqrt;
        }
    }

};  // namespace al
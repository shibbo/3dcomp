#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {

bool isNearZero(const sead::Vector2f&, f32);
bool tryCalcAngleDegree(f32*, const sead::Vector3f&, const sead::Vector3f&);
bool isNearZero(const sead::Vector3f&, f32);
f32 calcAngleOnPlaneDegree(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&);

void normalize(sead::Vector2f*, const sead::Vector2f&);
void normalizeorZero(sead::Vector2f*);

void normalize(sead::Vector3f*, const sead::Vector3f&);

void normalizeOrZero(sead::Vector3f*, const sead::Vector3f&);
void normalizeOrZero(sead::Vector3f*);

bool isNear(f32, f32, f32);
bool isNear(const sead::Vector2f&, const sead::Vector2f&, f32);
bool isNear(const sead::Vector3f&, const sead::Vector3f&, f32);

bool isNearZero(f32, f32);
bool isNearZero(const sead::Matrix34f&, f32);
bool isNearZeroOrLess(f32, f32);
bool isExistNearZeroVal(const sead::Vector3f&, f32);
bool isNormalize(const sead::Vector3f&, f32);
bool isNormalize(const sead::Matrix34f&);
bool isParallelDirection(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isReverseDirection(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isNearDirection(const sead::Vector3f&, const sead::Vector3f&, f32);
bool isInRange(f32, f32, f32);
void normalize(sead::Vector2f*);
void normalize(sead::Vector3f*);
void normalize(sead::Matrix33f*);
void normalize(sead::Matrix34f*);

void normalizeOrZero(sead::Vector3f*);
}  // namespace al

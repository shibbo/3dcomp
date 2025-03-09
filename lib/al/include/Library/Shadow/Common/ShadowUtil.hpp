#pragma once

namespace al {
class LiveActor;

bool isExistShadow(LiveActor*);
bool isExistShadow(LiveActor*, const char*);
bool isHideShadow(const LiveActor*);
void hideShadow(LiveActor*);
void showShadow(LiveActor*);
void hideShadowDepth(LiveActor*);
void showShadowDepth(LiveActor*);
}  // namespace al

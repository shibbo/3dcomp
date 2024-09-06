#pragma once

namespace al {
    class AreaObj;

    bool tryGetAreaObjStringArg(const char**, const AreaObj*, const char*);

    bool tryGetAreaObjArg(bool*, const AreaObj*, const char*);
};  // namespace al
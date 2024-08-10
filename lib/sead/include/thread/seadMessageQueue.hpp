#pragma once

namespace sead {
    class MessageQueue {
    public:
        enum BlockType {
            Blocking        = 0,
            NonBlocking     = 1,
        };

        MessageQueue();

    };
};
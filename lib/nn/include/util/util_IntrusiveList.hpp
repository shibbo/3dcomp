#pragma once

#include <cstdio>

namespace nn {
    namespace util {
        class IntrusiveListNode {
        public:
            IntrusiveListNode() {
                mPrev = this;
                mNext = this;
            }

        private:
            IntrusiveListNode* mPrev;  // 0x00
            IntrusiveListNode* mNext;  // 0x08
        };

        namespace detail {
            class IntrusiveistImplementation {
            public:
                IntrusiveListNode mRoot;
            };
        };  // namespace detail

        template <class T, class Traits>
        class IntrusiveList {
        public:
            detail::IntrusiveistImplementation mImplementation;
        };

        template <class Holder, IntrusiveListNode Holder::*Member, class T = Holder,
                  size_t IsComplete = sizeof(Holder)>
        class IntrusiveListMemberNodeTraits {};
    };  // namespace util
};  // namespace nn
#include "container/seadTreeNode.hpp"

namespace sead {
    TreeNode::TreeNode() {
        clearLinks();
    }

    void TreeNode::clearLinks() {
        mNext = nullptr;
        mPrev = nullptr;
        mParent = nullptr;
        mChild = nullptr;
    }

    void TreeNode::pushBackChild(TreeNode *pNode) {
        pNode->detatchSubTree();

        if (mChild != nullptr) {
            TreeNode* prev = mChild->mPrev;
            prev->mNext = pNode;
            pNode->mPrev = prev;
            pNode->mParent = prev->mParent;
            mChild->mPrev = pNode;
        }
        else {
            mChild = pNode;
            pNode->mParent = this;
            pNode->mPrev = pNode;
        }
    }

    void TreeNode::detatchSubTree() {
        if (mParent != nullptr && mParent->mChild == this) {
            mParent->mChild = mNext;

            if (mNext != nullptr) {
                mNext->mPrev = mPrev;
                mNext = nullptr;
            }
        }
        else {
            if (mPrev != nullptr) {
                mPrev->mNext = mNext;
            }

            if (mNext != nullptr) {
                mNext->mPrev = mPrev;
                mNext = nullptr;
            }
            else if (mParent != nullptr) {
                mParent->mChild->mPrev = mPrev;
            }
        }

        mPrev = nullptr;
        mParent = nullptr;
    }

    void TreeNode::pushBackSibling(TreeNode *pNode) {
        pNode->detatchSubTree();

        TreeNode* next;

        if (mParent != nullptr && mParent->mChild != nullptr) {
            next = mParent->mChild->mPrev;
            mParent->mChild->mPrev = pNode;
        }
        else {
            next = this;
            while (next->mNext != nullptr) {
                next = next->mNext;
            }
        }

        next->mNext = pNode;
        pNode->mPrev = next;
        pNode->mParent = next->mParent;
    }

    // sead::TreeNode::pushFrontChild
    // sead::TreeNode::insertBeforeSelf
    // sead::TreeNode::insertAfterSelf
    // sead::TreeNode::detachAll
    // sead::TreeNode::clearChildLinksRecursively_
    // sead::TreeNode::findRoot
    // sead::TreeNode::findRoot(void)const
    // sead::TreeNode::countChildren
};
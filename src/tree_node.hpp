#pragma once

template <typename T>
struct TreeNode {
    T* value;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    explicit TreeNode(T* value) :
        value(value),
        left(nullptr),
        right(nullptr)
    {}
};
/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

#include<bits/stdc++.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool helper(TreeNode* left,TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        
        return (left->val == right->val) && helper(left->right,right->left) && helper(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = helper(root->left,root->right);
        return ans;
    }
};
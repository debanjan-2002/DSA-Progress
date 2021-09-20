/*
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
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
    bool helper(TreeNode* root){
        if(root == NULL)
            return true;
        
        bool check1 = helper(root->left);
        bool check2 = helper(root->right);
        
        if(root->left != NULL && root->val != root->left->val)
            check1 = false;
        if(root->right != NULL && root->val != root->right->val)
            check2 = false;
        
        if(check1 && check2)
            return true;
        else
            return false;
    }
    bool isUnivalTree(TreeNode* root) {
        bool ans = helper(root);
        return ans;
    }
};
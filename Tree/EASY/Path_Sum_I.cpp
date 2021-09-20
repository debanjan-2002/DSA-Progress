/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
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
    bool path(TreeNode* root,int sum){
        if(root == NULL)
            return false;
        
        if(root->left == NULL && root->right == NULL && sum - root->val == 0)
            return true;
        return path(root->left,sum-root->val) || path(root->right,sum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = path(root,targetSum);
        return ans;
    }
};
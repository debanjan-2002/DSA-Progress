/*
Given the root of a binary tree, return the sum of all left leaves.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = 0;
        if(root->left != NULL){
            if(root->left->left == NULL && root->left->right == NULL)
                ans += root->left->val;
            else
                ans += sumOfLeftLeaves(root->left);
        }
        ans += sumOfLeftLeaves(root->right);
        return ans;
    }
};
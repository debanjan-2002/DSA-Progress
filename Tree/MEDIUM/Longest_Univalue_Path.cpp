/*
Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.
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
    int ans = 0;
    int max_len(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int ans1 = max_len(root->left);
        int ans2 = max_len(root->right);
        
        if(root->left != NULL && root->left->val == root->val)
            ans1++;
        else
            ans1 = 0;
        if(root->right != NULL && root->right->val == root->val)
            ans2++;
        else
            ans2 = 0;
        
        ans = max(ans,ans1 + ans2);
        return max(ans1,ans2);
            
    }
    int longestUnivaluePath(TreeNode* root) {
        max_len(root);
        return ans;
    }
};
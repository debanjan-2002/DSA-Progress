/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.
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
    int res = INT_MIN;
    int maxSum(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int left_max = max(maxSum(root->left),0);
        int right_max = max(maxSum(root->right),0);
        
        int curr_max = root->val + left_max + right_max;
        res = max(res,curr_max);
        
        return root->val + max(left_max,right_max);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return res;
    }
};
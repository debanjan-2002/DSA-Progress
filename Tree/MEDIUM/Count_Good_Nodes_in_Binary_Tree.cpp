/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
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
    int good(TreeNode* root,int maxi){
        if(root == NULL)
            return 0;
        maxi = max(maxi,root->val);
        int ans1 = good(root->left,maxi);
        int ans2 = good(root->right,maxi);
        
        if(root->val >= maxi)
            return 1 + ans1 + ans2;
        else
            return ans1 + ans2;
    }
    int goodNodes(TreeNode* root) {
        int ans = good(root,INT_MIN);
        return ans;
    }
};
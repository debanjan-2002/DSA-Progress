/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
    vector <vector<int>> ans;
    void path(TreeNode* root,int sum,vector <int>& v){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL && sum - root->val == 0){
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        path(root->left,sum - root->val,v);
        path(root->right,sum - root->val,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> v;
        path(root,targetSum,v);
        return ans;
    }
};
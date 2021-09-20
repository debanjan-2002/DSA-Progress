/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
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
    void path(TreeNode* root,int curr,unordered_map<int,int>& m,int targetSum){
        if(root == NULL)
            return;
        curr += root->val;
        if(m.find(curr - targetSum) != m.end())
            ans += m[curr - targetSum];

        m[curr]++;
        
        path(root->left,curr,m,targetSum);
        path(root->right,curr,m,targetSum);
        
        m[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map <int,int> m;
        m.insert({0,1});
        path(root,0,m,targetSum);
        return ans;
    }
};
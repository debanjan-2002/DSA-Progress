/*
Given the root of a binary tree, return the sum of values of its deepest leaves.
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
    int deepestLeavesSum(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int count = q.size();
            res = 0;
            for(int i=0; i<count; i++){
                TreeNode *curr = q.front();
                q.pop();
                res += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return res;
    }
};
/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)
            return {};
        vector <int> ans;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            int maxi = INT_MIN;
            for(int i=0; i<count; i++){
                TreeNode *curr = q.front();
                q.pop();
                maxi = max(maxi,curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
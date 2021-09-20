/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        stack <TreeNode*> s1;
        stack <TreeNode*> s2;
        s1.push(root);
        vector <vector<int>> ans;
        while(!s1.empty() || !s2.empty()){
            vector <int> temp;
            while(!s1.empty()){
                TreeNode *curr = s1.top();
                s1.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    s2.push(curr->left);
                if(curr->right)
                    s2.push(curr->right);
            }
            if(!temp.empty())
                ans.push_back(temp);
            temp.clear();
            while(!s2.empty()){
                TreeNode *curr = s2.top();
                s2.pop();
                temp.push_back(curr->val);
                if(curr->right)
                    s1.push(curr->right);
                if(curr->left)
                    s1.push(curr->left);
            }
            if(!temp.empty())
                ans.push_back(temp);
        }
        return ans;
    }
};
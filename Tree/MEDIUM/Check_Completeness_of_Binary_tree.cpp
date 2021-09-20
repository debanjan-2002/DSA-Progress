/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    bool isCompleteTree(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        bool gap = false;
        while(!q.empty()){
            int count = q.size();
            
            for(int i=0; i<count; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left == NULL && curr->right != NULL)
                    return false;
                if((curr->left || curr->right) && gap)
                    return false;
                if(curr->left)
                    q.push(curr->left);
                else
                    gap = true;
                if(curr->right)
                    q.push(curr->right);
                else
                    gap = true;
            }
        }
        return true;
    }
};
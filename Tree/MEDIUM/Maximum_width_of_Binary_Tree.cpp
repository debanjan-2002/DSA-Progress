/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue <pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int res = 0;
        while(!q.empty()){
            int count = q.size();
            unsigned long long curr_min = q.front().second;
            unsigned long long curr_max = 0;
            for(int i=0; i<count; i++){
                pair<TreeNode*,unsigned long long> temp = q.front();
                q.pop();
                curr_max = temp.second;
                if(temp.first->left)
                    q.push({temp.first->left,2*temp.second + 1});
                if(temp.first->right)
                    q.push({temp.first->right,2*temp.second + 2});
            }
            res = max(res,int(curr_max-curr_min+1));
        }
        return res;
    }
};
/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        int level = 0;
        int res = INT_MIN;
        int ans = 0;
        while(!q.empty()){
            int count = q.size();
            int sum = 0;
            for(int i=0; i<count; i++){
                TreeNode *curr = q.front();
                q.pop();
                sum += (curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            level++;
            if(sum > res){
                ans = max(ans,level);
                res = sum;
            }
        }
        return ans;
    }
};
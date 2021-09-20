/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.
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
    void merge(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return;
        if(root1 == NULL || root2 == NULL)
            return;
        
        root1->val += root2->val;
        merge(root1->left,root2->left);
        if(root1->left == NULL && root2->left != NULL){
            TreeNode* curr = root2->left;
            root1->left = curr;
        }
        merge(root1->right,root2->right);
        if(root1->right == NULL && root2->right != NULL){
            TreeNode* curr = root2->right;
            root1->right = curr;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return NULL;
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
        merge(root1,root2);
        return root1;
    }
};
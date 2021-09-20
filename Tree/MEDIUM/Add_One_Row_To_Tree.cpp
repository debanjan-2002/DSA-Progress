/*
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
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
    void add(TreeNode* root,int curr,int depth,int val){
        if(root == NULL)
            return;
        if(curr == depth - 1){
            TreeNode* temp1 = new TreeNode(val);
            TreeNode* temp2 = new TreeNode(val);
            if(root->left != NULL){
                TreeNode* next = root->left;
                root->left = temp1;
                temp1->left = next;
            }
            else{
                root->left  = temp1;  
            }
            if(root->right != NULL){
                TreeNode* next = root->right;
                root->right = temp2;
                temp2->right = next;
            }
            else{
                root->right  = temp2;  
            }
            return;
        }
        add(root->left,curr + 1,depth,val);
        add(root->right,curr + 1,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newHead = new TreeNode(val);
            newHead->left = root;
            return newHead;
        }
        add(root,1,depth,val);
        return root;
    }
};
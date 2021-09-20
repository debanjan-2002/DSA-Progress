/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int left_Height = 1;
        int right_Height = 1;
        
        //Left extreme height
        while(l != NULL){
            l = l->left;
            left_Height++;
        }
        //Right extreme height
        while(r != NULL){
            r = r->right;
            right_Height++;
        }
        if(left_Height == right_Height)
            return pow(2,left_Height) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
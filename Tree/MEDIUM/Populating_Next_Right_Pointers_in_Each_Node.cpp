/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/
#include<bits/stdc++.h>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void helper(Node* root){
        //Base Case
        if(root == NULL)
            return;
        
        if(root->left != NULL)
            root->left->next = root->right;
        if(root->right != NULL && root->next != NULL)
            root->right->next = root->next->left;
        
        //Recursive Case
        helper(root->left);
        helper(root->right);
    }
    Node* connect(Node* root) {
        helper(root);
        return root;
    }
};
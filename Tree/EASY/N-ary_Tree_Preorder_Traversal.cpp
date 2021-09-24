/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value
*/
#include<bits/stdc++.h>
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector <int> ans;
    void traversal(Node* root){
        if(root == NULL)
            return;
        vector <Node*> temp = root->children;
        ans.push_back(root->val);
        for(int i=0; i<temp.size(); i++){
            traversal(temp[i]);
        }
    }
    vector<int> preorder(Node* root) {
        traversal(root);
        return ans;
    }
};
/*
Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> ans;
        queue <Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int count = q.size();
            vector <int> sub;
            for(int i=0; i<count; i++){
                Node* temp = q.front();
                q.pop();
                vector <Node*> curr = temp->children;
                for(int j=0; j<curr.size(); j++){
                    if(curr[j] != NULL)
                        q.push(curr[j]);
                }
                sub.push_back(temp->val);
            }
            ans.push_back(sub);
            sub.clear();
        }
        return ans;
    }
};
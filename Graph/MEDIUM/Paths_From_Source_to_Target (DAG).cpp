/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void totalPaths(vector<vector<int>>& graph,vector<int>& curr,int s,int target){
        if(s == target){
            curr.push_back(s);
            ans.push_back(curr);
            return;
        }
        curr.push_back(s);
        for(int v:graph[s]){
            totalPaths(graph,curr,v,target);
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <int> curr;
        totalPaths(graph,curr,0,graph.size() - 1);
        return ans;
    }
};
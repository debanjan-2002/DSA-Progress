/*
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

-There are no self-edges (graph[u] does not contain u).
-There are no parallel edges (graph[u] does not contain duplicate values).
-If v is in graph[u], then u is in graph[v] (the graph is undirected).
-The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
-A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int curr,int src){

        color[src] = curr;
        for(int &v: graph[src]){
            if(color[v] == -curr)
                continue;
            if(color[v] == curr || !dfs(graph,color,-curr,v)){
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color(n,0);
        for(int i=0; i<n; i++){
            if(color[i] == 0 && !dfs(graph,color,1,i))
                return false;
        }
        return true;
    }
};
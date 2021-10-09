/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex start to vertex end.

Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void buildGraph(vector <int> adj[],vector<vector<int>>& edges){
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    void dfs(vector <int> adj[],int source,int target,bool visited[]){
        visited[source] = true;
        
        for(int v:adj[source]){
            if(visited[v] == false){
                dfs(adj,v,target,visited);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector <int> adj[n];
        buildGraph(adj,edges);
        bool visited[n];
        for(int i=0; i<n; i++)
            visited[i] = false;
        dfs(adj,start,end,visited);
        return visited[end];
    }
};

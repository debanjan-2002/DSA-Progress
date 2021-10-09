/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,int vertex,vector <bool>& visited){
        queue <int> q;
        q.push(vertex);
        visited[vertex] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0; i<isConnected.size(); i++){
                if(visited[i] == false && isConnected[u][i] == 1){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        int ans = 0;
        vector <bool> visited(n,false);
        for(int i=0; i<isConnected.size(); i++){
            if(visited[i] == false){
                ans++;
                bfs(isConnected,i,visited);
            }
        }
        return ans;
    }
};
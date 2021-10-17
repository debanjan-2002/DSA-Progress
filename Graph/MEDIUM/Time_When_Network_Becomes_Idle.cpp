/*
There is a network of n servers, labeled from 0 to n - 1. You are given a 2D integer array edges, where edges[i] = [ui, vi] indicates there is a message channel between servers ui and vi, and they can pass any number of messages to each other directly in one second. You are also given a 0-indexed integer array patience of length n.

All servers are connected, i.e., a message can be passed from one server to any other server(s) directly or indirectly through the message channels.

The server labeled 0 is the master server. The rest are data servers. Each data server needs to send its message to the master server for processing and wait for a reply. Messages move between servers optimally, so every message takes the least amount of time to arrive at the master server. The master server will process all newly arrived messages instantly and send a reply to the originating server via the reversed path the message had gone through.

At the beginning of second 0, each data server sends its message to be processed. Starting from second 1, at the beginning of every second, each data server will check if it has received a reply to the message it sent (including any newly arrived replies) from the master server:

If it has not, it will resend the message periodically. The data server i will resend the message every patience[i] second(s), i.e., the data server i will resend the message if patience[i] second(s) have elapsed since the last time the message was sent from this server.
Otherwise, no more resending will occur from this server.
The network becomes idle when there are no messages passing between servers or arriving at servers.

Return the earliest second starting from which the network becomes idle.

LINK : https://leetcode.com/problems/the-time-when-the-network-becomes-idle/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void addEdge(vector<int> adj[],vector<vector<int>>& edges){
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<int> adj[n];
        addEdge(adj,edges);
        
        vector<int> dist(n,INT_MAX);
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        dist[0] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v: adj[u]){
                if(visited[v] == false){
                    dist[v] = dist[u] + 1;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        int res = 0;
        for(int i=1; i<n; i++){
            int temp = (2*dist[i] - 1)/patience[i];
            int time = 2*dist[i];
            if(temp > 0)
                time += (patience[i] * temp);
            res = max(res,time);
            
        }
        return res + 1;
    }
};
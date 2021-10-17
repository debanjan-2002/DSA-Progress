/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

LINK: https://leetcode.com/problems/network-delay-time/ 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void addEdge(vector <pair<int,int>> adj[],vector<vector<int>>& times){
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
    }
    int dijkstra(vector<pair<int,int>> adj[],int n,int k){
        vector<int> dist(n + 1,INT_MAX);
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(pair<int,int> &v: adj[prev]){
                int next = v.first;
                int nextDist = v.second;
                if(dist[next] > dist[prev] + nextDist){
                    dist[next] = dist[prev] + nextDist;
                    pq.push({dist[next],next});
                }
            }
        }
        bool flag = true;
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX){
                flag = false;
                break;
            }
            ans = max(ans,dist[i]);
        }
        if(!flag)
            return -1;
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <pair<int,int>> adj[n+1];
        addEdge(adj,times);
        return dijkstra(adj,n,k);
    }
};
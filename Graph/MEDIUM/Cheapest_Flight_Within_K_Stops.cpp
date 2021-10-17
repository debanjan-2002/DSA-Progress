/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

LINK : https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Bellman Ford Algorithm
    int shortestPath(vector<vector<int>>& flights,int src,int dst,int k,int n){
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        for(int count=0; count<=k; count++){
            vector<int> temp = dist;
            for(vector<int>& v: flights){
                if(dist[v[0]] == INT_MAX)
                    continue;
                if(temp[v[1]] > dist[v[0]] + v[2])
                    temp[v[1]] = dist[v[0]] + v[2];
            }
            dist = temp;
        }
        return (dist[dst] == INT_MAX ? -1 : dist[dst]);
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return shortestPath(flights,src,dst,k,n);
    }
};
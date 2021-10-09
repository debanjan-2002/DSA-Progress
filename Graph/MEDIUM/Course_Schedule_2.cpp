/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void addEdge(vector <int> adj[],vector<vector<int>>& prerequisites){
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }    
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];
        addEdge(adj,prerequisites);
        queue <int> q;
        vector <int> indegree(numCourses,0);
        vector <int> ans;
        int check = 0;
        
        for(int i=0; i<numCourses; i++){
            for(int &v: adj[i])
                indegree[v]++;
        }
        for(int i=0; i<numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            check++;
            ans.push_back(u);
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        if(check == numCourses)
            return ans;
        else
            return {};
    }
};
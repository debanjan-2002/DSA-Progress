/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

#include<bits/stc++.h>
using namespace std;

class Solution {
public:
    void addEdge(vector <int> adj[],vector<vector<int>>& prerequisites){
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> adj[numCourses];
        vector <int> indegree(numCourses,0);
        addEdge(adj,prerequisites);
        int count = 0;
        
        for(int i=0; i<numCourses; i++){
            for(int &v: adj[i]){
                indegree[v]++;
            }
        }
        queue <int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
            
        }
        if(count != numCourses)
            return false;
        else
            return true;
    }
};
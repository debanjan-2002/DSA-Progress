/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 
Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        if(row < 0 || row == grid.size() || col < 0 || col == grid[0].size())
            return 0;
        if(visited[row][col])
            return 0;
        if(grid[row][col] == 0)
            return 0;
        
        visited[row][col] = true;
        int left = dfs(row,col - 1,grid,visited);
        int right = dfs(row,col + 1,grid,visited);
        int top = dfs(row - 1,col,grid,visited);
        int bottom = dfs(row + 1,col,grid,visited);
        visited[row][col] = false;
        
        return grid[row][col] + max(left,max(right,max(top,bottom)));
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    ans = max(ans,dfs(i,j,grid,visited));
                }
            }
        }
        return ans;
    }
};
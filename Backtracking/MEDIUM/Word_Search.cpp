/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int row,int col,vector<vector<char>>& board,int idx,string& word,vector <vector<bool>>& visited){
        if(idx == word.length())
            return true;
        if(row < 0 || row == board.size() || col < 0 || col == board[0].size())
            return false;
        if(board[row][col] != word[idx] || visited[row][col])
            return false;
        
        visited[row][col] = true;
        bool left = dfs(row,col-1,board,idx+1,word,visited);
        bool right = dfs(row,col+1,board,idx+1,word,visited);
        bool top = dfs(row-1,col,board,idx+1,word,visited);
        bool bottom = dfs(row+1,col,board,idx+1,word,visited);
        visited[row][col] = false;
        
        return left || right || top || bottom;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector <vector<bool>> visited(row,vector <bool>(col,false));
            
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(dfs(i,j,board,0,word,visited))
                    return true;
            }
        }
        return false;
    }
};
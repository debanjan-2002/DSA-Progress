/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<string>& curr,int row,int col,int n){
        int tempRow = row - 1;
        int tempCol = col;
        
        //Upper Check
        while(tempRow >= 0){
            if(curr[tempRow--][col] == 'Q')
                return false;
        }
        
        tempRow = row - 1;
        tempCol = col + 1;
        //Right Diagonal
        while(tempRow >= 0 && tempCol < n){
            if(curr[tempRow--][tempCol++] == 'Q')
                return false;
        }
        
        tempRow = row - 1;
        tempCol = col - 1;
        //Left Diagonal
        while(tempRow >=0 && tempCol >= 0){
            if(curr[tempRow--][tempCol--] == 'Q')
                return false;
        }
        return true;
        
    }
    void queen(vector<vector<string>>& ans,vector<string>& curr,int n,int row){
        if(row == curr.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(curr,row,i,n)){
                curr[row][i] = 'Q';
                queen(ans,curr,n,row + 1);
                curr[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector <string> curr(n,string (n,'.'));
        vector <vector<string>> ans;
        queen(ans,curr,n,0);
        return ans;
    }
};


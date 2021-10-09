/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int row,int col,vector<string>& curr){
        int tempRow = row - 1;
        int tempCol = col;
        
        // Top check
        while(tempRow >= 0){
            if(curr[tempRow--][tempCol] == 'Q')
                return false;
        }
        tempRow = row - 1;
        tempCol = col - 1;
        
        //Left Diagonal
        while(tempRow >= 0 && tempCol >= 0){
            if(curr[tempRow--][tempCol--] == 'Q')
                return false;
        }
        tempRow = row - 1;
        tempCol = col + 1;
        
        //Right Diagonal
        while(tempRow >= 0 && tempCol < curr.size()){
            if(curr[tempRow--][tempCol++] == 'Q')
                return false;
        }
        return true;
        
    }
    void queen(vector<string>& curr,int n,int row,int &ans){
        if(row == curr.size()){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(row,i,curr)){
                curr[row][i] = 'Q';
                queen(curr,n,row + 1,ans);
                curr[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector <string> curr(n,string (n,'.'));
        int ans = 0;
        queen(curr,n,0,ans);
        return ans;
    }
};
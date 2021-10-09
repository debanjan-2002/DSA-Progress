/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.s
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <string> ans;
    void parenthesis(string &s, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(s);
            return;
        }
        if(open > 0){
            s.push_back('(');
            parenthesis(s,open-1,close);
            s.pop_back();
        }
        if(close > 0 && close > open){
            s.push_back(')');
            parenthesis(s,open,close-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        parenthesis(s,n,n);
        return ans;
    }
};
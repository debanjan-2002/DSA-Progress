/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    2 = "abc";
    3 = "def";
    4 = "ghi";
    5 = "jkl";
    6 = "mno";
    7 = "pqrs";
    8 = "tuv";
    9 = "wxyz";
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <string> res;
    void combinations(string &digit,int idx,unordered_map <int,string>& m,string &ans){
        if(idx == digit.length()){
            res.push_back(ans);
            return;
        }
        int curr = digit[idx] - '0';
        string op = m[curr];
        for(int j=0; j<op.length(); j++){
            ans.push_back(op[j]);
            combinations(digit,idx + 1,m,ans);
            ans.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        unordered_map <int,string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        string ans = "";
        combinations(digits,0,m,ans);
        return res;
    }
};
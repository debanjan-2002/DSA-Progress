/*
Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: s = "12345"
Output: ["12345"]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <string> ans;
    void permutations(string& s,int idx,string& currStr){
        if(idx == s.length()){
            ans.push_back(currStr);
            return;
        }
        if(isdigit(s[idx])){
            currStr += s[idx];
            permutations(s,idx + 1,currStr);
            currStr.pop_back();
        }
        else if(islower(s[idx])){
            currStr += s[idx];
            permutations(s,idx + 1,currStr);
            currStr.pop_back();
            
            currStr += toupper(s[idx]);
            permutations(s,idx + 1,currStr);
            currStr.pop_back();
        }
        else{
            currStr += s[idx];
            permutations(s,idx + 1,currStr);
            currStr.pop_back();
            
            currStr += tolower(s[idx]);
            permutations(s,idx + 1,currStr);
            currStr.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string currStr = "";
        permutations(s,0,currStr);
        return ans;
    }
};
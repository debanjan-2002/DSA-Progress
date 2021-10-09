/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <vector<int>> ans;
    void combinations(int n,int k,int idx,vector <int>& curr){
        if(k == 0){
            ans.push_back(curr);
            return;
        }
        if(idx > n){
            return;
        }
        curr.push_back(idx);
        combinations(n,k-1,idx+1,curr);
        curr.pop_back();
        combinations(n,k,idx+1,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector <int> curr;
        combinations(n,k,1,curr);
        return ans;
    }
};
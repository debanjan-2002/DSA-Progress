/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

-Only numbers 1 through 9 are used.
-Each number is used at most once.

Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void combination3(int k,int n,int idx,vector<int>& curr){
        if(n < 0)
            return;
        if(k == 0){
            if(n == 0){
                ans.push_back(curr);
            }
            return;
        }
        if(idx > 9)
            return;
        
        curr.push_back(idx);
        combination3(k - 1,n - idx,idx + 1,curr);
        curr.pop_back();
        combination3(k,n,idx + 1,curr);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> curr;
        combination3(k,n,1,curr);
        return ans;
    }
};
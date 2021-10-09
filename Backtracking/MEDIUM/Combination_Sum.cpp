/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int>& temp,int index,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index==candidates.size())
            return;
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            combination(candidates,target-candidates[index],temp,index,ans);
            temp.pop_back();
        }
        combination(candidates,target,temp,index+1,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> temp;
        vector <vector<int>> ans;
        combination(candidates,target,temp,0,ans);
        return ans;
    }
};


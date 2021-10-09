/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <vector<int>> ans;
    void solve(vector<int>& nums,int index,vector<int>& temp){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,index + 1,temp);
        temp.pop_back();
        solve(nums,index + 1,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> temp;
        solve(nums,0,temp);
        return ans;
    }
};
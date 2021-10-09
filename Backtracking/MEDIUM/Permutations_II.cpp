/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set <vector<int>> s;
    void permutations(vector <int>& nums,int idx){
        if(idx == nums.size()-1){
            s.insert(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i],nums[idx]);
            permutations(nums,idx + 1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permutations(nums,0);
        vector <vector<int>> ans;
        for(auto &v:s)
            ans.push_back(v);
        return ans;
    }
};
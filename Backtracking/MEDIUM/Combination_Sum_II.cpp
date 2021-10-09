/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination2(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            temp.push_back(candidates[i]);
            combination2(candidates,target-candidates[i],i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <vector<int>> ans;
        vector <int> temp;
        sort(candidates.begin(),candidates.end());
        combination2(candidates,target,0,temp,ans);
        return ans;
    }
};
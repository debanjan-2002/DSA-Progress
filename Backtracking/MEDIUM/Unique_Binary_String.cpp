/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans;
    void generateString(unordered_set<string>& s,string &curr,int n){
        if(curr.length() == n){
            if(s.find(curr) == s.end()){
                ans = curr;
            }
            return;
        }
        curr.push_back('0');
        generateString(s,curr,n);
        if(ans != curr){
            curr.pop_back();
            curr.push_back('1');
            generateString(s,curr,n);
            curr.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set <string> s;
        for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        
        string curr = "";
        generateString(s,curr,nums.size());
        return ans;
    }
};
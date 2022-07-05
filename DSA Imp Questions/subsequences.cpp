/* Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order. */

class Solution {
public:
    
    void fun(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>v)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        fun(i+1,nums,ans,v);
        v.pop_back();
        fun(i+1,nums,ans,v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>v;
       fun(0,nums,ans,v);
       return ans;
    }
};
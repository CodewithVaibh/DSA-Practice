/* Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input. */

class Solution {
public:
    
    void Comb(int i,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans,int target)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(i==nums.size())
        {
            if(target==0)
            {
                ans.push_back(v);
            }
            return;
        }
        if(target>=nums[i])
        {
            v.push_back(nums[i]);
            Comb(i,nums,v,ans,target-nums[i]);
            v.pop_back();
        }
        Comb(i+1,nums,v,ans,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        Comb(0,nums,v,ans,target);
        return ans;
    }
};
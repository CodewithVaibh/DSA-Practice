/* Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations. */

class Solution {
public:
    
    void fun(int i,vector<int>&nums,vector<int>&v,int target,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            if(target<nums[j])
                break;
            if(j==i)
            {
                v.push_back(nums[j]);
                fun(j+1,nums,v,target-nums[j],ans);
                v.pop_back();
            }
            else if(nums[j]!=nums[j-1])
            {
                v.push_back(nums[j]);
                fun(j+1,nums,v,target-nums[j],ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        fun(0,nums,v,target,ans);
        return ans;
    }
};
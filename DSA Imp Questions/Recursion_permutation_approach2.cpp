//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {
public:
    
    void fun(int i,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            fun(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        fun(0,nums,ans);
        return ans;
    }
};
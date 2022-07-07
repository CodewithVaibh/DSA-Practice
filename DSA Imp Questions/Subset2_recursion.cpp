/* Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order. */

class Solution {
public:
    
    void fun(int i,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans)
    {
        ans.push_back(v);
        for(int j=i;j<nums.size();j++)
        {
            if(j==i)
            {
                v.push_back(nums[j]);
                fun(j+1,nums,v,ans);
                v.pop_back();
            }
            else if(nums[j]!=nums[j-1])
            {
                v.push_back(nums[j]);
                fun(j+1,nums,v,ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        fun(0,nums,v,ans);
        return ans;
    }
};
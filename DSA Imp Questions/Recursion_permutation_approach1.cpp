//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

class Solution {
public:
    
    void fun(vector<int>&nums,vector<int>&v,vector<vector<int>>&ans,vector<int>call)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(call[j]==0)
            {
                v.push_back(nums[j]);
                call[j]=1;
                fun(nums,v,ans,call);
                call[j]=0;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        vector<int>call(nums.size(),0);
        fun(nums,v,ans,call);
        return ans;
    }
};
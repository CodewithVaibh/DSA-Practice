/* You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7. */

class Solution {
public:
    
    int fun(int i,vector<int>&nums,int target,int mini,int maxi)
    {
        if(mini+maxi>target && mini!=1000000 && maxi!=0)
            return 0;
        if(i==nums.size())
        {
           if(mini+maxi<=target)
               return 1;
            return 0;
        }
        int l=fun(i+1,nums,target,mini,maxi);
        mini=min(mini,nums[i]);
        maxi=max(maxi,nums[i]);
        int r=fun(i+1,nums,target,mini,maxi);
        return ((l%1000000007)+(r%1000000007))%1000000007;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int mini=1000000;
        int maxi=0;
        return fun(0,nums,target,mini,maxi);
    }
};
/* Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
 */
 
class Solution {
public:
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
        vector<int>subset;
       for(int i=0;i<(1<<nums.size());i++)
       {
           for(int j=0;j<nums.size();j++)
           {
               if(i&(1<<j))
               subset.push_back(nums[j]);
           }
           ans.push_back(subset);
           while(subset.size()!=0)
           subset.pop_back();
       }
       return ans;
    }
};
 
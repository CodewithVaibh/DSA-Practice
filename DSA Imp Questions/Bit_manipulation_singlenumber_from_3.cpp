/* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space. */

class Solution {
public:
    
    bool getBit(int n,int pos)
    {
        return (n && (n & (1<<pos)));
    }
    
    int setBit(int n,int pos)
    {
        return (n | (1<<pos));
    }
    
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<32;i++)
        {
            int sum=0;
            for(int j=0;j<nums.size();j++)
            {
                if(getBit(nums[j],i))
                    sum++;
            }
            if(sum%3)
            {
                result=setBit(result,i);
            }
        }
        return result;
    }
};
 /* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity. */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minh;
        for(auto &it : nums)
        {
            minh.push(it);
            if(minh.size()>k)
                minh.pop();
        }
        return minh.top();
    }
};
 
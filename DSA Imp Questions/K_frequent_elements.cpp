//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            minh.push({i->second,i->first});
            if(minh.size()>k)
                minh.pop();
        }
        while(minh.size()!=0)
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};
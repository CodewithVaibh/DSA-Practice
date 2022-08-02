/* Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them. */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>maxh;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            maxh.push({i->second,i->first});
        }
        while(maxh.size()!=0)
        {
            int freq=maxh.top().first;
            while(freq!=0)
            {
            ans.push_back(maxh.top().second);
            freq--;
            }
            maxh.pop();
        }
        return ans;
    }
};
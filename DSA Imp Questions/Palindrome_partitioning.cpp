/* Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward. */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>v;
        vector<vector<string>>ans;
        fun(0,s,v,ans);
        return ans;
    }
    
    void fun(int i,string s,vector<string>&v,vector<vector<string>>&ans)
    {
        if(i==s.length())
        {
            ans.push_back(v);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            if(isPalindrome(s,i,j))
            {
                v.push_back(s.substr(i,j-i+1));
                fun(j+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s,int l,int r)
    {
        while(l<=r)
        {
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
};
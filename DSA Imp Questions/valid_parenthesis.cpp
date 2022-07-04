//Given a string S, composed of different combinations of '(' , ')', '{', '}', '[', ']'. The task is to verify the validity of the arrangement.
//Note: Ignore the precedence of brackets.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    // code here
    stack<int>st;
    bool flag =1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        st.push(s[i]);
        else
        {
            if(st.empty())
            flag=0;
            else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))
            st.pop();
            else
            flag=0;
        }
    }
    if(!st.empty())
    flag=0;
    return flag;
}
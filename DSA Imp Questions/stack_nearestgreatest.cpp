//Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
//Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
//If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long>s;
        vector<long long> ans;
        int N=arr.size();
        for(int i=N-1;i>=0;i--)
        {
            if(s.empty())
            ans.push_back(-1);
            else if(s.top()>arr[i])
            ans.push_back(s.top());
            else
            {
                while(!s.empty() && s.top()<=arr[i])
                s.pop();
                if(s.empty())
                ans.push_back(-1);
                else
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
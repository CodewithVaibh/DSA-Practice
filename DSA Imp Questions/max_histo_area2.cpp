//Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
       stack<long long> S;
       long long ans=0;
       for(int i=0;i<=n;i++)
       {
           while(!S.empty() && (i==n || arr[S.top()]>arr[i]))
           {
               long long height=arr[S.top()];
               S.pop();
               int width;
               if(S.empty())
               width=i;
               else
               width=i-S.top()-1;
               ans=max(ans,width*height);
           }
           S.push(i);
       }
       return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
//Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], long long n)
    {
        // Your code here
        vector<long long>NSR;
        vector<long long>NSL;
        stack <pair<long long,long long>>S1;
        stack <pair<long long,long long>>S2;
        for(long long i=n-1;i>=0;i--)
        {
            if(S1.empty())
            NSR.push_back(n);
            else if(S1.top().first<arr[i])
            NSR.push_back(S1.top().second);
            else
            {
                while(!S1.empty() && S1.top().first>=arr[i])
                S1.pop();
                if(S1.empty())
                NSR.push_back(n);
                else
                NSR.push_back(S1.top().second);
            }
            S1.push({arr[i],i});
        }
        reverse(NSR.begin(),NSR.end());
        for(long long i=0;i<n;i++)
        {
            if(S2.empty())
            NSL.push_back(-1);
            else if(S2.top().first<arr[i])
            NSL.push_back(S2.top().second);
            else
            {
                while(!S2.empty() && S2.top().first>=arr[i])
                S2.pop();
                if(S2.empty())
                NSL.push_back(-1);
                else
                NSL.push_back(S2.top().second);
            }
            S2.push({arr[i],i});
        } 
        long long maximum=0;
        long long area[n];
        for(long long i=0;i<n;i++)
        {
            width[i]=(NSR[i]-NSL[i]-1);
            area[i]=width[i]*arr[i];
            maximum=max(maximum,area[i]);
        }
        return maximum;
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
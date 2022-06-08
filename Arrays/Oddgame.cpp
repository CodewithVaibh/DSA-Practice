//Given an array of length N, starting from 1 to N. At each iteration, you remove all elements at odd positions, until only one element is left. Find the last remaining element.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long oddGame(long long N) {
        // code here
        for(long long int i=2;i<=N;i*=2)
        {
            if(N/i==1)
            return i;
        }
        if(N==1)
        return 1;
        if(N==0)
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.oddGame(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
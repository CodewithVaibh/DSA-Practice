//Given two integers M and N, generate all primes between M and N.

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        int isPrime[N],i,j;
        vector<int> ans;
        for(i=1;i<=N;i++)
        {
            isPrime[1]=0;
            isPrime[i]=1;
        }
        for(i=2;i<=sqrt(N);i++)
        {
            if(isPrime[i])
            {
                for(j=i*i;j<=N;j+=i)
                isPrime[j]=0;
            }
        }
        for(i=M;i<=N;i++)
        {
            if(isPrime[i])
            ans.push_back(i);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends
//Find nCr for given n and r.
//As answer can be very large, compute it modulo 109 + 7.

// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long int pow(long int a, long int b, long int m)
    {
        long int power=1;
        while(b){
            if(b%2)
            {
                power=((power%m)*(a%m))%m;
                b--;
            }
            else
            {
                a=((a%m)*(a%m))%m;
                b/=2;
            }
        }
        return power;
    }

    long int ncr(int n, int r){
        //complete the function here
        long int mod=1000000007;
        long int Fact[100005];
        Fact[0]=Fact[1]=1;
        for(long int i=2;i<=n;i++)
        Fact[i]=((Fact[i-1]%mod)*(i%mod))%mod;
        long int res=Fact[n];
        res=((res%mod)*(pow(Fact[r],mod-2,mod)%mod))%mod;
        res=((res%mod)*(pow(Fact[n-r],mod-2,mod)%mod))%mod;
        return res;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    
    }
    return 0; 
} 
  // } Driver Code Ends
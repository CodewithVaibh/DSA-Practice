//Given an equation of the form f(n) = f(n-1) + f(n-2) where f(0) = 1, F(1) = 1 , the task is to find the nth term of this sequence.

// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    long long int mod=1e9+7;
public:
        void mul_arr(long long int A[2][2],long long int B[2][2])
        {
            long long int res[2][2];
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    res[i][j]=0;
                    for(int k=0;k<2;k++)
                    {
                        long long int x=(A[i][k]*B[k][j])%mod;
                        res[i][j]=(res[i][j]+x)%mod;
                    }
                }
            }
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                A[i][j]=res[i][j];
            }
        }

    int FindNthTerm(long long int n) {
        // Code here
        if(n<2)
        return 1;
        
        long long int Imat[2][2];
        long long int Mmat[2][2];
        Imat[0][0]=Imat[1][1]=1;
        Imat[0][1]=Imat[1][0]=0;
        Mmat[0][0]=0;
        Mmat[1][0]=Mmat[0][1]=Mmat[1][1]=1;
        
        n=n-1;
        while(n)
        {
            if(n%2)
            {
                mul_arr(Imat,Mmat),
                n--;
            }
            else
            {
                mul_arr(Mmat,Mmat),
                n/=2;
            }
        }
        int Fn=(Imat[0][0]+2*Imat[1][0])%mod;
        return Fn;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
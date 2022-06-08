//Given a number n, find the total numbers, less than or equal to n which have at-least one common factor with n other than 1.

// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

    int CommonFactor(int n)
    {
        int res,ans;
        res=ans=n;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                res/=i;
                res*=(i-1);
                while(n%i==0)
                n/=i;
            }
        }
        if(n>1)
        {
            res/=n;
            res*=(n-1);
        }
        
        ans-=res;
        return ans;
    }

    
	

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.CommonFactor(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
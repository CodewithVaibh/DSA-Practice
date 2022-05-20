//Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.//

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        long long int m=(long long int)n;
        long long int sum=(m*(m+1))/2;
        long long int sqrsum=(m*(m+1)*(2*m+1))/6;
        long long int mis=0,rep=0;
        
        for(long long int i=0;i<m;i++)
        {
            sum-=(long long int)arr[i];
            sqrsum-=(long long int)arr[i]*(long long int)arr[i];
        }
        int *ans = new int[2];
        if(sum==0)
        {
            ans[0]=(int)rep;
            ans[1]=(int)mis;
        }
        else{
            mis=(sum+(sqrsum/sum))/2;
            rep=mis-sum;
            ans[0]=(int)rep;
            ans[1]=(int)mis;
        }
    return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
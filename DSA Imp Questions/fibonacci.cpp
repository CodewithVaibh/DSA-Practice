//Rohan has a special love for the matrices especially for the first element of the matrix. Being good at Mathematics, he also loves to solve the different problem on the matrices. So one day he started to multiply the matrix with the original matrix.  The elements of the original matrix are given by a00=1 , a01=1, a10=1, a11=0.
//Given the power of the matrix, n calculate the an and return the a10 element mod 1000000007.

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    int firstElement(int n) 
    {
        // code here
        int arr[n+1];
        arr[1]=arr[2]=1;
        for(int i=3;i<=n;i++)
        {
            arr[i]=(arr[i-1]%1000000007)+(arr[i-2]%1000000007);
        }
        return (arr[n]%1000000007);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.firstElement(n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
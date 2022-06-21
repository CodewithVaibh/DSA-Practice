//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
      int MAH(int arr[],int n)
    {
       stack<int> S;
       int ans=0;
       for(int i=0;i<=n;i++)
       {
           while(!S.empty() && (i==n || arr[S.top()]>arr[i]))
           {
               int height=arr[S.top()];
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
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans=MAH(M[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j])
                    M[i][j]+=M[i-1][j];
                else
                    M[i][j]=0;
            }
            ans=max(ans,MAH(M[i],m));
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
//Given a list arr of N integers, print sums of all subsets in it.\

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void fun(int i,vector<int>&arr,int sum,vector<int>&ans)
    {
        if(i==arr.size())
        {
            ans.push_back(sum);
            return;
        }
        fun(i+1,arr,sum+arr[i],ans);
        fun(i+1,arr,sum,ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int sum=0;
        vector<int>ans;
        fun(0,arr,sum,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
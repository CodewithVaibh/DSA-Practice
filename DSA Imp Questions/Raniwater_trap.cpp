//Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        stack<int>S;
        int maxL[n],maxR[n];
        for(int i=0;i<n;i++)
        {
            if(S.empty() || arr[i]>S.top())
            S.push(arr[i]);
            maxL[i]=S.top();
        }
        while(!S.empty())
        S.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            if(S.empty() || arr[i]>S.top())
            S.push(arr[i]);
            maxR[i]=S.top();
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(min(maxL[i],maxR[i])-arr[i]);
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
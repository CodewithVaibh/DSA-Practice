//Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the array
        void merge(long long int arr1[],long long int arr2[], int n, int m)
{ 
    //code here
    int gap=ceil ((float)(n+m)/2);
    while(gap>0)
    {
    long long int i=0;
    long long int j=gap;
    while(j<n+m)
    {
            if(j<n && arr1[i]>arr1[j])
            swap(arr1[i],arr1[j]);
            else if(j>=n && i<n && arr2[j-n]<arr1[i])
            swap(arr2[j-n],arr1[i]);
            else if(j>=n && i>n && arr2[j-n]<arr2[i-n])
            swap(arr2[j-n],arr2[i-n]);
            i++;
            j++;
    }
    if(gap==1)
    gap=0;
    else
    gap=ceil((float)(gap)/2);
    }
}
};
       

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends
//Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
//Given an array arr[], its starting position low and its ending position high.

//Implement the partition() and quickSort() functions to sort the array.

// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
{
    // code here
    if(low>=high)
    return;
    else{
    int p_index=partition(arr,low,high);
    quickSort(arr,low,p_index-1);
    quickSort(arr,p_index+1,high);
    }
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot=arr[high];
   int p_index=0;
   for(int i=0;i<=high-1;i++)
   if(arr[i]<=pivot)
   {
       swap(arr[i],arr[p_index]);
       p_index++;
   }
   swap(arr[p_index],arr[high]);
   return p_index;
}
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
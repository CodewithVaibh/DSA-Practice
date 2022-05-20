//Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>>mergesort_intervals;
         if(intervals.size()==0)
         return mergesort_intervals;
         sort(intervals.begin(),intervals.end());
         vector<int>temp_interval=intervals[0];
         for(auto it : intervals)
         {
             if(it[0]<=temp_interval[1])
             temp_interval[1]=max(it[1],temp_interval[1]);
             else
             {
                 mergesort_intervals.push_back(temp_interval);
                 temp_interval=it;
             }
         }
         mergesort_intervals.push_back(temp_interval);
         return mergesort_intervals;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
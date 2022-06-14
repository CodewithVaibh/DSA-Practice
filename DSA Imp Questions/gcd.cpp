//A seminar of Artificial Intelligence is going on,and the number of participants from Foreign is N, while from India is M. All the participants would be staying in the same hotel.In each room equal number of participants have to stay( can be 1 in a room).Also foreign and Indian cannot stay in the same room. Find the minimum number of rooms required,if in each room the same number of participants are to be seated.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int gcd(int N,int M)
        {
            if(M==0)
            return N;
            else
            gcd(M,N%M);
        }
    int rooms(int N, int M){
        // code here
        int count=0;
        int b=gcd(N,M);
        count = (N+M)/b;
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        
        Solution ob;
        cout<<ob.rooms(N, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
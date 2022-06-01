//You are given an array A of integers of size N. You will be given Q queries where each query is represented by two integers L, R. You have to find the gcd(Greatest Common Divisor) of the array after excluding the part from range L to R inclusive (1 Based indexing). You are guaranteed that after excluding the part of the array remaining array is non empty.

#include <bits/stdc++.h>
using namespace std;



int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    int N,Q;
	    cin>>N>>Q;
	    int arr[N];
	    for(int i=1;i<=N;i++)
	    cin>>arr[i];
	    int Pref[N],Suff[N];
	    Pref[0]=Suff[N+1]=0;
	    for(int i=1;i<=N;i++)
	    Pref[i]=__gcd(Pref[i-1],arr[i]);
	    for(int i=N;i>=1;i--)
	    Suff[i]=__gcd(arr[i],Suff[i+1]);
	    while(Q--)
	    {
	        int L,R;
	        cin >> L >> R;
	        cout << __gcd(Pref[L-1],Suff[R+1]) <<endl;
	    }
	}
	return 0;
}

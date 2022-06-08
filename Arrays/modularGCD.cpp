//Given integers A, B and N, you should calculate the GCD of AN+BN and |A−B|. (Assume that GCD(0,a)=a for any positive integer a). Since this number could be very large, compute it modulo 1000000007 (109+7).

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007

lli power(lli a, lli n , lli d){
    lli res=1;
    while(n){
    if(n%2)
    {
        res=((res%d)*(a%d))%d;
        n--;
    }
    else{
        a=((a%d)*(a%d))%d;
        n/=2;
    }
    }
    return res;
}

lli GCD(lli A, lli B, lli N){
    if(A==B)
    {
        return (power(A,N,mod)+power(B,N,mod))%mod;
    }
    lli factor=1;
    lli num=A-B;
    for(lli i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            lli temp = (power(A,N,i)+power(B,N,i))%i;
            if(temp==0)
            factor=max(factor,i);
            
            temp=(power(A,N,num/i)+power(B,N,num/i))%(num/i);
            if(temp==0)
            factor=max(factor,num/i);
        }
    }
    return factor%mod;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    lli A,B,N;
	    cin>>A >> B >> N;
	    cout<<GCD(A,B,N)<<endl;
	}
	return 0;
}
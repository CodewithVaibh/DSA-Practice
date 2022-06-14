//Micro just learned about prime numbers. But he quickly got bored of them, so he defined a new kind of numbers and called them Prime Prime Numbers. A number X is Prime Prime if number of prime numbers from 1 to X (inclusive) are prime. Now he wants to find out the number of Prime Prime numbers from L to R (inclusive). Help Micro with it.

#include <bits/stdc++.h>
using namespace std;

int prime[1000001];
int pp[1000001];
void seive()
{
	int n=1000000;
    
	for(int i=0;i<=n;i++){
	pp[i]=0;
	prime[i]=1;
	}
	prime[1]=prime[0]=0;
	for(int i=1;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(int j=i*i;j<=n;j+=i)
			prime[j]=0;
		}
	}

	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(prime[i])
		count++;

		if(prime[count])
		pp[i]=1;
	}

	for(int i=1;i<=n;i++)
	pp[i]+=pp[i-1];
}
int main() {
	int t,L,R;
	seive();
	cin >> t;
	while(t--)
	{
	cin >>L >> R;
	int cnt=pp[R]-pp[L-1];
	cout << cnt <<endl;

	}

}
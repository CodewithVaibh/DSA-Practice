//Consider all numbers from 1 to ‘N’, your task is to find the sum of gcd of all pairs (i, j) such that 1 <= i < j <= N.
//For example for N = 3, all pairs are { (1, 2), (1, 3), (2, 3) }.

int phi[5000];

void init(int maxn)
{
    for(int i=1;i<=maxn;i++)
        phi[i]=i;
    for(int i=2;i<=maxn;i++)
        if(phi[i]==i)
        {
            for(int j=i;j<=maxn;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
}

long long count(int d,int N)
{
    return phi[N/d]; 
}


long long fun(int N)
{
    int res=0;
    for(int i=1;i*i<=N;i++)
    if(N%i==0)
    {
        int d1=i;
        int d2=N/i;
        
        res+=d1*count(d1,N);
        if(d1!=d2)
            res+=d2*count(d2,N);
    }
    return res;
}


long long gcdSum(int n)
{
    // Write your code here.
    init(5000);
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=fun(i)-i;
    return sum;
}

#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

LL  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( LL n )
{
    LL  m=sqrt(n), i, j;
    for(i=2;i<=m;i++)
    {
        if(arr[i]==0)
         {
            for(j=i;j<=n;j+=i)
                arr[j]=i;
         }
    }
    for(i=3;i<=n;i+=2)
    {
        if(arr[i]==0)
         {
            arr[i]=i;
         }
    }
}
void prime_fac(LL n)
{
    while(n>1)   //for( LL  i=0; i<np && prime[i] <= m ; i++ )
    {
       if(pfac[nf-1]==arr[n])
       {
           tim[nf-1]++;
       }
       else
       {
           pfac[nf]=arr[n];
           tim[nf]=1;
           nf++;
       }
       n /= arr[n];
    }
}

void divisor()
{
    LL i, j, k, x;
    for(i=0;i<nf;i++)
    {
        LL temp=nd;
        x=1;
        for(j=0;j<tim[i];j++)
        {
            x=x*pfac[i];
            for(k=0;k<temp;k++)
            {
                divi[nd]=divi[k]*x;
                cout << divi[nd] << ' ';
                nd++;
            }
        }
    }
}

LL fi(LL x) /// coprime bahir kore x
{
    LL y=x,i=0;
    while(i!=nf)
    {
        y=y/pfac[i];
        y=y*(pfac[i] - 1);
        i++;
    }
    return y;
}
LL k = 4000001, sum[4000003], ans[4000003], j = 0;

int main()
{
   // ios::sync_with_stdio(false);
        memset( arr, 0, sizeof(arr));
        np = 0; /// number of prime initially 0

        sieve(4000005); /// range of the sieve


        LL n , x, y=0, i, m;

        //cout << arr[4001];

        n = 65539; /// number jr prime fac krbo and divisor find krbo
        nf = 0; /// number of fac intially zero
        prime_fac(n);

        for( i=0; i<nf; i++)
           cout << pfac[i] << ' ' << tim[i] << endl ;

        cout << endl << 1 << ' ';
        divi[0] = 1; /// total divisor find jonno divi array te age e 1 input dia lag
        nd = 1;
        divisor();
        //sort( divi, divi+nd);


        y = 0;
        for( i=0; i<nd; i++)
     {

         x = fi(n/divi[i]); /// koto golo int( x <= n) sathe n r  gcd divi[i]
         y = y + (x*divi[i]); /// sum of all gcd(x,n)....  x <=n
     }





}




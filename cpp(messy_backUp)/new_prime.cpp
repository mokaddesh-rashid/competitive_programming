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
#define M_PI           3.14159265358979323846  /* pi */
#define LL              long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL arr[1000000+1], prime[1000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number
void sieve(LL n )
{
   LL  m = sqrt(n), i, j;
    prime[np] = 2;
    np++;
    for( i=3; i<=m; i += 2)
    {
        if( arr[i] == 0 )
         {
            for( j=i*i; j<=n; j += (i+i) )
                arr[j]++;
         }
    }
    for( i=3; i<=n; i += 2)
    {
        if( arr[i] == 0 )
         {
            prime[np] = i;
            np++;
         }
    }


}



void prime_fac(LL  n )
{
   LL  m = sqrt(n);

    for(LL  i=0; i<np && prime[i] <= m ; i++ )
    {
        if( n % prime[i] == 0 )
        {
           LL  a = 0;

            while( n % prime[i] == 0 )
            {
                a++;
                n /= prime[i];

            }
           //cout << prime[i] << ' ' << a << endl;
           pfac[nf] = prime[i];
           tim[nf] = a;
           nf++;
           m = sqrt(n);
        }
    }

    if( n != 1 )
    {
           ///cout << n << ' ' << 1 << endl;
           pfac[nf] = n;
           tim[nf] = 1;
           nf++;
    }
}

void divisor()
{
   LL i, j, k, x;

    for( i=0; i<nf; i++ )
    {
       LL temp = nd;
        x = 1;

        for( j=0; j<tim[i]; j++)
        {
            x = x * pfac[i];
            for( k = 0; k<temp; k++ )
            {

                divi[nd] = divi[k]*x;
                cout << divi[nd] << ' ';
                nd++;

            }
        }
    }
}

long long  fi( LL  x ) /// coprime bahir kore x
{
    LL  y = x, i = 0;

    while( i != nf )
    {
            y = y/pfac[i];
            y = y*(pfac[i] - 1);

        i++;
    }

    return y;
}

int main()
{
    ios::sync_with_stdio(false);
    outf;
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0

    sieve(10000001); /// range of sieve

    LL p=897868987,n;
    //for(long long  i=p; i<p+300; i++)
         n=111;
         nf = 0;
         //prime_fac(n);
         //if(nf==0)cout<<n<<NL;

}


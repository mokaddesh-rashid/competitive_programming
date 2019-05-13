#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;



LL  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number
void sieve( LL n )
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



void prime_fac( LL  n )
{
    LL  m = sqrt(n);

    for( LL  i=0; i<np && prime[i] <= m ; i++ )
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
           //cout << n << ' ' << 1 << endl;
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

LL  fi(  LL  x ) /// coprime bahir kore x
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
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0

    sieve(10000001); /// range of sieve

    int ca;

    cin >> ca;

    while( ca-- )
    {
        LL t;
        cin >> t;
        set<LL> ms;
        set<LL>::iterator it;
        LL x, j, k, m, n, y;
        for(LL i=0; i<t; i++)
         {
             cin >> n;

             nf = 0;
             prime_fac(n);

             for( j=0; j<nf; j++ )
             {
                 y = pfac[j];
                 if( ms.count( y ) != 0 )
                 {
                     x = y;
                 }
                 else
                 {
                     ms.insert( y );
                 }
             }
         }

         cout << x <<endl;
    }
}

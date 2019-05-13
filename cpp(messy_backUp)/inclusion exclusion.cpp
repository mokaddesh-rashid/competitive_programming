#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;


#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          prlong long f
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000

//set<long long >::iterator ii;
long long  arr[10000000+10], prime[10000000+10], np, pfac[20+1], tim[20+1], nf, divi[100000], nd, val[1000000+10], t, go[1000000+10];

void sieve( long long  n )
{
    long long  m = sqrt(n), i, j;
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


void prime_fac( long long  n )
{
    long long  m = sqrt(n);

    for( long long  i=0; i<np && prime[i] <= m ; i++ )
    {
        if( n % prime[i] == 0 )
        {
            long long  a = 0;

            while( n % prime[i] == 0 )
            {
                a++;
                n /= prime[i];

            }
          // cout << prime[i] << ' ' << a << endl;
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


int main()
{
    std::ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    memset( val, 0, sizeof(val));
    memset( go, 0, sizeof(go));
    np = 0;
    long long n, x, maxx = mn, a, b, m, i , ans, y;
    sieve(10000000);


   while( cin >> n >> m )
   {
        nf = 0;
        prime_fac(n);

        long long ans = m;
        for( int bt=0; bt < 1<<nf; bt++)
        {
            int nob = 0;
            long long val = 1;
            for(int i=0; i< nf; i++)
            {


                if( bt & (1<<i) )
                {
                    val *=pfac[i];
                    nob++;
                }

            }
            if( nob > 0 )
                 {
                     if(nob%2==0)
                        ans += m/val;
                     else
                        ans -= m/val;
                 }

        }
        cout << ans;
   }


}

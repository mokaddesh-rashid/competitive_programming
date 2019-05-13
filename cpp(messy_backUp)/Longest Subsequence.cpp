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
#define pf          printf
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000

//set<int>::iterator ii;
long long  arr[1000000+10], prime[1000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd, val[1000000+10], t, go[1000000+10];

void sieve( int n )
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

void divisor()
{
    int i, j, k, x;

    for( i=0; i<nf; i++ )
    {
        int temp = nd;
        x = 1;

        for( j=0; j<tim[i]; j++)
        {
            x = x * pfac[i];
            for( k = 0; k<temp; k++ )
            {
                t += val[divi[k]*x];
                go[divi[k]*x]++;
                divi[nd] = divi[k]*x;
                //cout << divi[nd] << ' ';
                nd++;

            }
        }
    }
}

int main()
{
    memset( arr, 0, sizeof(arr));
    memset( val, 0, sizeof(val));
    memset( go, 0, sizeof(go));
    np = 0;
    long long n, x, maxx = mn, a, b, m, i , ans;

   // cin >> n >> m;

    sff(n,m);

    long long prin[n+1];

    for( i=0; i<n; i++)
    {
        //cin >> x;
        sf(x);
        prin[i] = x;

        if(x<1000000+1)
        val[x]++;
    }

    sieve(1000010);

   for(  i=m; i>=1; i--)
     {
        if( go[i] == 0 )
         {
          t = 0;
          nf = 0;
          prime_fac(i);
          divi[0] = 1;
          nd = 1;
          t += val[1];
          go[1]++;
          divisor();

          if( t > maxx )
          {
              ans = i ;
              maxx = t;
          }
         }
     }



    long long z = 1, y;

    for( i=0; i<n; i++)
    {
        if( ans % prin[i] == 0 )
        {
            //cout << prin[i] << ' ';
            y = __gcd(z, prin[i]);
            x = z * prin[i];
            z = x / y;
           // cout << z << endl;
        }

    }

   // cout << z << ' ' << maxx << endl;

    pf("%I64d %I64d\n",z,maxx);

      for( i=0; i<n; i++)
    {
        if( z % prin[i] == 0 )
        {
            pf("%I64d ", i+1);
            //cout << i+1 << ' ';

        }

    }
}

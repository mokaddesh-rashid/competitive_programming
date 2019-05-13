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
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



long long  arr[10000+100], prime[10000+1], np, pfac[20+1], tim[20+1], nf, nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( long long n )
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



long long  fi[1000003],  j = 0, se[1000003];

int main()
{
        //inf;
        //outf;
        ios::sync_with_stdio(false);
        memset( arr, 0, sizeof(arr));
        np = 0; /// number of prime initially 0
        sieve(1001); /// range of the sieve
        long long n , x = 0, y=0, i, m, a, b, c, d, p, q, e;

        for( i=1; i<1000002; i++ )
        {
            j = i;

            while( j % 5 == 0 && j > 0 )
            {
                x++;
                j /= 5;
            }
            while( j % 2 == 0 && j > 0 )
            {
                y++;
                j /= 2;
            }
            se[i] = y;
            fi[i] = x;
        }

        //cout << fi[95] << endl;


        int t, ca = 1;

        cin >> t;

        while( t-- )
        {
            cin >> a >> b >> p >> q;

            nf = 0; /// number of fac intially zero
            prime_fac(p);
            c = fi[a];
            d = fi[b];
            e = fi[a-b];
            //cout << c << ' ' << d << ' ' << e << endl;
            x = c - d - e;
            //cout << a << endl;
            c = se[a];
            d = se[b];
            e = se[a-b];
            //cout << c << ' ' << d << ' ' << e << endl;
            y = c - d - e;

            for( i=0; i<nf; i++ )
            {
                //cout << pfac[i] << ' ' << tim[i] << endl;
                if( pfac[i] == 2  )
                    y += ( tim[i] * q ) ;

                if(  pfac[i] == 5 )
                    x += ( tim[i] * q ) ;

            }

            cout << "Case " << ca << ": " << min( x, y) << endl;
            ca++;
        }





}




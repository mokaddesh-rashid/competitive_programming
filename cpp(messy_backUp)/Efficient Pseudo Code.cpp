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
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000
#define mod          1000000007

//set<int>::iterator ii;



long long  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
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
           cout << prime[i] << ' ' << a << endl;
           pfac[nf] = prime[i];
           tim[nf] = a;
           nf++;
           m = sqrt(n);
        }
    }

    if( n != 1 )
    {
           cout << n << ' ' << 1 << endl;
           pfac[nf] = n;
           tim[nf] = 1;
           nf++;
    }
}

long long  bm(long long  base, long long power, long long modu) {    //bm represents bigmod
    if(power == 0)
    {
        return 1;
    }
    if(power % 2 == 0)
    {
        /*
        int ret = bm(base, power / 2, modu);
        return ret * ret;
        */
        long long   ret = (bm(base, power / 2, modu));
        return (ret * ret) % modu;
    }
    else
    {
        //return base * bm(base, power - 1, modu);
        return ( base * (bm(base, power - 1, modu)) ) % modu;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr));
    np = 0; /// number of prime initially 0

    sieve(10000001); /// range of sieve

    long long n, p, i;

    cin >> n;
    nf = 0;
    prime_fac(n);
    long long x = 1, y, z;

    for( i=0; i<nf; i++ )
    {
        y = bm( pfac[i], tim[i]*p, mod ) - 1;
        z = bm( pfac[i]-1, mod-2, mod );
        y *= z;
        x *= y;
        x %= mod;
    }
    cout << x << endl;

}


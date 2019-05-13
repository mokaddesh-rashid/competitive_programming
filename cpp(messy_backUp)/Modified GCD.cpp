
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
    long long i, j, k, x;

    for( i=0; i<nf; i++ )
    {
        long long temp = nd;
        x = 1;

        for( j=0; j<tim[i]; j++)
        {
            x = x * pfac[i];
            for( k = 0; k<temp; k++ )
            {

                divi[nd] = divi[k]*x;
               // cout << divi[nd] << ' ';
                nd++;

            }
        }
    }
}

long long fi( long long x ) /// coprime bahir kore x
{
    long long y = x, i = 0;

    while( x != 1 )
    {
        if( x % pfac[i] == 0 )
        {
            while( x % pfac[i] == 0 )
            {
                x /=  pfac[i];
            }

            y = y/pfac[i];
            y = y*(pfac[i] - 1);
        }

        i++;
    }

    return y;
}

int main()
{
    ios::sync_with_stdio(false);
    memset( arr, 0, sizeof(arr) );
    np = 0; /// number of prime initially 0

    sieve(10000001); /// range of sieve

    long long n, m, i, a, b, c;
         cin >> n >> m;
         n = __gcd(n,m);
         nf = 0;
         prime_fac ( n );
         //cout << endl;
         //cout << 1 << ' ';
         divi[0] = 1; /// total divisor find jonno divi array te age e 1 input dia lag
         nd = 1;
         divisor();

        sort( divi, divi+nd);

        cin >> n;


    for( i=0; i<n; i++ )
    {
        cin >> a >> b;

        c = lower_bound( divi, divi+nd,b) - divi;

        if( divi[c] >= a && divi[c] <= b )
            cout << divi[c] << endl;
        else if( c > 0 && divi[c-1] >= a && divi[c-1] <= b )
            cout << divi[c-1] << endl;
        else
            cout << -1 << endl;
    }



}

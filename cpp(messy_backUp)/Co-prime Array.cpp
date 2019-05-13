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

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009


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

long long arrr[1000000];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    sieve( 100000 );

    long long i, j, x = 0, y = 0, n, m, a, b ,c , g, d;

    cin >> n ;

    for( i=0; i<n; i++ )
    {
        cin >> a;

        if( x == 0 )
        {
            arrr[x] = a;
            x++;
        }

        else
        {
            g = __gcd( a, arrr[x-1] );

            if( g != 1 )
            {
              b = 0;

              while( true )
              {
                  d = __gcd( prime[b], arrr[x-1] );
                  c = __gcd( a, prime[b] );
                  //cout << d << ' ' << c << endl;
                  if( d == 1 && c == 1 )
                    break;

                  b++;
              }

              arrr[x] = prime[b];
              x++;
              arrr[x] = a;
              x++;
              y++;

            }

            else
            {
                arrr[x] = a;
                x++;
            }
        }

    }

    cout << y << endl;

    for( i=0; i<x; i++)
        cout << arrr[i] << ' ';



    return 0;

}



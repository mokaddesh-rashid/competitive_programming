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



long long  arr[10000000+10], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

void sieve( long long n )
{
    long long  m = sqrt(n), i, j;
    //prime[np] = 2;
   // np++;
    for( i=2; i<=m; i ++)
    {
        if( arr[i] == 0 )
         {
            for( j=i ; j<=n; j += i )
                arr[j] = i ;
         }
    }

    for( i=3 ; i <= n; i += 2)
    {
        if( arr[i] == 0 )
         {
            arr[i] = i;
         }
    }


}



void prime_fac( long long  n )
{
   // long long  m = sqrt(n);

     while( n > 1 )   //for( long long  i=0; i<np && prime[i] <= m ; i++ )
    {

           if( pfac[nf-1] == arr[n] )
           {
               tim[nf-1]++;
           }
           else
           {
               pfac[nf] = arr[n];
               tim[nf] = 1;
               nf++;
           }
           n /= arr[n];

    }

}


int main()
{
        ios::sync_with_stdio(false);
        memset( arr, 0, sizeof(arr));
        np = 0; /// number of prime initially 0

        sieve(10000001); /// range of the sieve


        long long n , x, y=0, i, m;

        cin >> n >> m;

        m = n+m;

        while( n < m )
        {

        nf = 0;
        prime_fac(n);
        x = 1;
        for( i=0; i<nf; i++)
        {
            if( tim[i] % 2 )
            {
                x = x*pfac[i];
            }
        }
           //cout << pfac[i] << ' ' << tim[i] << endl ;
        y += x;
        n++;

        }


        cout << y;


}




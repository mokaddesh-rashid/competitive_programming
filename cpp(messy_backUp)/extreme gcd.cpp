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
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



long long  arr[10000+100], prime[10000+100], np, pfac[20+1], tim[20+1], nf, divi[100000], nd, mob[10000+100];
long long  in[40003], cnt[40003];
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number
void mobi( long long n )
{
    long long  m = n, i, j, cnt;
    for( i=2; i<=m; i ++ )
    {        cnt = 1;
        if( arr[i] == 0 )
         {
             long long  l = i*i;
             arr[i]++;
             for( j = i+i; j <= n; j += i )
                {    if( j % l == 0 )
                         mob[j] = 0;
                    cnt++;
                    arr[j]++;
                }
        }
    }

    for( i=2; i<=n; i++ )
    {
        if( mob[i] != 0 )
        {
            if( arr[i] % 2 )
            {
                mob[i] = -1;
            }
            else
                 mob[i] = 1;
        }
    }
}

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
                cnt[divi[nd]]++;
                //cout << divi[nd] << ' ';
                nd++;

            }
        }
    }
}

long long int ncr[10010][10];

long long int nCr(long long n, long long r)
{
    if(r == n || r == 0)
        return 1;
    if(r == 1)
        return n;

    if(ncr[n][r] != -1)
        return ncr[n][r];

    return (ncr[n][r] = (nCr(n-1, r) + nCr(n-1, r-1)));
}

int main()
{
   // ios::sync_with_stdio(false);
        memset( arr, 0, sizeof(arr) );
        memset( mob, -1, sizeof(mob) );
        memset( ncr, -1, sizeof(ncr) );
        mobi( 10001 );
        memset( arr, 0, sizeof(arr) );
        np = 0; /// number of prime initially 0
        sieve(10005); /// range of the sieve
        long long t, ca = 1;
        sf( t );
        //cin >> t;

        while( t-- )
     {
         memset( cnt, 0, sizeof(cnt) );
         long long n , x, y=0, i, m, j;
         sf( n );

         for( i=0; i<n; i++ )
            sf( in[i] );

       for( i=0; i<n; i++ )
       {
            nf = 0; /// number of fac intially zero
            prime_fac( in[i] );
            divi[0] = 1; /// total divisor find jonno divi array te age e 1 input dia lag
            nd = 1;
            divisor();
       }

       x = nCr( n, 4 );
      // cout << x << endl;
       for( i= 2 ; i<10000+1; i++ )
       {
           if( cnt[i] >= 4 && mob[i] != 0 )
           {
               x += ( mob[i] * nCr( cnt[i] , 4 ) );
           }
       }

       if( n < 4 )
         pf( "Case %lld: %lld\n", ca, x );
       else
         pf( "Case %lld: %lld\n", ca, x );
       ca++;
       //cout << x << endl;
     }

}





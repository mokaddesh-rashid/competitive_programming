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



long long  arr[10000000+1], prime[10000000+1], np, pfac[20+1], tim[20+1], nf, divi[100000], nd;
long long k = 4000001, sum[4000003], ans[4000003], j = 0, cnt;
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
                if( divi[nd] % 2 )
                    cnt += divi[nd];
                //cout << divi[nd] << ' ';
                nd++;

            }
        }
    }
}


int main()
{
   // ios::sync_with_stdio(false);
        memset( arr, 0, sizeof(arr));
        np = 0; /// number of prime initially 0

        sieve(1000005); /// range of the sieve


        long long n , x = 0, y=0, i, m, a, b;

         for( i=1; i<100001; i++ )
         {
              nf = 0; /// number of fac intially zero
              prime_fac(i);
              divi[0] = 1; /// total divisor find jonno divi array te age e 1 input dia lag
              nd = 1;
              cnt = 1;
              divisor();
              //cout << i << ' ' << cnt << endl;
              x += cnt;
              sum[i] = x;
         }


         int t;

         cin >> t;

         while( t-- )
         {
             cin >> a >> b;

             m = sum[b] - sum[a-1];

             cout << m << endl;
         }
}





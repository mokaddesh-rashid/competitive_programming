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


long long int  bm(long long int  base, int power )
{    //bm represents bigmod
    if(power == 0)
    {
        return 1;
    }
    if(power % 2 == 0)
    {

        long long ret = bm(base, power / 2 );
        return ret * ret;
        /*
        long long int  ret = (bm(base, power / 2, modu));
        return (ret * ret) % modu;*/
    }
    else
    {
        return base * bm(base, power - 1 );
        //return ( base * (bm(base, power - 1, modu)) ) % modu;
    }
}


long long k = 4000001, sum[4000003], ans[4000003], j = 0;

int main()
{
        inf;
        outf;
        //ios::sync_with_stdio(false);
        memset( arr, 0, sizeof(arr));
        np = 0; /// number of prime initially 0

        sieve(1000005); /// range of the sieve


        long long n , x, y=0, i, m, t, a, b, c, ca = 1, iii;

        for( int iii=1; iii<1000001; iii++ )
        {
            n = iii; /// number jr prime fac krbo and divisor find krbo
            nf = 0; /// number of fac intially zero
            prime_fac(n);
            a = 1;

            for( i=0; i<nf; i++ )
            {
                x = pfac[i] - 1;
                b = tim[i] + 1;
                y = bm( pfac[i], b ) - 1;
                //if( iii == 65539 )
                    //cout << x << ' ' << b << ' ' << y << endl;
                y /= x;
                a *= y;
                //if( iii == 65539 )
                    //cout << a << endl;
                if( a > 1000000 )
                    a = 0;
            }
           // if( a == 5 )
               //cout << iii << ' ' << a << endl;
            if( a <= 1000000 && sum[a] == 0 )
            {
                sum[a] = iii;
            }
        }

        cin >> t;

        while( t-- )
        {
            cin >> a;
            //cout << a << ' ' << sum[a] << endl;
            if( sum[a] == 0 )
                cout << "Case " << ca++ << ": nai\n";
            else
                cout << "Case " << ca++ << ": " << sum[a] << endl;
        }



}




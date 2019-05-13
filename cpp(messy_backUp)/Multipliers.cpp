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
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000
#define mod         (long long)1000000007



//set<long long >::iterator ii;



long long   np, pfac[2000000+1], tim[2000000+1], nf, divi[100000], nd, nt;
/// np(num of prime)  , nd (number of divisor)
/// nf (num of prime fac)
///pfac stores prime fac and tim count numbers of a prime fac
/// divi stores the divisor of the number

long long   bm(long long   base, long long  power, long long  modu)  //bm represents bigmodu
{
    if(power == 0)
    {
        return 1;
    }
    if(power % 2 == 0)
    {
        /*
        long long  ret = bm(base, power / 2, modu);
        return ret * ret;
        */
        long long   ret = (bm(base, power / 2, modu));
        return (ret% modu * ret % modu ) % modu;
    }
    else
    {
        //return base * bm(base, power - 1, modu);
        return ( base * (bm(base, power - 1, modu)) % modu ) % modu;
    }
}


int  main()
{
   // ios::sync_with_stdio(false);

         memset( tim, 0, sizeof(tim));
         memset( pfac, 0, sizeof(pfac));
         long long x = 0 , y, a, b, i, n, m, p;
         sf(n);
         //cin >> n;
         long long  arr[n+1000];

         for( i=0; i<n; i++)
            sf(arr[i]);
            //cin >> arr[i];

         sort( arr, arr+n);


         m = n;
         nf = 0;

         for( i=0; i<n; i++)
         {
             if( pfac[nf-1] != arr[i] || i == 0)
             {
                 m++;
                 pfac[nf] = arr[i];
                 tim[nf] = 1;
                 nf++;

             }
             else
             {
                 tim[nf-1]++;
             }
         }
         m = 1;
         //cout << m << endl;
         for( i=0; i<nf; i++)
         {
             m = m*(tim[i]+1);
         }

         x = 1;

         for( i=0; i<nf; i++)
         {
            a = tim[i]*(tim[i]+1);
            a /= 2;
            b = m / (tim[i]+1);
            p = a*b;

            if(p != 0 )
              y = bm(pfac[i],p,mod);
            else
              y = bm(pfac[i],a,mod);
            x = x*y;
            x %= mod;
         }

         cout<< x;


}

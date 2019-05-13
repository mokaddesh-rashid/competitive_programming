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
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;
LL n, k, arr[500050];

int chk ( LL  x )
{
    LL  c = 0, i, j, a, b = 0, d, e;
    i = 0;
    j = n-1;

    while( i < j )
    {
        a = arr[i]  ;
        b = max( arr[j], b);


        if( b - a > x )
        {
           a += x;
           d = b - a;
           if( d % 2 )
            d++;
           c += ( d / 2 );
           e = arr[j] - ( d / 2 );
           if( b == arr[j] )
            b = e;
           //cout << d / 2 << ' ' << c << ' ' << b << endl;
        }

        i++;
        j--;

    }

    if( c <= k  )
        return 1;
    else
        return 0;
}

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = mx, y, m, st = 0, en = 1000000001, mid, a, cnt = 0, z;

   // cin >> n >> k ;
    sff( n, k );

   for( i=0; i<n; i++ )
    {
        sf( arr[i] );
        //cin >> arr[i];
        cnt += arr[i];
    }

//    if( cnt % n )
//        st = 1;

    sort( arr, arr+n );

    while( st <= en )
     {
        mid = ( st + en ) / 2;

        a = chk( mid );


        //cout << mid << ' ' << a << endl;
        if( a == 1 )
        {
            x = min( x, mid );
            en = mid - 1;
        }
        else
            st = mid + 1;
     }


     cout << x;


    return 0;

}



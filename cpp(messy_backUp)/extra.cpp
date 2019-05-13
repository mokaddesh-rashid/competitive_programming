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
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

LL n, k, arr[ 100010 ], brr[ 100010 ];

int chk( int x )
{
    LL a = 0, y = k, b, c, d ;

    for( int i=0; i<n; i++ )
    {
       b = (long long) x * arr[i];

       b = (long long) b - brr[i];


       if( b > 0 )
       {
           y  = (long long) y - b;
           if( y < 0 )
            break;
       }
    }
    // cout << y << 'k'  << endl;
    if( y >= 0 )
        return 1;
    else
        return 0;
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, m, st = 0, en = 2000000001, mid, a, b, c;

    cin >> n >> k ;

    for( i=0; i<n; i++ )
        cin >> arr[i];

    for( i=0; i<n; i++ )
        cin >> brr[i];

    while( st <= en )
    {
       mid = ( st + en ) / 2;

       a = chk ( mid );
       if( a == 1 )
       {
           x = max( x, mid );
           st = mid + 1;
       }
       else
          en = mid - 1;
    }

    cout << x;








    return 0;

}


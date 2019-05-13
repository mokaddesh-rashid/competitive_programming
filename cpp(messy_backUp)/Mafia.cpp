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
#define mn          (long long) -100000000000000000
#define mx          (long long) 100000000000000000



//set<int>::iterator ii;

long long n, arr[100010], x;

int chk( long long x )
{
    long long y = 0;

    for( int i=0; i<n; i++ )
    {
        y += ( x - arr[i] );
    }

    if( y >= x )
        return 1;
    else
        return 0;
}



int main()
{
    ios::sync_with_stdio(false);

   // INP;
    //OUT;

    long long i, j, m = mx , a, st, en, mid;

    x = mn;

    cin >> n ;

    for( i=0; i<n; i++)
    {
        cin >> arr[i];
        x = max( x, arr[i]);

    }

    sort( arr, arr+n );
    st = x;
    en = x*2;

    while( st <= en )
    {
        mid = (st+en) / 2;

        a = chk(mid);

        if( a == 1 )
            m = min( m, mid);

        if( a == 0 )
            st = mid+1;
        else
            en = mid-1;
    }

     cout << m;

    return 0;

}



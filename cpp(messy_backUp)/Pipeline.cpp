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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n


//set<int>::iterator ii;

LL n, m;

int chk( LL x )
{
    LL i, j, a, b, c = x-1;
    //cout << x << ' ';
    b = m*(m+1);
    b /= 2;
    x = m - x;
    a = x*(x+1);
    a /= 2;
//cout << a << ' ' << b << ' ' << b - a << endl;
    a = b - a;
    a -= c;

    if( a >= n )
        return 1;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = mx, y, st, en, mid;

    cin >> n >> m ;

    st = 1;
    en = m;

    while( st <= en )
    {
        mid = (st+en) / 2;

        y = chk( mid );

        if( y == 1 )
        {
            x = min( x, mid );
            en = mid-1;
        }
        else
            st = mid+1;
    }

    if( n == 1)
        cout << 0;
    else if( x == mx )
        cout << -1;
    else
        cout << x;





    return 0;

}



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

int main()
{
    inf;
    outf;

    ios::sync_with_stdio(false);

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        long long i, j, x, y, n, m, a, b, c, d;

        cin >> a >> b >> c >> d;

        x = max( a, b );
        x = max( x, c );
        x = max( x, d );

        cout << "Case " << ca++ << ": " << min( ( a + b + c + d ) / 4 , a + b + c + d - x ) << endl;
    }

    return 0;

}

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
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

LL ar[200010], ad[200010], ans[200010], tm[200010], br[200010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( ad, 0, sizeof(ad));
    memset( tm, 0, sizeof(tm));
    LL i, j, x, y, n, m, a, b, mx = -1, c = 1, t = -1;

    cin >> n >> m ;

    for( i=0; i<n; i++ )
    {
        cin >> ar[i];
        br[i] = ar[i];
    }

    for( i=0; i<m; i++ )
    {
        cin >> a >> b;

        ad[b-1] = a;
        tm[b-1] = i+1;
        mx = max( mx, b );
    }

    sort( ar, ar+mx );

    a = 0;
    b = mx-1;

    for( i=b; i>=0; i-- )
    {
        if( c == 1 && tm[i] > t && ad[i] == 2 )
            {
                //cout << c << ' ' << ad[i] << endl;
                c = ad[i];
                t = tm[i];
            }
        if( c == 2 && tm[i] > t && ad[i] == 1 )
            {
                //cout << c << ' ' << ad[i] << endl;
                c = ad[i];
                t = tm[i];
            }

        if( c == 2 )
        {
            ans[i] = ar[a];
            a++;
        }
        else
        {
            ans[i] = ar[b];
            b--;
        }
    }

    for( i=0; i<mx; i++ )
        cout << ans[i] << ' ';
    for( i=mx; i<n; i++ )
        cout << br[i] << ' ';

    return 0;

}



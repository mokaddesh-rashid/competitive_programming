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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int ar[2000001], br[2000001], cnt[2000001];


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c = -2, d;

    cin >> n ;

    for( i=0; i<n; i++ )
    {
        cin >> a >> b;
        ar[a] = b;
        br[b] = a;
        cnt[a]++;
        cnt[b]++;
        if( a == 0 )
            x = b;
        if( b == 0 )
            y = a;
    }
    for( i=1; i<=2000001; i++ )
    {
        if( cnt[i] == 1 && ar[i] != 0 && n%2 == 1 )
            {
                c = 2;
                y = i;
            }
    }
   // cout << y << endl;
    int ans[n+10];

    i = 1;

    while( x != 0 )
    {
        ans[i] = x;
        x = ar[x];
        i += 2;
    }

    if( c == 2 )
       i = 0;
    else
       i = n-2;

    while( y != 0 )
    {

        ans[i] = y;
        if( c == 2 )
        y = ar[y];
        else
        y = br[y];
        i += c;
    }

    for( i=0; i<n; i++ )
        cout << ans[i] <<  ' ';
    return 0;

}



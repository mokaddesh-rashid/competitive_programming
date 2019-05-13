#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> pr;


//set<int>::iterator ii;

struct node
{
   LL d, f, s;
}ar[100010];

bool compare( node x, node y )
{
    return x.d > y.d;
}

LL fi[100010], si[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m;

    cin >> n >> m;


    for( i=0; i<n; i++ )
        cin >> fi[i] >> si[i];

    for( i=0; i<n; i++ )
        ar[i].d = max( fi[i]-si[i], si[i]-fi[i] ) , ar[i].f = fi[i], ar[i].s = si[i];

    sort( ar, ar+n, compare );

    for( i=0; i<n; i++ )
        {
            if( ar[i].f >= ar[i].s && m > 0 ) x += ar[i].f, m--;
            else x -= ar[i].s;
        }
    //cout << x << ' ' << m << endl;
    for( i=0; i<n; i++ )
        {
            if( m > 0 && ar[i].f < ar[i].s ) x += ar[i].f, x += ar[i].s, m--;
        }

    cout << max( (LL)0, x );

    return 0;

}

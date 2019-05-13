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


struct node
{
    LL v, pa, low, lev;
}tar[50], dfa[50], cfa[50];

int stk[50], top, ins[50], ti, cnt[50];
vector<int> mat[50];

void tarzan( int p )
{
    int i, j, y;
    tar[p].v = 1;
    tar[p].low = tar[p].lev = ++ti;
    ins[p] = 1;
    stk[++top] = p;

    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i], y;
        if( tar[x].v == 0 )
        {
            tarzan(x);
            tar[p].low = min( tar[x].low, tar[p].low );

        }
        else if( ins[x] == 1 ) tar[p].low = min( tar[x].lev, tar[p].low );

    }
    if( tar[p].low == tar[p].lev )
    {
        int nn = 0;
        while( top > -1 )
        {
            nn++;
            y = stk[top];
            ins[y] = 0;
            top--;
            cnt[y] = 1;
            if( y == p ) break;
        }
        if( nn == 1 ) cnt[y] = 0;

    }
}

int vis[50], ow, dp[50], cir[50], cr, im[50];

void dfs( int p )
{
    if( cnt[p] == 1 ) cir[cr] = p;
    vis[p] = 1;
    dfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == 0 )
        {
            dfs(x);
        }
    }
}

void cfs( int p )
{
    if( cnt[p] == 1 ) cir[cr] = p;
    vis[p] = 1;
    cfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( cfa[x].v == 0 )
        {
            cfs(x);
        }
    }
}

int tok[100];

int rec( int s, int p )
{
    //cout << s << ' ' << p << ' ' << cnt[p] << endl;
    if( cnt[p] == 1 ) return 0;
    if( s == p ) return 1;
    if( dp[p] != -1 ) return dp[p];

    int temp = 0;
    for( int i=0; i<mat[p].size(); i++ )
        {
           // cout << mat[p][i] << endl;
            if( tok[ mat[p][i] ] == 0 )
            {
                tok[ mat[p][i] ] = 1;
                temp += rec( s, mat[p][i] );
                tok[ mat[p][i] ] = 0;
            }
        }

    return dp[p] = temp;

}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca = 0;

    int m;
    while( cin >> m )
    {
        mem( cnt, 0 );
        mem( tar, 0 );

        int i, j, x, y, n;

        n = ti = 0;
        top = -1;
        for( i=0; i<32; i++ ) mat[i].clear();

        for( i=0; i<m; i++ )
        {
            cin >> x >> y;
            x++; y++;
            n = max( x, n ); n = max( y, n );
            mat[x].push_back( y );
           // mat[y].push_back( x );
        }

        for( i=1; i<=n; i++ )
        {
            if( tar[i].v == 0 ) tarzan( i );
        }

        int ans[33][33];

        mem( dp, -1 );
        for( i=1; i<=n; i++ )
        {
            mem( dfa , 0 );
            mem( cfa, 0 );
            cr = 0;
            dfs( i );

            for( j=0; j<cr; j++ )
            {
                if( cfa[j].v == 0 ) cfs( j );
            }
            for( int l=1; l<=n; l++ )
            {
                mem( dp, -1 );
                if( cfa[l].v == 1 || cnt[i] == 1 ) ans[i][l] == -1;
                if( i != l ) ans[i][l] = rec( l, i );
                else ans[i][l] = 0;
            }

        }

        cout << "matrix for city " << ca++ << endl;
        for( i=1; i<=n; i++ )
        {
            for( j=1; j<=n; j++ )
            {
                cout << ans[i][j];
                if( j == n ) cout << endl;
                else cout << ' ';
            }

        }
    }



    return 0;

}

/*
4
0  1
0  2
1  2
2  3
*/



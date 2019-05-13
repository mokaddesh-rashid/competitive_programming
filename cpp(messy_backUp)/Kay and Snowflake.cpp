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

struct info2
{
    int v, ty;
}arr[3000001];

vector <int> mat[300001], cost[100001]; ///adjecency matrix
struct info0
{
    int v, l, pa, cn, h_c, h_v,lf, ri;
}lar[3000001]; // array of info about input

int que[300001], hd, re, iv, n, sp_t[100001][20], ms, max_t[100001][20], min_t[100001][20], stk[100001], top, len;


///************DFS*********
void dfs( int p )
{
    if( lar[p].cn == 0 )
    {
        //top++;
        //stk[top] = p;
        //cout << p << '(' << len << ')' << ' ';
        arr[len].v = 1;
        lar[p].lf = len;
        lar[p].cn = 2;
        len++;

        for( int i=1; i<=mat[p][0]; i++ )
        {
            int y = mat[p][i];
            dfs( y );
            int z = ( lar[y].ri - lar[y].lf + 1 ) / 2;
            //cout << p << ' ' << y << ' ' << lar[y].ri - lar[y].lf + 1 << endl;
            if( lar[p].h_v < z )
                {
                    lar[p].h_c = y;
                    lar[p].h_v = z;
                }
        }
        //cout << p << '(' << len << ')' << ' ';
        arr[len].v = 0;
        lar[p].ri = len;
        len++;
        top--;

    }

}


int sv[300001];

int rec( int x, int cmp )
{
    //cout << x << ' ' << lar[x].h_v << endl;
    if( mat[x][0] == 0 )
    {
        return x;
    }
    else if ( lar[x].h_v >= (cmp/2) )
    {

        return rec( lar[x].h_c, cmp );
    }
    else
        return x;

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    top = -1;
    hd = 0;
    re = 0;
    len = 1;
    int i, j, x, y,  m, z, a, b, c, e, f, g, h, maxx, p;

    //cin >> n ;
     cin >> n >> m;
    //cout << n << endl;

    ms = log(n) / log(2);
    ms++;

    for( i=1; i<=n; i++ )
    {
        mat[i].clear( );
        //cost[i].clear( );
        mat[i].push_back(0);
        //cost[i].push_back(0);

    }


    for( i=1; i<n; i++ )
    {
        x = i+1;
        cin >> y;
        //cout << x << ' ' << y  << ' ' << z << endl;
        mat[y].push_back(x);
        //mat[x].push_back(y);
        mat[y][0] = mat[y][0]+1;
        //mat[y][0] = mat[y][0]+1;
    }

    //bfs(1);
    dfs(1);

    x = 0;
    for( i=1; i<len; i++ )
    {
        x += arr[i].v;
        arr[i].v = x;
    }
    //pf("Case %d:\n", ca++ );

    for( j=0; j<m; j++ )
    {
        cin >> x;
        int cmp = arr[lar[x].ri].v - arr[lar[x].lf].v+1;
        if( cmp % 2 )
            cmp++;
        maxx = 1;
        //cout << cmp/2 << endl;
        cout << rec( x, cmp ) << endl;
    }

    return 0;

}

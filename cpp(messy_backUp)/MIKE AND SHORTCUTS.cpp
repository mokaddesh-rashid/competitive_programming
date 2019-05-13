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

vector <int> mat[500001];///adjecency matrix
struct info0
{
    int v, l, pa, cn;
}lar[1000001]; // array of info about input

int que[1000001], hd, re, iv, n, sp_t[100001][20], ms, max_t[100001][20], min_t[100001][20], stk[1000001], top, len;

///**************BFS*********
void bfs( int p ) ///bfs
{
    lar[p].l = 1;
    lar[p].pa = -1;
    sp_t[p][0] = -1;
    lar[p].cn = 1;
    que[re] = p;
    re++;

    while( hd != re )
    {
       // cout << p << " = ";
        for(int i=1; i<=mat[p][0]; i++ )
        {
            int x = mat[p][i];

            if( lar[x].cn == 0 )
            {
               // cout << x << '(' << mat[p][i] << ')' << ' ';
                lar[x].l = lar[p].l+1;
                lar[x].pa = p;
                sp_t[x][0] = p;
                lar[x].cn = 1;
                que[re] = x;
                re++;

            }

        }
        //cout << endl;
        hd++;
        p = que[hd];
    }
}
///************DFS*********

int main()
{
    ios::sync_with_stdio(false);
    memset( lar, 0, sizeof(lar) );
    top = -1;
    hd = 0;
    re = 0;
    len = 1;
    int i, j, x, y,  ma, z, a, b, c, e, f, g, h;

    cin >> n;
    ma = n;

    for( i=1; i<=n; i++ )
    {
        mat[i].clear( );
        mat[i].push_back(0);

    }


    for( i=1; i<n; i++ )
    {
        x = i;
        y = i+1;
        mat[y].push_back(x);
        mat[x].push_back(y);
        mat[x][0] = mat[x][0]+1;
        mat[y][0] = mat[y][0]+1;
    }
    for( i=1; i<=n; i++ )
    {
        x = i;
        cin >> y;
        mat[x].push_back(y);
        mat[x][0] = mat[x][0]+1;
    }

    bfs(1);
    x = 0;
    for(int i=1; i<=ma; i++ )
    {
        cout << ( lar[i].l-lar[1].l ) << ' ';
    }


    return 0;

}






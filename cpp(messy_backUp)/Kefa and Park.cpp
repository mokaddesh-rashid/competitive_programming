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
}arr[400001];

vector <int> mat[100001], cost[100001]; ///adjecency matrix
struct info0
{
    int v, l, pa, cn, dis, chk, lf, ri;
}lar[100001]; // array of info about input

int que[100001], hd, re, iv, n, leaf[1000001], top, len, ar[100001], m, max_l;

///**************BFS*********
void bfs( int p ) ///bfs
{
    lar[p].chk = 0;
    if( ar[1] == 1 )
        lar[p].v = 1;
    else
        lar[p].v = 0;
    lar[p].l = 1;
    lar[p].pa = -1;
    lar[p].cn = 1;
    que[re] = p;
    re++;

    while( hd != re )
    {
        //cout << p << " = ";
        for(int i=1; i<=mat[p][0]; i++ )
        {
            int x = mat[p][i];

            if( lar[x].cn == 0 )
            {
                leaf[p]++;
                //cout << x << '(' << lar[p].l+1 << ')' << ' ';
                if( lar[p].chk == 0 )
                {
                     if( lar[p].v+1 > m && ar[x] == 1 )
                       lar[x].chk = 1;
                     else if( ar[x] == 1 )
                        lar[x].v = lar[p].v + 1;
                     else
                        lar[x].v = 0;

                }
                else
                    lar[x].chk = 1;

                lar[x].l = lar[p].l+1;
                lar[x].pa = p;
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


int main()
{
    ios::sync_with_stdio(false);
    memset( lar, 0, sizeof(lar) );
    memset( arr, 0, sizeof(arr) );
    top = -1;
    hd = 0;
    re = 0;
    len = 1;
    int i, j, x, y, z, a, b, c, e, f, g, h;

    cin >> n >> m;

    for( i=1; i<=n; i++ )
    {
        cin >> ar[i];
        mat[i].clear( );
        mat[i].push_back(0);

    }


    for( i=1; i<n; i++ )
    {
        cin >> x >> y;
        mat[y].push_back(x);
        mat[x].push_back(y);
        mat[x][0] = mat[x][0]+1;
        mat[y][0] = mat[y][0]+1;
    }

    bfs(1);
    int cnt = 0;
    for( i=1; i<=n; i++ )
    {
        //cout << lar[i].l << ' ' << lar[i].chk << endl;
        if( leaf[i] == 0 && lar[i].chk == 0 )
            cnt++;
    }
    cout << cnt;
    return 0;

}






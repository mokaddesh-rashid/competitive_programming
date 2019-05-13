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

int que[100001], hd, re, iv, n, sp_t[100001][20], ms, max_t[100001][20], min_t[100001][20], stk[100001], top, len;

///**************BFS*********
void bfs( int p ) ///bfs
{
    min_t[1][0] = 1111111;
    lar[p].l = 1;
    lar[p].pa = p;
    sp_t[p][0] = -1;
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
int ho[2000001];
int main()
{
    ios::sync_with_stdio(false);
    memset( lar, 0, sizeof(lar) );
    memset( arr, 0, sizeof(arr) );
    top = -1;
    hd = 0;
    re = 0;
    len = 1;
    int i, j, x, y,  m, z, a, b, c, e, f, g, h;

    cin >> n ;
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


    for( i=1; i<=n; i++ )
    {
        x = i;
        cin >> y;
        if( i == y )
            ho[i] = 1;
        //cout << x << ' ' << y  << ' ' << z << endl;
        mat[y].push_back(x);
        mat[x].push_back(y);
        mat[x][0] = mat[x][0]+1;
        mat[y][0] = mat[y][0]+1;
    }
    int cnt = 0;
    for( i=1; i<=n; i++ )
    {
        if( ho[i] == 1 && lar[i].cn == 0 )
        {
            cnt++;
            bfs(i);
        }
    }
    for( i=1; i<=n; i++ )
    {
        if( lar[i].cn == 0 )
        {
            cnt++;
            bfs(i);
        }
    }
    //cout <<
    int d = -1;
    if( cnt == 1 )
    {
        cout << 0 << endl;
        for( i=1; i<=n; i++ )
            cout << lar[i].pa << ' ';
    }
    else
    {
        cout << cnt-1 << endl;
        for( i=1; i<=n; i++ )
        {
            x = lar[i].pa;
            if( x == i && d == -1 )
                cout << lar[i].pa << ' ';
            else if( x == i && d != -1 )
                cout << d << ' ';
            else
                cout << lar[i].pa << ' ';
            if( x == i )
            {
                d = i;
            }
        }
            //cout << lar[i].pa << ' ';
    }



    return 0;

}





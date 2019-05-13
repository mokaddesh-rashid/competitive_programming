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

vector <int> mat[100001], cost[100001];
struct info
{
    int v, l, pa, cn, dis, chk;
}lar[100001]; // array of info about input

int que[100001], hd, re, iv, n, sp_t[10001][20], ms;

void bfs( int p )
{
    lar[p].l = 1;
    lar[p].pa = -1;
    sp_t[p][0] = -1;
    lar[p].cn = 1;
    //lar[p].dis = 0;
    que[re] = p;
    re++;
    int t = 2;
    while( hd != re )
    {
        //cout << p << " = ";
        for(int i=1; i<=mat[p][0]; i++ )
        {
            int x = mat[p][i];

            if( lar[x].cn == 0 )
            {
               // cout << x << ' ';
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

void cre_t()
{
    for(int i=1; i<ms; i++ )
    {
        for(int j=1; j<=n; j++ )
        {
            int x = sp_t[j][i-1];

            if( x != -1 )
                sp_t[j][i] = sp_t[x][i-1];
            else
                sp_t[j][i] = -1;
        }
    }
}

int fi_lca( int x, int y, int jm )
{
    if( sp_t[x][jm] == sp_t[y][jm] )
   {
       //cout << sp_t[x][jm] << ' ' << sp_t[y][jm] << 'k' << endl;;
       if( x == y )
        return x;
       else if( jm == 0 )
        return sp_t[x][jm];
       else
        return fi_lca( x, y, jm-1 );
   }
   else
   {
       //cout << sp_t[x][jm] << ' ' << sp_t[y][jm] << 'l' << endl;
       x = sp_t[x][jm];
       y = sp_t[y][jm];
       return fi_lca( x, y, jm );
   }
}

int mak_sm( int x, int y, int jm )
{
    int z = sp_t[x][jm];

    if( lar[x].l == lar[y].l )
        return x;
   else if( lar[z].l < lar[y].l )
        return mak_sm( x, y, jm-1 );
   else
   {
       //cout << sp_t[x][jm] << ' ' << sp_t[y][jm] << 'l' << endl;
       x = sp_t[x][jm];
       return mak_sm( x, y, jm );
   }
}

int main()
{
    //ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca=1;
    sf(t);

    while( t-- )
    {
        memset( sp_t, -1, sizeof(sp_t) );
        memset( lar, 0, sizeof(lar) );
        int i, j, x, y,  m, z;

        //cin >> n ;
        sf(n);

        ms = log(n) / log(2);
        ms++;

        for( i=1; i<=n; i++ )
        {
            mat[i].clear( );
            //mat[i].push_back(0);
            //cost[i].push_back(0);
            //cin >> lar[i].v;
        }


        for( i=1; i<=n; i++ )
        {
            //x = i+1;
            //cin >> m;// >> z;
            sf(m);
            mat[i].push_back(m);

            for( j=0; j<m; j++ )
            {
                sf(x);
                mat[i].push_back(x);
                //mat[y].push_back(x);
            }
                //cost[x].push_back(z);
                //cost[y].push_back(z);
                //mat[x][0] = mat[x][0]+1;
                //mat[y][0] = mat[y][0]+1;
        }

        bfs(1);

        cre_t();
    //    for( i=1; i<=n; i++ )
    //    {
    //        cout << i << " = ";
    //        for( j = 0; j<ms; j++ )
    //    {
    //        cout << sp_t[i][j] << ' ';
    //        if( j == 3 )
    //            cout << endl;
    //    }
    //
    //    }

        //cin >> z;
        sf(z);
        pf("Case %d\n", ca++ );
        for( i=0; i<z; i++ )
        {

            sff( x, y );
            if( lar[x].l > lar[y].l )
                x = mak_sm( x, y, ms-1 );
            if( lar[x].l < lar[y].l )
                y = mak_sm( y, x, ms-1 );

            pf("%d\n", fi_lca( x, y, ms-1 ) );
        }

    }

    return 0;

}




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

int que[100001], hd, re, iv, n, sp_t[100001][20], ms, max_t[100001][20], min_t[100001][20];

void bfs( int p )
{
    min_t[1][0] = 1111111;
    lar[p].l = 1;
    lar[p].pa = -1;
    sp_t[p][0] = -1;
    lar[p].cn = 1;
    lar[p].v = 0;
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
                //cout << x << '(' << cost[p][i] << ')' << endl;
                lar[x].l = lar[p].l+1;
                lar[x].pa = p;
                lar[x].v =  cost[p][i];
                max_t[x][0] = lar[x].v;
                min_t[x][0] = lar[x].v;
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
            int x = sp_t[j][i-1], y;

            if( sp_t[x][i-1] == -1 )
                y = 1111111;
            else
                y = min_t[x][i-1];

            if( x != -1 )
                {
                    min_t[j][i] = min( min_t[j][i-1], y );
                    max_t[j][i] = max( max_t[j][i-1], max_t[x][i-1] );
                    sp_t[j][i] = sp_t[x][i-1];
                }

            else
                {

                    min_t[j][i] = min( min_t[j][i-1], y );
                    max_t[j][i] = max( max_t[j][i-1], max_t[x][i-1] );
                    sp_t[j][i] = -1;
                }
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

///***********y levelr por 1st parent******
int lca_dc( int x, int y, int jm )
{
    int z = sp_t[x][jm];

    if( lar[sp_t[x][0]].l == y )
        return x;
    else if( lar[z].l <= y )
        {
            //cout << x << ' ' << y << ' ' << jm << endl;
            return lca_dc( x, y, jm-1 );
        }
    else
        {
            //cout << x << ' ' << y << ' ' << jm <<  'l' << endl;
            return lca_dc( z, y, jm );
        }
}

int fi_max_pa( int x, int y, int jm ) /// maximun parent les than a value y
{
    int z = sp_t[x][jm];
    if( jm == -1 )
        return x;
    else if( lar[z].v < y )
    {
        //cout << x << ' ' << y << ' ' << jm << 'k' << endl;
        return fi_max_pa( x, y, jm-1 );
    }
    else
    {
        //cout << x << ' ' << y << ' ' << jm << 'l' << endl;
        return  fi_max_pa( z, y, jm );
    }
}

int fi_max( int x, int y, int jm )
{
    int z = sp_t[x][jm];

    if( lar[x].l == lar[y].l )
        return 0;
    else if( lar[z].l < lar[y].l )
    {
        //cout << x << ' ' << y << ' ' << jm << 'k' << endl;
        return fi_max( x, y, jm-1 );
    }
    else
    {
        //cout << x << ' ' << y << ' ' << jm << 'l' << endl;
        return max( fi_max( z, y, jm ), max_t[x][jm] );
    }
}
int fi_min( int x, int y, int jm )
{
    int z = sp_t[x][jm];

    if( lar[x].l == lar[y].l )
        return 1100000;
    else if( lar[z].l < lar[y].l )
    {
        //cout << x << ' ' << y << ' ' << jm << 'k' << endl;
        return fi_min( x, y, jm-1 );
    }
    else
    {
        //cout << x << ' ' << y << ' ' << jm << 'l' << endl;
        return min( fi_min( z, y, jm ), min_t[x][jm] );
    }
}

int mak_sm( int x, int y, int jm )
{
    int z = sp_t[x][jm];

    if( lar[x].l == lar[y].l )
        return x;
   else if( lar[z].l < lar[y].l )
       {
        //cout << x << ' ' << y << 'a' << endl;
        return mak_sm( x, y, jm-1 );
       }
   else
   {
       //cout << z << ' ' << y << 'b' << endl;
       //x = sp_t[x][jm];
       return mak_sm( z, y, jm );
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
        hd = 0;
        re = 0;
        int i, j, x, y,  m, z, a, b, c;

        //cin >> n ;
        sf(n);
        //cout << n << endl;

        ms = log(n) / log(2);
        ms++;

        for( i=1; i<=n; i++ )
        {
            mat[i].clear( );
            cost[i].clear( );
            mat[i].push_back(0);
            cost[i].push_back(0);

        }


        for( i=1; i<n; i++ )
        {
            //x = i+1;
            cin >> x >> y >> z;
            //cout << x << ' ' << y  << ' ' << z << endl;
            mat[y].push_back(x);
            mat[x].push_back(y);
            cost[x].push_back(z);
            cost[y].push_back(z);
            mat[x][0] = mat[x][0]+1;
            mat[y][0] = mat[y][0]+1;
        }

        bfs(1);
        cre_t();
        sf(z);
        pf("Case %d:\n", ca++ );
        for( i=0; i<z; i++ )
        {

            sff( x, y );
            int c = x, d = y;
            if( lar[x].l > lar[y].l )
                x = mak_sm( x, y, ms-1 );
            if( lar[x].l < lar[y].l )
                y = mak_sm( y, x, ms-1 );

            a = fi_lca( x, y, ms-1 );
            b = max( fi_max( c, a, ms-1 ), fi_max( d, a, ms-1 ) );
            int e = min( fi_min( c, a, ms-1 ), fi_min( d, a, ms-1 ) );
            pf("%d %d\n", e, b );
            //cout << b << ' ' << e << endl;
        }

    }

    return 0;

}






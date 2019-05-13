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
    lar[p].v = 1;
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

                lar[x].l = lar[p].l+1;
                lar[x].pa = p;
                max_t[x][0] = lar[x].v;
                sp_t[x][0] = p;
                lar[x].cn = 1;
                que[re] = x;
                re++;
                //cout << x << '(' << lar[x].v << ')' << ' ';

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

            if( x != -1 )
                {
                    max_t[j][i] = max_t[x][i-1];
                    sp_t[j][i] = sp_t[x][i-1];
                }

            else
                {
                    max_t[j][i] = max_t[x][i-1];
                    sp_t[j][i] = -1;
                }
        }
    }
}


int fi_max( int x, int y, int jm )
{
    int z = sp_t[x][jm];
    if( jm == -1 )
        return x;
    else if( lar[z].v < y )
    {
        //cout << x << ' ' << y << ' ' << jm << 'k' << endl;
        return fi_max( x, y, jm-1 );
    }
    else
    {
        //cout << x << ' ' << y << ' ' << jm << 'l' << endl;
        return  fi_max( z, y, jm );
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
        sff(n, m);
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
            sff( y, z );
            //cin >> y >> z ;
            y++;
            //cout << x << ' ' << y  << ' ' << z << endl;
            mat[y].push_back(x);
            mat[x].push_back(y);
            lar[x].v = z;
            //cost[x].push_back(z);
            //cost[y].push_back(z);
            mat[x][0] = mat[x][0]+1;
            mat[y][0] = mat[y][0]+1;
        }

        bfs(1);
        cre_t();

        pf("Case %d:\n", ca++ );
        for( i=0; i<m; i++ )
        {

            sff( x, y );
            int c = x, d = y;
            x++;
            a = fi_max( x, y, ms-1 );
            //b = fi_max( c, y, ms-1 );;
            pf("%d\n", a-1 );
            //cout << b << ' ' << e << endl;
        }

    }

    return 0;

}





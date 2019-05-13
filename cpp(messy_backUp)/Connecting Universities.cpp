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
}arr[500001];

vector <int> mat[200001]; ///adjecency matrix
struct info0
{
    int v, l, pa, cn, dis, chk, lf, ri;
}lar[200001]; // array of info about input

int que[200001], hd, re, iv, n, sp_t[200001][20], ms, max_t[200001][20], min_t[200001][20], stk[100001], top, len;

///**************BFS*********
void bfs( int p ) ///bfs
{
    min_t[1][0] = 1111111;
    lar[p].l = 1;
    lar[p].pa = -1;
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
                //cout << x << '(' << mat[p][i] << ')' << ' ';
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
void dfs( int p )
{
    if( lar[p].cn == 1 )
    {
        //top++;
        //stk[top] = p;
        //cout << p << '(' << 1 << ')' << ' ';
        arr[len].v = 1;
        lar[p].lf = len;
        lar[p].cn = 2;
        len++;

        for( int i=1; i<=mat[p][0]; i++ )
        {
            dfs(mat[p][i]);
        }
        //cout << p << '(' << 0 << ')' << ' ';
        arr[len].v = 0;
        lar[p].ri = len;
        len++;
        top--;

    }

}

///******Create sparce table*********
void cre_t()
{
    for(int i=1; i<ms; i++ )
    {
        for(int j=1; j<=n; j++ )
        {
            int x = sp_t[j][i-1];

            if( x != -1 )
                {
                    sp_t[j][i] = sp_t[x][i-1];
                }

            else
                {
                    sp_t[j][i] = -1;
                }
        }
    }
}

///****************find lca ***********
int fi_lca( int x, int y, int jm )
{
    if( sp_t[x][jm] == sp_t[y][jm] )
   {
       ////cout << sp_t[x][jm] << ' ' << sp_t[y][jm] << 'k' << endl;;
       if( x == y )
        return x;
       else if( jm == 0 )
        return sp_t[x][jm];
       else
        return fi_lca( x, y, jm-1 );
   }
   else
   {
       ////cout << sp_t[x][jm] << ' ' << sp_t[y][jm] << 'l' << endl;
       x = sp_t[x][jm];
       y = sp_t[y][jm];
       return fi_lca( x, y, jm );
   }
}


///*********make x and y same level`s node***********
int mak_sm( int x, int y, int jm )
{
    int z = sp_t[x][jm];

    if( lar[x].l == lar[y].l )
        return x;
   else if( lar[z].l < lar[y].l )
       {
        ////cout << x << ' ' << y << 'a' << endl;
        return mak_sm( x, y, jm-1 );
       }
   else
   {
       ////cout << z << ' ' << y << 'b' << endl;
       //x = sp_t[x][jm];
       return mak_sm( z, y, jm );
   }
}

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

int br[200001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    memset( sp_t, -1, sizeof(sp_t) );
    memset( lar, 0, sizeof(lar) );
    memset( arr, 0, sizeof(arr) );
    top = -1;
    hd = 0;
    re = 0;
    len = 1;
    LL i, j, k, x, y, t = 0,  m, z, a, b, c, e, f, g, h;

    cin >> n >> k;
    //sff(n, k);
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

    k = k*2;
    for( i=0; i<k; i++ )
    {
      cin >> br[i];
    }

    for( i=1; i<n; i++ )
    {
        //x = i+1;
        //sff( x, y );
        cin >> x >> y;
        //cout << x << ' ' << y  << ' ' << z << endl;
        mat[y].push_back(x);
        mat[x].push_back(y);
        mat[x][0] = mat[x][0]+1;
        mat[y][0] = mat[y][0]+1;
    }

    bfs(1);
    dfs(1);
    cre_t();

    pair <int,int> yo[200011];
    pair <int,int> pp;

    for( i=0; i<k; i++ )
    {
      yo[i] = make_pair( lar[br[i]].lf, br[i] );
    }

    sort( yo, yo+k );
    k = k/2;
    j = k;
    for( i=0; i<k; i++,j++ )
    {
        a = yo[i].second;
        b = yo[j].second;
        x = a;
        y = b;

        if( lar[a].l > lar[b].l )
            x = mak_sm( a, b, ms-1 );
        if( lar[b].l > lar[a].l )
            y = mak_sm( b, a, ms-1 );
        z = fi_lca( x, y, ms-1 );

        t += ( ( lar[a].l-lar[z].l ) + ( lar[b].l - lar[z].l ) );
        //cout << yo[i].first << ' ' << yo[i].second << endl;
    }

    cout << t << endl;

    return 0;

}





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
        //cout << p << '(' << lar[p].v << ')' << ' ';
        arr[len].v = lar[p].v;
        lar[p].lf = len;
        lar[p].cn = 2;
        len++;

        for( int i=1; i<=mat[p][0]; i++ )
        {
            dfs(mat[p][i]);
        }
        ////cout << p << '(' << lar[p].v << ')' << ' ';
        arr[len].v = lar[p].v * -1;
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


///*************segment tree part**************
struct info
{
   int s[13];

}tree[8*MAX];

void init(int idx, int b, int e )
{

    if( b == e )
    {
        int x = arr[b].v;

        if( x > 0 )
        cnd.s[x] = 1;
        else
        {
          x = x*-1;
          cnd.s[x] = -1;
        }
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);
    for( int i=1; i<=10; i++ )
        cnd.s[i] = tree[lnd].s[i] + tree[rnd].s[i];

    ////cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}

void update_node(int idx, int b, int e, int v)
{
    for(int i=1; i<=10; i++ )
            cnd.s[i] = 0;
        if(v>0)
        cnd.s[v] = 1;
        else
        {
            v *= -1;
            cnd.s[v] = -1;
        }
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    for(int i=1; i<=10; i++ )
        cnd.s[i] = tree[lnd].s[i] + tree[rnd].s[i];
}


int query(int idx, int b, int e, int st, int en, int t )
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.s[t];

    int lft = query(lnd, b, (b+e)/2, st, en, t);
    int rgt = query(rnd, ((b+e)/2)+1, e, st, en, t);
    return lft + rgt;
}
///**********segment tree end**********
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
        memset( tree, 0, sizeof(tree) );
        memset( arr, 0, sizeof(arr) );
        top = -1;
        hd = 0;
        re = 0;
        len = 1;
        int i, j, x, y,  m, z, a, b, c;

        //cin >> n ;
        sff(n, m);
        //cout << n << endl;

        ms = log(n) / log(2);
        ms++;

        for( i=1; i<=n; i++ )
        {
            sf( lar[i].v );
            mat[i].clear( );
            //cost[i].clear( );
            mat[i].push_back(0);
            //cost[i].push_back(0);

        }


        for( i=1; i<n; i++ )
        {
            //x = i+1;
            sff( x, y );
            //cout << x << ' ' << y  << ' ' << z << endl;
            mat[y].push_back(x);
            mat[x].push_back(y);
            mat[x][0] = mat[x][0]+1;
            mat[y][0] = mat[y][0]+1;
        }

        bfs(1);
        dfs(1);
        cre_t();
        init( 1, 1, len );

        //pf("Case %d:\n", ca++ );
        for( j=0; j<m; j++ )
        {
            int o;
            sf(o);

            if( 1 == o )
            {

            int maxx = 0, l;
            sff( x, y );
            int c = x, d = y;
            if( lar[x].l > lar[y].l )
                x = mak_sm( x, y, ms-1 );
            if( lar[x].l < lar[y].l )
                y = mak_sm( y, x, ms-1 );

            a = fi_lca( x, y, ms-1 );
            //cout << a << endl;
            for(int i=1; i<=10; i++)
            {
                l = query( 1, 1, len, lar[a].lf, lar[c].lf, i ) + query( 1, 1, len, lar[a].lf+1, lar[d].lf, i );
                //cout << i << ' ' << query( 1, 1, len, lar[a].lf, lar[c].lf, i )  << ' ' << query( 1, 1, len, lar[a].lf+1, lar[d].lf, i ) << endl;
                maxx = max( maxx, l );
            }
            pf("%d\n",maxx );

            }

            else
            {
                sff( x, y );
                update( 1, 1, len, lar[x].lf, lar[x].lf, y );
                update( 1, 1, len, lar[x].ri, lar[x].ri, y*-1 );
            }
            //cout << b << ' ' << e << endl;
        }

    }

    return 0;

}




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
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<LL>::iterator ii;

struct Node{
    LL lazy, mn;
};

Node tree[4*MAX];

void update_node(LL idx, LL b, LL e, LL v)
{
    cnd.mn = v;
}

void init(LL idx, LL b, LL e )
{
    if( b == e )
    {
        if( b == 1 )
            cnd.mn = 0;
        else
            cnd.mn = maxx;
        return ;
    }

    init(lnd, b, (b+e)/2 );
    init(rnd, ((b+e)/2)+1, e );
    cnd.mn = min(tree[lnd].mn, tree[rnd].mn);
}
LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return maxx;
    if(st <= b && en >= e)
        return cnd.mn;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return min(lft,rgt);
}

void update(LL idx, LL b, LL e, LL st, LL en, LL v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.mn = min(tree[lnd].mn, tree[rnd].mn);
}

struct noode
{
    LL v, pa, l;
}dfa[100010];

vector<LL> mat[100010], tik[100010], val[100010];
LL vis[100010], stk[100010], top, mn[10010], n;

void dfs( LL p )
{
    LL x, y, z;
    if( p != 1 )
    {
        y = 0;

        if( y < tik[p].size() )
        {
            while(  y < tik[p].size() )
        {
            z = max( (LL)1, top-tik[p][y]+1);
            x = query( 1, 1, n,  z, top );
            //cout << z << ' ' << top << ' ' << x << endl;
            if( y == 0 ) mn[p] = val[p][y]+x;
            else mn[p] = min( mn[p], val[p][y]+x );
            mn[p] = min( maxx, mn[p] );
            y++;
        }

        }
        else
        mn[p] = maxx;
        //cout << mn[p];
        //cout << endl << endl;
    }

    if( dfa[p].v == 0 )
    {

        dfa[p].v = 1;
        for(LL i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                if( vis[p] == 0 )
                   stk[++top] = p, vis[p] = 1, update( 1, 1, n, top, top, mn[p] );

                dfa[x].l = dfa[p].l;
                dfa[x].pa = p;
                dfs(x);
            }
        }
        if( vis[p] != 0 && top > 0 )
            vis[p] = 0, top--;
    }
}




int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    LL i, j, x, y, m, a, b, c, v, k, w;

    cin >> n >> m;

    for( i=0; i<n-1; i++ )
    {
        cin >> x >> y;

        mat[x].push_back( y );
        mat[y].push_back( x );
    }



    for( i=0; i<m; i++ )
    {
       cin >> v >> k >> w;
       tik[v].push_back(k);
       val[v].push_back(w);
    }

    init( 1, 1, n );
    stk[1] = 1;
    top = 1;
    mn[1] = 0;
    vis[1] = 1;
    dfs(1);

    cin >> m;

    while(m--)
    {
        cin >> a;
        if( a == 1 )
            cout << 0 << endl;
        else
            cout << mn[a] << endl;
    }



    return 0;

}




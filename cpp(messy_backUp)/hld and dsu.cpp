#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i<=k; i++)
#define PB push_back
#define MAX 100010
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define Val first
#define lazy second

typedef pair<int,int> PR;

int bit[MAX];
void updatePos(int p,int dv) {for (; p <= MAX; p += p & (-p)) bit[p] += dv;}
int query(int p) {int rv = 0;for (; p; p -= p & (-p)) rv += bit[p];return rv;}
void update(int l,int r,int dv) { updatePos(l, dv); updatePos(r + 1, -dv);}

vector<int> mat[MAX];
int sz[MAX], paa[MAX], lev[MAX], dfa[MAX], pos[MAX], head[MAX], mxChild[MAX], ti, rev[MAX];
set<int> sota;
set<int>::iterator it;

void dfs(int p,int pa)
{
    sz[p] = 1; mxChild[p] = -1;
    for(auto x : mat[p])
    {
        if(x == pa) continue;

        paa[x] = p; lev[x] = lev[p] + 1;
        dfs(x, p); sz[p] += sz[x];

        if(sz[ mxChild[p] ] < sz[x]) mxChild[p] = x;

    }
}

void init_hld(int p,int pa,int hd)
{
    head[p] = hd; pos[p] = ++ti; rev[ti] = p;

    if(mxChild[p] != -1) init_hld(mxChild[p], p, hd);
    for(auto x : mat[p])
    {
        if(x == pa || mxChild[p] == x) continue;
        init_hld(x, p, x);
    }
}

int saved[MAX], col[MAX];

void update_tree(int u,int v)
{
    int r1 = pos[ head[u] ];
    it = sota.lower_bound( pos[u] );
    if(it != sota.begin()) it--;
    int r2 = *it;

    if(r1 <= r2 && r2 <= pos[ u ])
    {
        saved[ rev[r2] ] += v;
        update(r2 + 1, pos[u], v);
    }
    else
    {
        update(r1, pos[u], v);
        r1 = paa[ rev[r1] ];

        if(!col[r1]) saved[r1] += v;
        else update_tree(r1, v);
    }
}

int query_tree(int u)
{
    int r1 = pos[ head[u] ], r2;


    it = sota.lower_bound( pos[u] );
    if(it != sota.begin()) it--; r2 = *it;

    if(r1 <= r2 && r2 <= pos[ u ]) return r2 + 1;
    else
    {
        if(!col[ paa[ rev[r1] ] ]) return r1;
        else query_tree( paa[ rev[r1] ] );
    }
}

void changeCol(int u)
{
    if(!col[u])
    {
        update_tree(u, saved[u] + 1);
        sota.erase( pos[u] );
    }
    else
    {
        saved[u] = query(pos[u]);
        update_tree(u, -saved[u]);
        sota.insert( pos[u] );
        saved[u]--;

    }
    col[u] ^= 1;
}

#define F first
#define S second

PR que[MAX];
int prin[MAX];

int main()
{
    ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n, u, v, ty, q; ti = 0;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> u >> v;

        mat[u].PB( v );
        mat[v].PB( u );
    }

    cin >> q;
    FOR(i,0,q-1) cin >> que[i].F >> que[i].S;

    dfs(1, 1);
    init_hld(1, 1, 1);
    ///FOR(i,1,n) cout << i << ' ' << pos[i] << ' ' << head[i] << endl;
    FOR(i,0,n) sota.insert( i );

    FOR(i,0,q-1)
    {
        int u = que[i].F, v = que[i].S;
        if(u) changeCol( v );
        else if(col[v]) {prin[i] = query(query_tree( v ));}
    }

    FOR(i,1,n) if(!col[i]) changeCol( i );
    FOR(i,0,q-1)
    {
        int u = que[i].F, v = que[i].S;
        if(u) changeCol( v );
        else if(col[v]) prin[i] = query(query_tree( v ));

        //if(!u) continue;
        //cout << endl << endl << "OJK dude " << v  << endl;
        //FOR(i,1,n) cout << i << ' ' << query( query_tree( i ) ) << ' ' << rev[ query_tree( i ) ] * col[i] << endl;
    }

    FOR(i,0,q-1) if(prin[i]) cout << prin[i] << endl;

    return 0;
}


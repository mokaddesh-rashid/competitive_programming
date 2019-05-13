#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int sparceT[17][MAX], lev[MAX], n;
vector<int> mat[MAX];

void dfs(int p,int pa)
{
    for(auto x : mat[p])
    {
        if(x == pa) continue;
        lev[x] = lev[p] + 1;
        sparceT[0][x] = p;
        dfs(x, p);
    }
    return;
}

void make_sparceT()
{
    FOR(i,1,16)
        FOR(j,1,n)
        {
            int x = sparceT[i - 1][j];
            if(x == -1) continue;
            sparceT[i][j] = sparceT[i - 1][x];
        }
}

int make_same(int u,int v,int jump)
{
    while(true)
    {
        int to = sparceT[jump][u];

        if(lev[u] == v) return u;
        else if(to == -1 || lev[to] < v) jump--;
        else u = to;
    }

}


int fin_Lca(int u,int v,int jump)
{
    while(true)
    {
        int t1 = sparceT[jump][u], t2 = sparceT[jump][v];

        if(u == v) return u;
        if(jump == 0 && t1 == t2) return t1;

        else if(t1 == t2) jump--;
        else u = t1, v = t2;
    }
}

int lca(int u,int v)
{
    if(lev[u] < lev[v]) swap(u, v);
    u = make_same(u, lev[v], 16);
    return fin_Lca(u, v, 16);
}

int getVal(int a,int b,int u,int v)
{
    int l = lca(a, u);

    if(l != a && l != u) return 0;

    int x = max(lev[a], lev[u]);
    int y = lev[ lca(b, v) ];

    return max(0, (y - x) + 1);

}

int dis(int u,int v)
{
    return lev[u] + lev[v] - 2*lev[ lca(u, v) ];
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int u, v, q, a, b;

    cin >> n >> q;
    FOR(i,1,n-1)
    {
        cin >> u >> v;
        mat[u].PB( v );
        mat[v].PB( u );
    }

    mem(sparceT, -1);
    dfs(1, 1);
    make_sparceT();

    FOR(t,1,q)
    {
        cin >> a >> b >> u >> v;

        if(lev[a] < lev[b]) swap(a, b);
        if(lev[u] < lev[v]) swap(u, v);

        int l1 = lca(a, b), l2 = lca(u, v);

        int prin = getVal(l1, a, l2, u);
        if(l2 != v)
        {
            int dude = make_same(v, lev[l2] + 1, 16);
            prin += getVal(l1, a, dude, v);
        }

        if(l1 != b)
        {
            l1 = make_same(b, lev[l1] + 1, 16);
            prin += getVal(l1, b, l2, u);
            if(l2 != v)
            {
                int dude = make_same(v, lev[l2] + 1, 16);
                prin += getVal(l1, b, dude, v);
            }
        }

        cout << prin << endl;
    }


    return 0;
}

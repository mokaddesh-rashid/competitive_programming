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
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

pair<LL,PR> dis[MAX];
vector<PR> mat[MAX];

void dfs(LL p,LL pa,LL t)
{
    for(auto x : mat[p])
    {
        if(x.F == pa) continue;

        if(t) dis[x.F].S.F = dis[p].S.F + x.S;
        else  dis[x.F].S.S = dis[p].S.S + x.S;

        dfs(x.F, p, t);
    }

    return;
}

multiset<LL> sota;
LL on[MAX], id[MAX];

class cmp
{
    public:
    bool operator()(LL a,LL b)
    {
        return dis[a].F > dis[b].F;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL n, u, v, c, q;

    cin >> n >> q;
    FOR(I,1,n - 1)
    {
        cin >> u >> v >> c;
        mat[u].PB( MP(v, c) );
        mat[v].PB( MP(u, c) );
    }
    dfs(1, 1, 1);
    dfs(n, n, 0);

    FOR(i,1,n) dis[i].F = dis[i].S.F - dis[i].S.S;
    FOR(i,1,n) id[i] = i;

    sort(id + 1, id + n + 1, cmp());
    LL prin = 0;

    FOR(i,1,n)
    {
        LL p = id[i];
        for(auto x : mat[p])
        {
            if(!on[ x.F ]) continue;
            sota.erase( sota.find( dis[x.F].S.S ) );
        }
        if(!sota.empty())
        {
            v = *(sota.rbegin());
            prin = max(prin, v + dis[p].S.F);
        }
        for(auto x : mat[p])
        {
            if(!on[ x.F ]) continue;
            sota.insert( dis[x.F].S.S );
        }

        sota.insert( dis[p].S.S );
        on[ p ] = 1;
    }

    FOR(i,0,q-1)
    {
        cin >> c;
        cout << min(dis[1].S.S, prin + c) << endl;
    }


    return 0;
}


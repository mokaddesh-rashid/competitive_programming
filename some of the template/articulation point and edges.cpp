#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> pii;
const int MAX = (5e4) + 5;

struct EDGE
{
    int u, v, id;
}ed[MAX];

int n, m, low[MAX], dis[MAX], ti;
vector<pii> mat[MAX];
vector<int> edgeList, nodeList;

int arti(int p,int pa)
{
    int canAdd = (p != pa);

    dis[p] = low[p] = ti++;
    for(pii x : mat[p])
    {
        if(x.F == pa) continue;
        else if(dis[x.F] != -1) low[p] = min(low[p], dis[x.F]);
        else
        {
            low[p] = min(low[p], arti(x.F, p));

            if(dis[p] < low[x.F]) edgeList.PB( x.S );
            if(dis[p] <= low[x.F] && canAdd) nodeList.PB( p );

            canAdd = 1;
        }
    }

    return low[p];
}

int main()
{
    inf;
    mem(dis, -1); mem(low, -1);
    nodeList.clear(); edgeList.clear();
    int u, v;

    sff(n, m);
    FOR(i,1,n) mat[i].clear();
    FOR(i,1,m)
    {
        sff(u, v);
        ed[i] = {u, v, i};

        mat[u].PB( {v, i} );
        mat[v].PB( {u, i} );
    }
    arti(1, 1);
    cout << "Articulation nodes are : ";
    for(int x : nodeList) cout << x << "  ";
    cout << endl;
    cout << "Articulation bridges are :\n";
    for(int x : edgeList) cout << ed[x].u << ' ' << ed[x].v << endl;
    return 0;
}


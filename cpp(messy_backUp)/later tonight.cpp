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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

pair<PR,PR> ed[MAX];
vector<PR> mat[MAX];
int n, sz[MAX], pa[MAX], newBie[MAX], re[MAX], vis[MAX];
map<int,int> mop;
LL prin[MAX];

int finPa(int p)
{
    return (p == pa[p]) ? p : (pa[p] = finPa(pa[p]));
}

void mergeAB(int a,int b)
{
    a = finPa(a);
    b = finPa(b);

    if(a == b) return;
    pa[a] = b;
    sz[b] += sz[a];
    return;
}

int getId(int v)
{
    v = finPa( v );
    if(mop[v] != 0) return mop[v];

    int m = mop.size();
    re[m] = v;
    return mop[v] = m;

}

void dfs(int p,int pa)
{
    ///cout << p << ' ' << re[p] << ' ' << sz[ re[p] ] << endl;
    newBie[p] = sz[ re[p] ]; vis[ p ] = 1;
    for(auto x : mat[p])
    {
        if(x.F == pa) continue;

        dfs(x.F, p);
        newBie[p] += newBie[ x.F ];
    }
}

void dfs2(int p,int pa,int all)
{
    for(auto x : mat[p])
    {
        if(x.F == pa) continue;
        int vi = all - newBie[x.F], vo = newBie[x.F];
        prin[x.S] = (LL)vi * vo;
        dfs2(x.F, p, all);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int x, y, c;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> x >> y >> c;
        ed[i] = MP( MP(c, i), MP(x, y) );
    }
    sort(ed + 1, ed + n);

    FOR(i,1,n)
    {
        pa[i] = i;
        sz[i] = 1;
    }

    FOR(i,1,n-1)
    {
        if(ed[i].F.F != ed[i - 1].F.F)
        {
            int j = i;
            while(ed[i].F.F == ed[j].F.F) j++;

            mop.clear();
            FOR(p,i,j-1)
            {
                int v1 = getId( ed[p].S.F );
                int v2 = getId( ed[p].S.S );
            }

            int so = mop.size();
            FOR(k, 1, so) mat[k].clear(), vis[k] = 0;

            FOR(p,i,j-1)
            {
                int v1 = getId( ed[p].S.F );
                int v2 = getId( ed[p].S.S );

                mat[ v1 ].PB( MP(v2, ed[p].F.S) );
                mat[ v2].PB( MP(v1, ed[p].F.S) );
            }

            FOR(p,i,j-1)
            {
                int v1 = getId( ed[p].S.F );
                if(!vis[v1])
                {
                    dfs( v1, v1 );
                    dfs2( v1, v1, newBie[v1]);
                }
            }

            FOR(p,i,j-1)
            {
                mergeAB(ed[p].S.F, ed[p].S.S);
            }
        }
    }

    LL mo = 0, cc = 0;

    FOR(i,1,n-1)
    {
        ///cout << prin[i] << endl;
        if(mo < prin[i]) mo = prin[i], cc = 0;
        if(mo == prin[i]) cc++;
    }

    cout << 2*mo << ' ' << cc << endl;
    FOR(i,1,n-1)
    if(prin[i] == mo) cout << i << ' ';

    return 0;
}


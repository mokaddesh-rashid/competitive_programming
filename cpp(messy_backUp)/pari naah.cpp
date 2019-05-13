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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int INF = 1000000000;

int src, des, node;
vector<int> typ[110];
vector<int> adjl[110];
vector<int> rc[110];///residual capacity
vector<int> rev_idx[110];///reverse_index

void poriskar()
{
    FOR(u,0,node)
    {
        FOR(p, 0, (int)adjl[u].size()-1)
        {
            int v = adjl[u][p];
            if(!typ[u][p]) continue;

            rc[u][p] += rc[v][ rev_idx[u][p] ];
            rc[v][ rev_idx[u][p] ] = 0;
            ///if(rc[u][p] != INF && rc[u][p]) cout << u << ' ' << v << ' ' << rc[u][p] << endl;
        }
    }
}

void add_edge(int u,int v,int w)
{
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(0);///one directional
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
    typ[u].PB( 1 );
    typ[v].PB( 0 );
}

int lev[110];
int vis[110];
bool dinic_bfs()  { //this finds level of all nodes from source
    mem(vis, 0);
    mem(lev, 0);
    lev[src] = 0;
    vis[src] = 1;
    queue<int> myq;
    myq.push(src);
    while(!myq.empty()) {
        int u = myq.front();
        myq.pop();
        int sz = adjl[u].size();
        FOR(i, 0, sz - 1)   {
            int v = adjl[u][i];
            if(rc[u][i] == 0)   {
                continue;
            }
            if(vis[v] == 0) {
                vis[v] = 1;
                lev[v] = lev[u] + 1;
                myq.push(v);
            }
        }
    }
    if(vis[des])    {
        return 1;
    }
    return 0;
}

int shuru[110];
int dinic_dfs(int u, int flow) {
    //cout << u << " " << flow << "\n";
    if(u == des)    {
        return flow;
    }
    FOR(i, shuru[u], (int)adjl[u].size() - 1)   {
        shuru[u] = i;
        int v = adjl[u][i];
        if((lev[v] == lev[u] + 1) && (rc[u][i]))    {
            int ff = dinic_dfs(v, min(flow, rc[u][i]));
            if(ff) {
                rc[u][i] -= ff;
                rc[v][ rev_idx[u][i] ] += ff;

                return ff;
            }
        }
    }
    shuru[u] = adjl[u].size();
    return 0;
}

int dinic() {

    int ans = 0;
    while(dinic_bfs()) {
        mem(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, INF);
            if(ff == 0)break;
            ans += ff;
        }
    }

    return ans;
}

int rev_edge(int u,int tar,int ff)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        int v = adjl[u][i];
        if(v == tar)
        {
            if(!typ[u][i]) continue;
            //cout << u << ' ' << v << ' ' << rc[u][i] << endl;
            if(!rc[u][i]) return 1;

            rc[u][i] -= ff;
            rc[v][ rev_idx[u][i] ] += ff;

            return 0;
        }
    }
    return 1;
}

void decreaseCap(int u,int tar)
{
    FOR(i, 0, (int)adjl[u].size() - 1)
    {
        if(!typ[u][i]) continue;

        int v = adjl[u][i];
        if(v == tar)
            rc[v][ rev_idx[u][i] ] -= 1;
    }
    return;
}



string str;
int cnt[30], mask[MAX], bitCnt[MAX], n;

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;

    int x, q, p;

    cin >> str; n = str.size();
    FOR(i,0,n-1)
         x = str[i] - 'a', cnt[x]++;

    cin >> q;
    FOR(i,1,q)
    {
        cin >> p >> str;

        int v = 0;
        FOR(ko,0,str.size() - 1)
        {
            int so = str[ko] - 'a';
            v |= (1<<so);
        }
        mask[p] = v ^ ((1<<6) - 1);
    }

    FOR(i,1,n)
    {
        mask[i] = mask[i] ^ ((1<<6) - 1);
        bitCnt[ mask[i] ]++;
    }

    src = 6 + (1<<6) + 1; des = 6 + (1<<6) + 2; node = des;
    FOR(i,0,5) add_edge(i, des, cnt[i]);
    FOR(i,0,(1<<6) - 1) add_edge(src, i + 6, bitCnt[i]);

    FOR(i,0,(1<<6) - 1)
    {
        int id = i + 6;
        FOR(ko,0,5)
            if(i & (1<<ko)) add_edge(id, ko, INF);
    }

    if(dinic() == n)
    {
        FOR(i,1,n)
        {
            int u = mask[i];
            u = u + 6;

            FOR(p, 0, (int)adjl[u].size()-1)
            {
                if(adjl[u][p] == src) continue;

                poriskar();
                int v = adjl[u][p];

                if( rev_edge(src, u, 1) ) continue;
                if( rev_edge(v, des, 1) ) continue;
                ///cout << i << ' ' << v << ' ' << dinic() << endl << endl;

                if(dinic() == n - i)
                {
                    char ch = v + 'a';
                    decreaseCap(src, u);
                    decreaseCap(v, des);
                    cout << ch;
                    break;
                }
            }
            ///break;
        }
    }
    else cout << "Impossible" << endl;

    return 0;
}

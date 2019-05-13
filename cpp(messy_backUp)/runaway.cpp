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
#define MAX 100100
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int MAXO = 1e9;

int node, edge;
int src, des;
vector<int> adjl[MAX];
vector<int> rc[MAX];
vector<int> rev_idx[MAX];

void add_edge(int u,int v,int w)
{
    ///cout << "add " << u << ' ' << v << ' ' << w << endl;
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(0);
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

int lev[MAX];
int vis[MAX];
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

int shuru[MAX];
int dinic_dfs(int u, int flow) {

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

int dinic()
{
    int ans = 0;
    while(dinic_bfs()) {
        mem(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, MAXO);
            //cout << "\n";
            if(ff == 0)break;
            ans += ff;
        }
    }

    return ans;
}


string in[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int getId(string str) {FOR(i,0,5) if(in[i] == str) return i;}
int n, ex, v, q;
string str, toot;


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    n = 5; src = n + 1; des = src + 1; ex = des + 1;
    FOR(i,0,n)
    {
        cin >> v;
        add_edge(src, i, v);
    }

    cin >> q;
    FOR(p,1,q)
    {
        cin >> toot;
        int m = toot.size(); str = "";
        FOR(i,0,m-1)
        {
            if(toot[i] == ',')
            {
                add_edge(getId(str), ex + p, 1);
                str = "";
            }
            else str = str + toot[i];
        }

        add_edge(getId(str), ex + p, 1);
        str = "";
        add_edge(ex + p, des, 1);
    }

    if(dinic() == q)
    {
        cout << "YES" << endl;
        FOR(p,1,q)
        {
            int u = ex + p;

            int sz = adjl[u].size();
            FOR(i, 0, sz - 1)
            {
                int v = adjl[u][i];
                if(v == des) continue;
                if(rc[u][i]) cout << in[v] << endl;
            }
        }
    }
    else cout << "NO" << endl;

    return 0;
}




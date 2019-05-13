#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
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
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;


const int MAXN = 2*101*101;
const int INF = 1000000000;


struct edge {
    int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN], m, row, col, node;
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
    ////cout<<"added"<<a<<' '<<b<<' '<<cap<<NL;
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, sizeof(d));
    d[s] = 0;
    ///cout<<"SHIT"<<s<<' '<<qh<<' '<<qt<<' '<<d[t]<<NL;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        ///cout<<"B"<<v<<NL;
        for (int i=0; i<g[v].size(); ++i)
        {
            int id = g[v][i],
                to = e[id].b;
           /// cout<<v<<" abal "<<to<<NL;

            if (d[to] == -1 && e[id].flow < e[id].cap)
            {
                q[qt++] = to;
                d[to] = d[v] + 1;
                ///cout<<v<<' '<<to<<NL;
            }
        }
    }
    ///cout<<s<<' '<<t<<NL;
    return d[t] != -1;
}

int dfs (int v, int flow) {

    //cout<<v<<NL;
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int cnt = 0;
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, t * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
        if(cnt++>1000)break;
    }
    ///cout<<flow<<NL;
    return flow;
}


int in[110][110], out[110][110];
string str[MAX];
char abal[MAX];

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int main()
{
    int tc;
    sf(tc);
    FOR(tt, 1, tc)
    {
        int c = 0, d = 0;
        sff(n, m);
        row = n; col = m;

        FOR(i,0,n-1)
        {
            scanf("%s", abal);
            str[i] = abal;
        }

        FOR(i,0,n-1)
        FOR(j,0,m-1) in[i][j] = ++c;

        FOR(i,0,n-1)
        FOR(j,0,m-1) out[i][j] = ++c;

        s = 0; node = t = c + 1;
        e.clear();
        FOR(i, 0, node) g[i].clear();

        FOR(i,0,n-1)
        FOR(j,0,m-1) add_edge(in[i][j], out[i][j], 1);

        FOR(i,0,n-1)
        FOR(j,0,m-1)
        {
            c = 0;
            FOR(k,0,3)
            {
                int a = fx[k] + i, b = fy[k] + j;
                if(valid(a, b))
                {
                    if(str[a][b] == '.') add_edge(out[i][j], in[a][b], 1);
                }
                else c = 1;
            }
            if(c) add_edge(out[i][j], t, 1);
            if(str[i][j] == '*') add_edge(s, in[i][j], 1), d++;
        }
        ///cout << d << ' ' << dinic() << endl;
        if(d == dinic()) pf("Case %d: yes\n", tt);
        else pf("Case %d: no\n", tt);
    }
    return 0;
}

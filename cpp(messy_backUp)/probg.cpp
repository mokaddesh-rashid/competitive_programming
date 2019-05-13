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
#define MAX 100100
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int ar[MAX], n, mask[MAX], cnt[10], id[MAX], cId, val[MAX];
string str;

const int MAXN = 100100;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow, oldCap, oldFlow;
};

int s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap)
{
	edge e1 = { a, b, cap, 0, 0, 0};
	edge e2 = { b, a, 0, 0, 0, 0};
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof(d));
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (int i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
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
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, sizeof(ptr));
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

void rev_flow(int v,int tar,int ff)
{
    for (int i=0; i<g[v].size(); ++i)
    {
        int id = g[v][i], to = e[id].b;
        if (tar == to)
        {
            e[id].flow -= ff;
			e[id^1].flow += ff;
        }
    }
    return;
}

void off_edge(int v,int tar)
{
    for (int i=0; i<g[v].size(); ++i)
    {
        int id = g[v][i], to = e[id].b;
        if (tar == to)
        {
            e[id] = { v, to, 0, 0, e[id].cap, e[id].flow };
			e[id^1] = { v, to, 0, 0, e[id^1].cap, e[id^1].flow };
        }
    }
    return;
}

void on_edge(int v,int tar)
{
    for (int i=0; i<g[v].size(); ++i)
    {
        int id = g[v][i], to = e[id].b;
        if (tar == to)
        {
            ///cout << v << ' ' << tar << ' ' << e[id].oldCap << ' ' << e[id].oldFlow << endl;
            e[id] = { v, to, e[id].oldCap, e[id].oldFlow, 0, 0 };
			e[id^1] = { v, to, e[id^1].oldCap, e[id^1].oldFlow, 0, 0 };
        }
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    int k, v, m;

    cin >> n >> m;

    s = 0; t = n + m + 1;
    e.clear();
    FOR(i,0,t + 1) g[i].clear();

    FOR(i,1,n) add_edge(s, i, 1);
    FOR(i,1,m)
    {
        cin >> v;
        add_edge(i + n, t, v);
    }
    FOR(i,1,n)
    {
        cin >> k;
        FOR(ko, 1, k)
        {
            cin >> v;
            add_edge(i, v + n, 1);
        }
    }
    cout << dinic() << " applicant(s) can be hired." << endl;

    FOR(v,1,n)
    {
        for (int i = (int)g[v].size() - 1; i >= 0; --i)
        {
            int id = g[v][i], to = e[id].b;

            if (e[id].flow && to != s && to != t)
            {
                rev_flow(s, v, 1);
                off_edge(v, to);
                rev_flow(to, t, 1);

                if(dinic());
                else
                {
                    cout << v << ' ' << to - n << endl;
                    rev_flow(s, v, -1);
                    on_edge(v, to);
                    rev_flow(to, v, -1);
                    break;
                }
            }
            else  if (to != s && to != t) off_edge(v, to);
        }
    }

    FOR(v,1,n)
    {
        for (int i = (int)g[v].size() - 1; i >= 0; --i)
        {
            int id = g[v][i], to = e[id].b;

            if (e[id].flow && to != s && to != t)
            {
                cout << v << ' ' << to - n << endl;
            }
        }
    }


    return 0;
}

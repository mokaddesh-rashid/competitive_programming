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
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int MAXN = 10010;
const int INF = 10000000;

struct edge {
	int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	mem(d, -1);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
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
		mem(ptr, 0);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

vector<int> female, male;
vector<int> mat[2][MAX];
int ara[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    ///outf;

    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        char ch;

        cin >> n;
        FOR(i,0,n-1) cin >> ara[i];
        FOR(i,0,n-1)
        {
            cin >> ch;
            if(ch == 'F') female.PB( i );
            else male.PB( i );
        }
        s = n; t = n + 1;

        FOR(i,0,(int)female.size()-1)
            add_edge(s, female[i], 1);


        FOR(i,0,(int)male.size()-1)
            add_edge(male[i], t, 1);

        FOR(i,0,(int)female.size()-1)
        {
            FOR(j,0,(int)male.size()-1)
            {
                if( __gcd( ara[ female[i] ], ara[ male[j] ]) > 1)
                    add_edge(female[i], male[j], 1);
            }
        }

        cout << n - dinic() << endl;

        e.clear();
        FOR(i,0,t) g[i].clear();
        male.clear();
        female.clear();

    }

    return 0;
}

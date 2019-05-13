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


const int INF = 1000 * 1000 * 1000;

struct rib {
	int b, u, c, f;
	size_t back;
};

void add_rib (vector <vector <rib>> & g, int a, int b, int u, int c) {
	rib r1 = {b, u, c, 0, g [b] .size ()};
	rib r2 = {a, 0, -c, 0, g [a] .size ()};
	g [a] .push_back (r1);
	g [b] .push_back (r2);
}

int main ()
{
	int n, m, k;

	n = 7;
	vector <vector <rib>> g (n);
	int s, t;

    s = 0; t = 6;

    add_rib(g, 0, 1, 1, 1);
    add_rib(g, 0, 2, 1, 1);
    add_rib(g, 0, 3, 1, 1);

    add_rib(g, 1, 4, 1, 1);
    add_rib(g, 2, 5, 1, 10);
    add_rib(g, 3, 5, 1, 1);

    add_rib(g, 4, 6, 1, 1);
    add_rib(g, 5, 6, 1, 1);

	///... reading the graph ...

	int flow = 0, cost = 0;
	while (flow <k)
    {
		vector <int> id (n, 0);
		vector <int> d (n, INF);
		vector <int> q (n);
		vector <int> p (n);
		vector <size_t> p_rib (n);

		int qh = 0, qt = 0;
		q [qt ++] = s;
		d [s] = 0;
		while (qh != qt)
        {
			int v = q [qh ++];
			id [v] = 2;
			if (qh == n) qh = 0;
			for (size_t i = 0; i <g [v] .size (); ++ i)
			{
				rib & r = g[v][i];
				if (rf < ru && d[v] + rc < d[rb])
				{
					d [rb] = d [v] + rc;
					if (id [rb] == 0)
					{
						q [qt ++] = rb;
						if (qt == n) qt = 0;
					}
					else if (id [rb] == 2)
					{
						if (--qh == -1) qh = n-1;
						q [qh] = rb;
					}
					id [rb] = 1;
					p [rb] = v;
					p_rib [rb] = i;
				}
			}
		}
		if (d[t] == 100) break;
		int addflow = k - flow;
		for (int v = t; v! = s; v = p [v])
		{
			int pv = p [v]; size_t pr = p_rib [v];
			addflow = min (addflow, g [pv] [pr] .u - g [pv] [pr] .f);
		}
		for (int v = t; v! = s; v = p [v])
		{
			int pv = p [v]; size_t pr = p_rib [v], r = g [pv] [pr] .back;
			g [pv] [pr] .f + = addflow;
			g [v] [r] .f - = addflow;
			cost + = g [pv] [pr] .c * addflow;
		}
		flow + = addflow;
	}

	///... output the result ...

}

#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define sf(n) scanf("%d", &n)

typedef vector<int>     VI;

const int N = int(1e5) + 10;
const int M = int(5e5) + 10;

VI g[N];
VI tree[N], rg[N], bucket[N];
int sdom[N], par[N], dom[N], dsu[N], label[N];
int arr[N], rev[N], T;

int Find(int u,int x=0)
{
	if(u == dsu[u]) return x ? -1 : u;
	int v = Find( dsu[u], x + 1);
	if(v < 0)return u;

	if(sdom[ label[ dsu[u] ] ] < sdom[ label[u] ])
		label[u] = label[ dsu[u] ];

	dsu[u] = v;
	return x ? v : label[u];
}
void Union(int u, int v) //Add an edge u-->v
{
	dsu[v] = u; 	//yup,its correct :)
}
void dfs0(int u)
{
	T++; arr[u] = T; rev[T] = u;
	label[T] = T; sdom[T] = T;dsu[T] = T;

	for(int i=0;i<g[u].size();i++)
	{
		int w = g[u][i];
		if(!arr[w]) dfs0(w), par[ arr[w] ] = arr[u];
		rg[ arr[w] ].push_back( arr[u] );
	}
}

void Make_dominatorTree(int root)
{
    //Build Dominator tree
    T = 0;
    dfs0( root );
	int n = T;
	for(int i = n;i >= 1; i--)
	{
		for(int j=0;j < rg[i].size(); j++)
			sdom[i] = min( sdom[i], sdom[ Find( rg[i][j] ) ] );

		if(i > 1) bucket[ sdom[i] ].push_back( i );
		for(int j=0; j < bucket[i].size(); j++)
		{
			int w = bucket[i][j];
			int v = Find(w);
			if(sdom[v] == sdom[w]) dom[w] = sdom[w];
			else dom[w] = v;
		}
		if(i > 1) Union(par[i], i);
	}
	for(int i = 2;i <= n; i++)
	{
		if(dom[i] != sdom[i]) dom[i] = dom[dom[i]];

		tree[rev[i]].push_back(rev[dom[i]]);
		tree[rev[dom[i]]].push_back(rev[i]);
	}
	//done :)
}

LL ans, sz[N];

void dfs(int p,int pa)
{
    LL val = 1;
    sz[p] = 1;

    for(auto x : tree[p])
    {
        if(x == pa) continue;
        cout << p << ' ' << x << endl;
        dfs(x, p);
        sz[p] += sz[x];

        if(p == 1)
        {
            ans += (LL)val * sz[x];
            val += sz[x];
        }
    }

    return;
}

int main()
{
    freopen("in.txt", "r", stdin);
	int n, m;
	sf(n); sf(m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		sf(u); sf(v);
		g[u].push_back(v);
	}
	Make_dominatorTree( 1 );

	dfs(1, 1);
	cout << ans << endl;

	return 0;
}


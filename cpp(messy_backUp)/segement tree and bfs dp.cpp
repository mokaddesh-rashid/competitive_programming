#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define LL           long long
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define MAX 100010

int M;
LL tree[4*MAX];

void update(int idx,int b,int e,int p,int v)
{
    if(p < b || p > e) return;
    if(b == e)
    {
        tree[idx] = v;
        return;
    }

    int m = (b + e)>>1;
    update(lnd, b, m, p, v);
    update(rnd, m + 1, e, p, v);

    tree[idx] = (tree[lnd] * tree[rnd]) % M;
}

LL query(int idx,int b,int e,int l,int r)
{
    if(r < b || e < l) return 1;
    if(l <= b && e <= r) return tree[idx];

    int m = (b + e)>>1;
    return (query(lnd, b, m, l, r) * query(rnd, m + 1, e, l, r)) % M;
}

vector<int> mat[MAX];
LL dp[MAX];
int id, gigi[MAX], lf[MAX], rg[MAX];

int dfs(int p,int pa)
{
    lf[p] = id + 1;
    dp[p] = 1; id += (mat[p].size() - (p != pa));
    int c = id; rg[p] = id;

    for(auto x : mat[p])
    {
        if(x == pa) continue;
        gigi[x] = c--;

        dfs(x, p);
        dp[p] *= (dp[x] + 1); dp[p] %= M;
    }
}

LL prin[MAX];
void dfs2(int p,int pa)
{
    LL pVal = query(1, 0, MAX-1, gigi[pa], gigi[pa]);

    prin[p] = query(1, 0, MAX - 1, lf[p], rg[p]);
    if(p != pa) prin[p] = (prin[p] * pVal) % M;


    for(auto x : mat[p])
    {
        if(pa == x) continue;

        update(1, 0, MAX-1, gigi[x], 1);

        LL newVal = query(1, 0, MAX-1, lf[p], rg[p]);
        if(p != pa) newVal = (newVal * pVal) % M;

        update(1, 0, MAX-1, gigi[p], newVal + 1);

        dfs2(x, p);

        update(1, 0, MAX-1, gigi[x], dp[x] + 1);
        update(1, 0, MAX-1, gigi[p], dp[p] + 1);
    }
}

int main(void)
{
	ios::sync_with_stdio(false);
	//inf;

    int n, v, u;

	cin >> n >> M;
	FOR(i,1,n-1)
	{
	    cin >> u >> v;
	    mat[u].PB( v ); mat[v].PB( u );
	}

    dfs(1, 1);
	FOR(i,1,n) update(1, 0, MAX-1, gigi[i], dp[i] + 1);
	dfs2(1, 1);

	FOR(i,1,n) cout << prin[i] << endl;


	return 0;
}



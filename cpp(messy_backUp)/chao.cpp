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
#define M              1000000007
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

vector<int> mat[MAX];
vector<LL> pref[MAX], sufi[MAX];
LL D[MAX];
int pa[MAX];

void dfs(int p)
{
    D[p] = 1;
    int sz = mat[p].size();

    FOR(i,0,sz - 1)
    {
        int x = mat[p][i];
        pa[x] = p; dfs( x );
        D[p] = D[p] * (D[x] + 1) % M;
    }

    LL t1 = 1, t2 = 1;
    for(int i = 0, j = sz - 1; i < sz; i++, j--)
    {
        int v = mat[p][i], u = mat[p][j];
        pref[p].PB( t1 );  sufi[p].PB( t2 );
        t1 = t1 * (D[v] + 1) % M;
        t2 = t2 * (D[u] + 1) % M;
    }
    reverse(sufi[p].begin(), sufi[p].end());
}

LL prin[MAX];

void bit(int p)
{
    prin[p] = D[p];
    LL opd, opx;

    FOR(i,0,(int)mat[p].size() - 1)
    {
        int x = mat[p][i];
        LL opd = D[p], opx = D[x];

        D[p] = pref[p][i] * 1ll * sufi[p][i]  % M;
        D[p] = D[p] * 1ll * (D[ pa[p] ] + 1) % M;

        D[x] = D[x] * (D[p] + 1) % M;
        bit(x);

        D[p] = opd; D[x] = opx;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n, u, v, p = 1;

    cin >> n;
    FOR(i,2,n)
    {
        u = i; cin >> v;
        mat[v].PB( u );
    }

    dfs( 1 );
    bit( 1 );

    FOR(i,1,n) cout << prin[i] << ' ';

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define PB push_back
#define F first
#define S second
#define MAX 55
#define MP make_pair
typedef pair<int,int> pii;

int col[MAX];
vector<int> mat[MAX];
int lev[MAX], low[MAX], ins[MAX], ti, cCol;
stack<int> stk;

void init()
{
    FOR(i,0,15) mat[i].clear();
    mem(col, 0); mem(lev, 0); mem(low, 0); mem(ins, 0);
    ti = cCol = 0;
}

void tarzan(int p)
{
    lev[p] = low[p] = ++ti;
    ins[p] = 1; stk.push( p );

    for(auto x : mat[p])
    {
        if(!lev[x]) {tarzan( x ); low[p] = min(low[p], low[x]);}
        else if(ins[x]) low[p] = min(low[p], lev[x]);
    }

    if(low[p] == lev[p])
    {
        cCol++;

        while(true)
        {
            int cp = stk.top(); stk.pop();

            ins[cp] = 0; col[cp] = cCol;
            if(cp == p) break;
        }
    }
}

pii ara[MAX];
int n, m, dp[16][(1<<15) + 1];

int rec(int p,int mask)
{
    ///cout << p << ' ' << mask << endl;
    if(mask == (1<<n) - 1) return 0;

    int &temp = dp[p][mask];
    if(temp != -1) return temp;

    temp = 20;
    FOR(i,0,n-1)
    {
        if(mask & (1<<i)) continue;
        temp = min(temp, 1 + rec(i, ((1<<i) | mask)));
    }

    for(auto i : mat[p])
    {
        if(mask & (1<<i)) continue;
        temp = min(temp, rec(i, ((1<<i) | mask)));
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    init();
    int u, v;

    cin >> n >> m;
    FOR(i,1,m)
    {
        cin >> u >> v; ara[i] = {u, v};
        mat[u].PB( v );
    }

    FOR(i,1,n) if(!lev[i]) tarzan( i );
    FOR(i,1,n) mat[i].clear();
    FOR(i,1,m)
    {
        u = col[ ara[i].F ] - 1; v = col[ ara[i].S ] - 1;
        if(u != v) mat[u].PB( v ), cout << u << ' ' << v << endl;
    }
    n = cCol;

    mem(dp, -1);
    int prin = n;
    FOR(i,0,n-1)
        prin = min(prin, rec(i, (1<<i)) + 1);

    cout << prin << endl;

    return 0;
}



#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 500010

int lf[MAX], rg[MAX], lev[MAX], bigChild[MAX], sz[MAX], dfa[MAX], ti;
vector<int> mat[MAX], query[MAX], id[MAX];
map<int,int> cnt;
int col[MAX];
long long prin;

void dfs(int p,int pa)
{
    lf[p] = ++ti; sz[p] = 1;
    dfa[ti] = p;

    int mx = -1;
    bigChild[p] = -1;

    for(auto x : mat[p])
    {
        if(x != pa)
        {
            lev[x] = lev[p] + 1;
            dfs(x, p);
            sz[p] += sz[x];
            if(sz[x] > mx) mx = sz[x], bigChild[p] = x;
        }
    }
    rg[p] = ti;
}

void dsu(int p,int pa,int keep)
{
    for(auto x : mat[p])
        if(x != pa && x != bigChild[p])
            dsu(x, p, 0);

    if(bigChild[p] != -1) dsu(bigChild[p], p, 1);

    prin += cnt[1];
    cnt[col[p]]++;
    for(auto x : mat[p])
    {
        if(x == pa || x == bigChild[p]) continue;
        FOR(i,lf[x],rg[x])
        {
            int v = dfa[i];
            if(col[p] % col[v] == 0) prin += cnt[col[p] / col[v]];
        }
        FOR(i,lf[x],rg[x])
        {
            int v = dfa[i];
            cnt[ col[v] ]++;
        }
    }

    if(!keep)
    {
        FOR(i,lf[p],rg[p])
        {
            int v = dfa[i];
            cnt[ col[v] ]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    int n, q, x, y;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].push_back( y );
        mat[y].push_back( x );
    }
    FOR(i,1,n) cin >> col[i];

    dfs(1, 1);
    dsu(1, 1, 0);

    cout << prin << endl;


    return 0;
}


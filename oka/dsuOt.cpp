#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j; i <= k; i++)
#define MAX 100010
#define PB push_back
#define LL long long

vector<int> mat[MAX];

int lf[MAX], rg[MAX], lev[MAX], bigC[MAX], sz[MAX], dfa[MAX], ti;

void dfs(int p,int pa)
{
    lf[p] = ++ti; sz[p] = 1;
    dfa[ti] = p;

    int mx = -1;
    bigC[p] = -1;

    for(auto x : mat[p])
    {
        if(x == pa) continue;

        lev[x] = lev[p] + 1;
        dfs(x, p);
        sz[p] += sz[x];
        if(sz[x] > mx) mx = sz[x], bigC[p] = x;
    }

    rg[p] = ti;
}

LL prin[MAX], sum[MAX], occ[MAX], cnt[MAX];
int col[MAX], moa;

void update(int p,int v)///here i try to record value jadr occurance max and tadr value r sum
{
    int c = col[p], oc1 = cnt[ c ];

    cnt[ c ] += v;
    int oc2 = cnt[ c ];

    if(oc1) occ[ oc1 ]--; if(oc2) occ[ oc2 ]++;
    if(oc1) sum[ oc1 ] -= c; if(oc2) sum[ oc2 ] += c;

    while(occ[moa + 1]) {moa++;}
    while(moa > 0 && !occ[moa]) {moa--;}

    return;
}


int dsu(int p,int pa,int keep)
{
    for(auto x : mat[p])
        if(x != pa && x != bigC[p])
            dsu(x, p, 0);

    if(bigC[p] != -1) dsu(bigC[p], p, 1);

    ///add my node info
    update(p, 1);

    for(auto x : mat[p])
    {
        if(x == pa || x == bigC[p]) continue;
        FOR(i,lf[x],rg[x]) update(dfa[i], 1);
    }

    prin[ p ] = sum[moa];
    ///check useful query here
    if(!keep)
        FOR(i,lf[p],rg[p]) update(dfa[i], -1);
}

int main()
{
    ios::sync_with_stdio(false);

    int n, u, v;

    cin >> n;
    FOR(i,1,n) cin >> col[i];
    FOR(i,1,n-1)
    {
        cin >> u >> v;
        mat[u].PB( v );
        mat[v].PB( u );
    }

    dfs(1, 1);
    dsu(1, 1, 0);

    FOR(i,1,n) cout << prin[i] << ' ';

    return 0;
}

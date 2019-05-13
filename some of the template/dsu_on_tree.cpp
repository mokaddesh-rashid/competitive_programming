#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a, b, sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back
#define MAX 100010

int lf[MAX], rg[MAX], sz[MAX], ti, dfa[MAX], col[MAX], n;
vector<int> mat[MAX];
int bigChild[MAX], cnt[MAX];
long long tyc[MAX], prin[MAX];
long long sum[MAX];

void dfs(int p,int pa)
{
    int mx = -1;
    bigChild[p] = -1;

    sz[p] = 1; lf[p] = ++ti; dfa[ti] = p;
    for(auto x : mat[p])
    {
        if(x != pa)
        {
            dfs(x, p);
            sz[p] += sz[x];
            if(sz[x] > mx) mx = sz[x], bigChild[p] = x;
        }
    }
    rg[p] = ti;
}

int mc;

void up(int p,int val,int c)
{
    tyc[ cnt[ col[p] ] ] -= val;
    cnt[ col[p] ] += c;
    tyc[ cnt[ col[p] ] ] += val;

    if(cnt[ col[p] ] > mc) mc++;
    while(tyc[mc] == 0 && mc)
    {
        mc--;
    }
}

void dfs(int p,int pa,bool keep)
{
    for(auto x : mat[p])
    {
        if(x != pa && x != bigChild[p])
            dfs(x, p, 0);
    }
    if(bigChild[p] != -1) dfs(bigChild[p], p, 1);

    for(auto x : mat[p])
    {
        if(x != pa && x != bigChild[p])
            FOR(i,lf[x],rg[x])
            {
                up(dfa[i], col[ dfa[i] ], 1);
            }
    }

    up(p, col[p], 1);
    prin[p] = tyc[mc];

    if(!keep)
    {
        FOR(i,lf[p],rg[p])
        {
            up(dfa[i], col[ dfa[i] ], -1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    int x, y;

    cin >> n;
    FOR(i,1,n) cin >> col[i];
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].PB( y );
        mat[y].PB( x );
    }
    dfs(1, 1);
    dfs(1, 1, 0);

    FOR(i,1,n)
    {
        //cout << lf[i] << ' ' << rg[i] << endl;
        cout << prin[i] << ' ';
    }

    return 0;
}


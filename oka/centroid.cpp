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
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;


vector<int> mat[MAX], chi[MAX], myPaChi[MAX];
vector<PR> paInfo[MAX];
int lev[MAX], pa, cen, sub[MAX], tr_sz, dis[MAX];

void col_info(int p,int baap)
{
    if(cen)
    {
        if(!paInfo[p].empty()) myPaChi[cen].PB( paInfo[p][(int)paInfo[p].size() - 1].S );
        chi[cen].PB( dis[p] );

        paInfo[p].PB( {cen, dis[p]} );
    }

    sub[p] = 1;
    for(auto x : mat[p])
    {
        if(lev[pa] < lev[x]) pa = x; ///finding parents in cen tree
        if(x == baap || lev[x]) continue;

        dis[x] = dis[p] + 1;
        col_info(x, p);
        sub[p] += sub[x];

    }
}

int centroid(int p,int baap)
{
    if((sub[p]<<1) <= tr_sz) return baap;

    for(auto x : mat[p])
        if((sub[x]<<1) > tr_sz && !lev[x] && x != baap)
            return centroid(x, p);

    return p;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n, u, v, k;

    cin >> n >> k;

    FOR(i,1,n-1)
    {
        cin >> u >> v;
        mat[u].PB( v ); mat[v].PB( u );
    }

    FOR(l,1,18)
        FOR(i,1,n)
        {
            if(lev[i]) continue;

            pa = 0; col_info(i, i); tr_sz = sub[i];
            cen = centroid(i, i);

            dis[cen] = 0; col_info(cen, cen);
            lev[cen] = lev[pa] + 1; cen = 0;
        }

    return 0;
}

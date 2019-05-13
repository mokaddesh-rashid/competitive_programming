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
#define M          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 300010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

int vis[MAX], c[2], d, col[MAX], n;
vector<int> mat[MAX];
vector<PR> vovo;

void dfs(int p)
{
    vis[p] = 1; c[ col[p] ]++;

    for(auto x : mat[p])
    {
        if(vis[x] && col[x] == col[p]) d = 0;
        if(vis[x]) continue;

        col[x] = col[p] ^ 1;
        dfs(x);
    }

    return;
}

LL prin;
LL dpCol[MAX], dp[MAX], cc;


LL bm(LL n, LL p)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % M;

    LL ret = bm(n, p>>1);
    ret = (ret * ret) % M;
    if(p % 2) ret = (ret * n) % M;
    return ret % M;
}


LL rec(int p)
{
    if(p == -1) return 1;
    if(dpCol[p] == cc) return dp[p];

    dpCol[p] = cc;

    if(vovo[p].F + vovo[p].S == 1) dp[p] = 3 * rec(p - 1);
    else dp[p] = rec(p - 1) * bm(2, vovo[p].F) + rec(p - 1) * bm(2, vovo[p].S);
//    cout << p << ' ' << vovo[p].F << ' ' << vovo[p].S << ' ' << dp[p] << endl;
//    cout << bm(2, vovo[p].F) << endl;
    return dp[p] % M;
}



int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        int u, v, m;

        cin >> n >> m;
        FOR(i,1,n)
        {
            mat[i].clear();
            vis[i] = 0;
        }

        FOR(i,1,m)
        {
            cin >> u >> v;
            mat[u].PB( v );
            mat[v].PB( u );
        }
        prin = 0; d = 1;
        FOR(i,1,n)
        {
            if(!vis[i])
            {
                c[0] = c[1] = 0;
                dfs( i );
                vovo.PB( MP(c[0], c[1]) );
            }
        }
        cc++;
        cout << rec(vovo.size() - 1) * d << endl;
        vovo.clear();
    }

    return 0;
}


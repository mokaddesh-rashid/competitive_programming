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
#define MAX 17
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int dis[MAX][MAX], n, m;
int dp[(15*15 + 5)][(1<<15) + 5], in[MAX];

int rec(int p,int mask)
{
    int x = p / n, y = p % n;

    if(x == n)
    {
       if(mask) return 100000000;
       else return 0;
    }

    int &temp = dp[p][mask];
    if(temp != -1) return temp;

    temp = rec(p + 1, mask);

    int newMask = mask ^ (1<<x) ^ (1<<y);
    if((mask & (1<<x)) && mask & (1<<y))  temp = min(dis[x][y] + rec(p + 1, newMask), temp);

    return temp;
}

int miin(int u,int v)
{
    if(u > v) swap(u, v);
    if(u <= -1) return v;
    else return u;
}

int main()
{
    ///inf;
    int tc;

    sf(tc);///cin >> tc;
    FOR(tt,1,tc)
    {
        mem(dis, -1); mem(in, 0);
        int prin = 0, u, v, c;

        sff(n, m);///cin >> n >> m;
        FOR(i,0,m-1)
        {
            sfff(u, v, c);///cin >> u >> v >> c;

            u--; v--;
            in[u]++; in[v]++;
            prin += c;

            dis[u][v] = miin(dis[u][v], c);
            dis[v][u] = miin(dis[v][u], c);
        }

        FOR(k,0,n-1)
            FOR(i,0,n-1)
                FOR(j,0,n-1)
                    if(dis[i][k] != -1 && dis[k][j] != -1)
                        dis[i][j] = miin(dis[i][j], dis[i][k] + dis[k][j]);

        int mask = 0;

        FOR(i,0,n-1)
            if(in[i] % 2) mask |= (1<<i);

        mem(dp, -1);
        printf("Case %d: %d\n",  tt, prin + rec(0, mask));
    }
    return 0;
}

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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int dp[MAX][1<<7][7], n, ara[MAX];

int giveId(int v)
{
    if(v == 10) return 0;
    if(v == 20) return 1;
    if(v == 50) return 2;
    if(v == 100) return 3;
    if(v == 200) return 4;
    if(v == 500) return 5;
    return 6;
}

int rec(int p,int mask,int cv)
{
    if(p == n) return 0;

    int &temp = dp[p][mask][cv];
    if(temp != -1) return temp;

    temp = 0;
    FOR(i,0,6)
    {
        if(mask & (1<<i)) continue;
        temp = max(temp, rec(p, mask | (1<<i), i));
    }

    int a = 0;
    if(ara[p] == cv) a = 1;
    temp = max(temp, a + rec(p + 1, mask, cv));

    return temp;
}


int main()
{
    ///ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;

    sf(tc);///cin >> tc;

    FOR(tt,1,tc)
    {
        int a;

        sf(n);///cin >> n;
        FOR(i,0,n-1)
        {
            sf(a);///cin >> a;
            ara[i] = giveId( a );
        }
        mem(dp, -1);
        int prin = 0;

        FOR(i,0,6)
            prin = max(prin, rec(0, 1<<i, i));

        pf("%d\n", n - prin);

    }

    return 0;
}


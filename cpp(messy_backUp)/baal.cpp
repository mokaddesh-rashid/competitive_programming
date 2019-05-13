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
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;


int n, m, q;
int dp[1<<13][110];
int cnt[1<<13], val[13];
char str[MAX];

int toNumber()
{
    int ret = 0;

    FOR(i,0,n-1)
    {
        if(str[i] == '1')
        {
            int x = 1<<i;
            ret += x;
        }
    }
    return ret;
}

int getDis(int x,int y)
{
    int ret = 0;

    FOR(i,0,n-1)
    {
        int a = x & (1<<i), b = y & (1<<i);
        if(a == b) ret += val[i];
    }

    return ret;
}

int main()
{
    ///ios::sync_with_stdio(false);
   /// inf;
    //outf;
    int chk;

    sfff(n, m, q);
    FOR(i,0,n-1) sf(val[i]);

    FOR(i,0,m-1)
    {
        scanf("%s", str);
        cnt[ toNumber()]++;
    }

    FOR(i,0,(1<<n))
        FOR(j,0,(1<<n))
        {
            int v = getDis(i, j);
            if(v < 101) dp[i][v] += cnt[j];
        }

    FOR(qi,1,q)
    {
        scanf("%s", str);
        sf(chk);
        int v = toNumber( );

        int prin = 0;
        FOR(i,0,chk) prin += dp[v][i];
        pf("%d\n", prin);
    }

    return 0;
}


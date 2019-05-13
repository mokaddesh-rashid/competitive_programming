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
#define MAX 2010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int dp[23][1<<23];
int n, ara[MAX];

int rec(int p,int mask)
{
    int cnt = 0;
    FOR(i,0,n-1) if(mask & 1<<i) cnt++;

    if(p == n) return cnt;

    int &temp = dp[p][mask];
    if(temp != -1) return temp;

    temp = MAX;

    int can = 0;
    if(p == 0) can = 1;

    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            if( (mask & 1<<i) && (mask & 1<<j) )
            {
                if(ara[i] + ara[j] == ara[p]) can = 1;
            }
        }
    }
    FOR(i,0,n-1)
    {
        if(mask & 1<<i)
        {
            temp = min(temp, rec(p, mask ^ (1<<i)));
            if(can) temp = min(temp, rec(p + 1, mask ^ (1<<i) ^ (1<<p)));
        }
    }

    if(can)
    {
         int ans = rec(p + 1, mask ^ (1<<p));
         cnt++; int ret = max(cnt, ans);
         temp = min(temp,  ret);
    }

    return temp;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];

    mem(dp, -1);
    int x = rec(0, 0);
    if(x > n) x = -1;
    cout << x << endl;
    return 0;
}

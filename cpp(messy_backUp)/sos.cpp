#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define LL long long
#define MAX 4000005
#define F first
#define S second
typedef pair<int,int> pii;

pii dp[(1<<19) + 10];

void update(int p,int v)
{
    if(dp[p].F < v)
    {
        dp[p].S = dp[p].F;
        dp[p].F = v;
    }
    else dp[p].S = max(dp[p].S, v);
}

void solve()
{

    int n, v, m;

    scanf("%d", &n); m = (1<<n) - 1;
    FOR(i,0,m)
    {
        scanf("%d", &v);
        dp[i] = {v, -1};

    }

    FOR(bit,0,n-1)
        FOR(mask,0,m)
            if(mask & (1<<bit))
            {
                int u = dp[mask ^ (1<<bit)].F, v = dp[mask ^ (1<<bit)].S;
                update(mask, u);
                update(mask, v);
            }

    int prin = 0;
    FOR(i,1,m)
    {
        prin  = max(prin, dp[i].F + dp[i].S);
        printf("%d\n", prin);
        ///cout << prin << endl;
    }
}

int main()
{
    solve();
    return 0;
}

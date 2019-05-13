#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define LL           long long

const int MOD = 10007;
int dp[105][1005], bm[105][1005], fac[105], n, w, ara[105], pp[105][1005];

void add(int &a,int b)
{
    a += b;
    if(a >= MOD) a -= MOD;
}

int main()
{
    ios::sync_with_stdio(false);

    fac[1] = 1;
    FOR(i,2,100)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }

    cin >> n >> w;
    FOR(i,0,n-1) cin >> ara[i];
    sort(ara, ara + n);

    dp[0][0] = 1;
    FOR(p,0,n-1)
    {
        FOR(len,0,p + 1)
            FOR(i,0,w)
            {
                add(bm[len][i], dp[len][i]);
                if(i + ara[p] <= w) add(bm[len + 1][i + ara[p]], dp[len][i]);
            }

         FOR(len,0,p + 1)
            FOR(i,0,w)
            {
                dp[len][i] = bm[len][i];
                bm[len][i] = 0;
            }
    }

    int prin = 0;
    FOR(len,0,n)
        FOR(i,0,w)
        {
            if(dp[len][i])
            {
                cout << len << ' ' << i << ' ' << dp[len][i] << endl;
                prin += (fac[len] * dp[len][i]);
                prin %= MOD;
            }
        }
    cout << prin << endl;
    return 0;
}



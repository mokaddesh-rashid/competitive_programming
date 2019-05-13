#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define LL           long long

const int MAX = 200005;
const int MOD = 998244353;

LL ara[MAX], dp[MAX], n, k;

bool same(int x,int y)
{
    if(ara[x] == -1) return 0;
    return (ara[x] == ara[y]);
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int cha = 0;

    cin >> n >> k;
    FOR(i,1,n) cin >> ara[i];

    FOR(i,1,n)
    {
        if(i > 2 && same(i, i - 2)) cha = 1;
        if(i + 2 <= n && same(i, i + 2)) cha = 1;
    }
    if(cha)
    {
        cout << 0 << endl;
        return 0;
    }

    dp[0] = 1;
    FOR(i,1,n)
    {
        LL can = k;

        if(ara[i] != -1) dp[i] = dp[i - 1];
        else
        {
            if(i - 2 < 1)
            {
                LL can = k;
                if(i + 2 <= n && ara[i + 2] != -1) can--;

                dp[i] = dp[i - 1] * can;
            }
            else if(i + 2 > n)
            {
                LL can = k - 1;
                dp[i] = dp[i - 1] * can;
            }
            else if(ara[i - 2] == -1 && ara[i + 2] != -1)
            {

            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)

const int MAX = 2005, MOD = (1e9) + 7;

void M(int &x)
{
    if(x >= MOD) x -= MOD;
    return;
}

int dp[MAX][MAX][2];

int rec(int p,int t,int c)
{
    if(p == 0) return 0;

    int &temp = dp[p][t][c];
    if(temp != -1) return temp;

    temp = 0;
    int r1 = 0, r2 = 0;

    if(c)
    {
        if(t + 1 <= p - 1) r1 += rec(p - 1, t + 1, 0);
        if(t) r1 += rec(p - 1, t - 1, 0);
        r1++;
    }
    if(t + 1 <= p - 1) r2 += rec(p - 1, t + 1, 1);
    if(t) r2 += rec(p - 1, t - 1, 1);

    temp = max(r1, r2);
    M(temp);

    return temp;
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    cout << rec(n*2, 0, 1) << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define LL           long long
#define MAX 1000010

int ar[MAX], upor[MAX], niche[MAX], n, up[MAX], dw[MAX];

LL dp[MAX];

LL rec(int p)
{
    if(p == n) return 0;

    LL &temp = dp[p];
    if(temp != -1) return temp;

    temp = rec(p + 1);

    int u = up[p], w = dw[p];

    temp = max(temp, ar[u] - ar[p] + rec(u + 1));
    temp = max(temp, ar[p] - ar[w] + rec(w + 1));

    if(p != u) temp = max(temp, ar[u - 1] - ar[p] + rec(u));
    if(p != w) temp = max(temp, ar[p] - ar[w - 1] + rec(w));

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;
    int c, d;

    cin >> n;
    FOR(i,0,n-1) cin >> ar[i];


    FOR(i,0,n-1)
    {
        if(ar[i] >= ar[i + 1]) upor[i] = 1;
        if(ar[i] <= ar[i + 1]) niche[i] = 1;
    }
    d = c = n - 1;
    REV(i,n-1,0)
    {
        up[i] = d;
        if(upor[i]) d = i;
///*********
        if(niche[i]) c = i;
        dw[i] = c;
    }

    mem(dp, -1);
    cout << rec(0) << endl;

    return 0;
}

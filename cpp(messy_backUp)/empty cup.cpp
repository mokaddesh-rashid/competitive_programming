#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 100005

typedef long long LL;
const LL INF = (LL)10000000000000000;

LL k, dp[MAX], bm[MAX], cnt[MAX], ara[MAX], n, cl, cr, in[MAX];
LL cost;

void upCost(int val,int p)
{
    LL voo = cnt[val];
    voo =  (voo * (voo - 1))>>1; cost -= voo;

    cnt[val] += p;

    voo = cnt[val];
    voo =  (voo * (voo - 1))>>1; cost += voo;
    return;
}

LL makeSame(int l,int r)
{
    while(true)
    {
        if(l <= cl && cl <= r && !in[cl]) upCost( ara[cl], 1), in[cl] = 1;
        else if(!(l <= cl && cl <= r) && in[cl]) upCost( ara[cl], -1), in[cl] = 0;

        if(cl == l) break;
        else cl = cl < l ? cl + 1 : cl - 1;
    }

    while(true)
    {
        if(l <= cr && cr <= r && !in[cr]) upCost( ara[cr], 1), in[cr] = 1;
        else if(!(l <= cr && cr <= r) && in[cr]) upCost( ara[cr], -1), in[cr] = 0;

        if(cr == r) break;
        else cr = cr < r ? cr + 1 : cr - 1;
    }

    return cost;
}

void compute(int l,int r,int optl,int optr)
{
    if(l > r) return;

    int mid = (l + r)>>1;
    pair<LL,int> best = {INF, -1};

    for(int k = optl; k <= min(mid, optr); k++)
        best = min(best, {dp[k-1] + makeSame(k, mid), k});

    bm[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> n >> k;
    FOR(i,1,n) cin >> ara[i];

    FOR(i,1,n) dp[i] = INF;
    FOR(i,1,k)
    {
        compute(0, n, 0, n);
        FOR(i,0,n) dp[i] = bm[i];
    }

    cout << dp[n] << endl;

    return 0;
}



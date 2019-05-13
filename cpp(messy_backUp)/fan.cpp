#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define lnd (idx<<1)
#define rnd (lnd^1)

const int MAX = 100005;

int tree[MAX*4];

void upd(int idx,int b,int e,int p,int v)
{
    if(b > p || p > e) return;
    if(b == e)
    {
        tree[idx] = v;
        return;
    }

    int m = (b + e)>>1;

    upd(lnd, b, m, p, v); upd(rnd, m + 1, e, p, v);
    tree[idx] = min(tree[lnd], tree[rnd]);
}

int query(int idx,int b,int e,int l,int r)
{
    if(b > r || e < l) return MAX;
    if(l <= b && e <= r) return tree[idx];

    int m = (b + e)>>1;
    return min(query(lnd, b, m, l, r), query(rnd, m + 1, e, l, r));
}

int dp[MAX], ara[MAX], n, k;


int can(int p)
{
    int st = 1, en = p, mid = p, ret = p;

    while(st <= en)
    {
        mid = (st + en)>>1;

        if(ara[mid] + k + k >= ara[p]) en = mid - 1, ret = min(mid, ret);
        else st = mid + 1;
    }

    return ret;
}

int main()
{
    inf;
    outf;

    int tc;

    scanf("%d", &tc);
    FOR(tt,1,tc)
    {
        scanf("%d %d", &n, &k);
        FOR(i,1,n) scanf("%d", &ara[i]);
        sort(ara, ara + n + 1);

        FOR(i,1,n)
        {
            int r = i - 3, l = can(i) - 1;
            upd(1, 0, MAX, i,  query(1, 0, MAX, l, r) + 1);
        }

        int x = query(1, 0, MAX, n, n);
        if(x >= MAX) x = -1;
        printf("Case %d: %d\n", tt, x);
    }
    return 0;
}



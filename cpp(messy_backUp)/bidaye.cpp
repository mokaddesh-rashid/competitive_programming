#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define LL long long
#define PB push_back
#define MAX 100010

vector<LL> tree[MAX * 4], sum[MAX * 4];
LL luffy[MAX * 4], ara[MAX];

void update(int idx,int b,int e)
{
    int p = 0;
    for(int i = b; i <= e; i++, p++)
    {
        LL v = min((LL)p, ara[i]);
        luffy[idx] += v;
        tree[idx].PB(ara[i] - v);
    }
    sort(tree[idx].begin(), tree[idx].end());
    sum[idx] = tree[idx];
    for(int i = 1; i < p; i++) sum[idx][i] += sum[idx][i - 1];

    if(b == e) return;

    int m = (b + e)>>1;
    update(lnd, b, m); update(rnd, m + 1, e);
}

LL query(int idx,int b,int e,int st,int en)
{
    if(e < st || b > en) return 0;
    if(st <= b && e <= en)
    {
        LL ret = luffy[idx], so = (e - b) + 1, v = (b - st);

        int goat = upper_bound(tree[idx].begin(), tree[idx].end(), v) - tree[idx].begin();

        if(goat) ret += sum[idx][goat - 1];
        ret += (v * (so - goat));

        return ret;
    }

    int m = (b + e)>>1;
    return query(lnd, b, m, st, en) + query(rnd, m + 1, e, st, en);
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    LL n, l, r, q, x, y;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];
    update(1, 0, n-1);
    cin >> q;
    FOR(i,0,q-1)
    {
        cin >> l >> r;
        x = query(1, 0, n-1, l, r);
        y = 0;
        for(int i = l, p = 0; i <= r; i++, p++)
            y += min((LL)p, ara[i]);

        if(x != y) cout << "ReDo " << x << ' ' << y << endl;
    }
    return 0;
}

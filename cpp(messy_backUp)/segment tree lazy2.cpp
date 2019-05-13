#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define LL           long long
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define MAX 55
#define Val first
#define lazy second

typedef pair<int,int> PR;

PR tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.Val += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    int m = (b+e)>>1;

    update_node(lnd, b, m, cnd.lazy);
    update_node(rnd, m + 1, e, cnd.lazy);
}

int query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e) return tree[idx].Val;

    lazy_update(idx, b, e);

    int m = (b+e)>>1;
    return query(lnd, b, m, st, en) + query(rnd, m + 1, e, st, en);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return;
    }

    lazy_update(idx, b, e);

    int m = (b+e)>>1;
    update(lnd, b, m, st, en, v); update(rnd, m + 1, e, st, en, v);
    cnd.Val = tree[lnd].Val + tree[rnd].Val;
}

int main()
{
    int u, v, c;
    FOR(i,0,100)
    {
        cout << "update " << endl;
        cin >> u >> v >> c;
        update(1, 1, MAX, u, v, c);

        cout << "query" << endl;
        cin >> u >> v;
        cout << query(1, 1, MAX, u, v) << endl;
    }
}

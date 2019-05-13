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
#define clean(sum,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define M          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd seg[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,int> PR;


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template<typename T> using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> seg[4*MAX];

int ara[MAX], n;

void update(int idx,int b,int e,int p,int t)
{
    if(b > p || e < p) return;

    if(t) seg[idx].insert( ara[p] );
    else seg[idx].erase( ara[p] );

    if(b == e) return;

    int m = (b + e)>>1;

    update(lnd, b, m, p, t);
    update(rnd, m + 1, e, p, t);

}

int query(int idx,int b,int e,int l,int v)
{
    if(b > l) return 0;

    if(e <= l)
    {
        int ret = (e - b) + 1 - seg[idx].order_of_key(v + 1);
        return ret;
    }

    int m = (b + e)>>1;
    return query(lnd, b, m, l, v) + query(rnd, m + 1, e, l, v);
}

int greaterThanL(int l,int st,int en)
{
    if(st > en) return 0;
    return query(1, 0, n-1, en, ara[l]) - query(1, 0, n-1, st - 1, ara[l]);
}

int lesserThanL(int l,int st,int en)
{
    if(st > en) return 0;
    return ((en - st) + 1) - greaterThanL(l, st, en);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int q, u, v;
    LL prin = 0;

    sf(n);
    FOR(i,0,n-1) ara[i] = i;

    FOR(i,0,n-1) update(1, 0, n-1, i, 1);


    sf(q);
    FOR(oo,0,q-1)
    {
        sff(u, v);
        u--; v--;
        if(u > v) swap(u, v);

        update(1, 0, n-1, u, 0);
        update(1, 0, n-1, v, 0);

        prin -= lesserThanL(u, u + 1, v - 1);
        prin += greaterThanL(u, u + 1, v - 1);

        prin += lesserThanL(v, u + 1, v - 1);
        prin -= greaterThanL(v, u + 1, v - 1);

        if(ara[u] < ara[v]) prin++;
        else if(u != v) prin--;

        swap(ara[u], ara[v]);
        update(1, 0, n-1, u, 1);
        update(1, 0, n-1, v, 1);

        pf("%lld\n", prin);
    }

    return 0;
}

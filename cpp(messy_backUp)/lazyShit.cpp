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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 300005
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
#define LD long double
typedef pair<LL,LL> pii;

LL a, n;
LL tree[2][MAX*4], pro[MAX];
LL M = (LL)100000000000000000;
pii ara[MAX];

void update(LL lev,LL idx,LL b,LL e,LL p,LL v)
{
    if(p < b || p > e) return;
    if(b == e)
    {
        tree[lev][idx] = v;
        return;
    }

    LL mid = (b + e)>>1;

    update(lev, lnd, b, mid, p, v);
    update(lev, rnd, mid + 1, e, p, v);

    tree[lev][idx] = lev == 0 ? max( tree[lev][lnd],  tree[lev][rnd]) : min( tree[lev][lnd],  tree[lev][rnd]);
}

LL query(LL lev,LL idx,LL b,LL e,LL st,LL en)
{
    if(st > e || en < b ) return lev == 0 ? -M : M;
    if(st <= b && en >= e)
        return tree[lev][idx];

    LL lft = query(lev, lnd, b, (b+e)>>1, st, en);
    LL rgt = query(lev, rnd, ((b+e)>>1) + 1, e, st, en);

    return lev == 0 ? max(lft, rgt) : min(lft, rgt);
}

priority_queue<pii> que;
set<LL> sota;
set<LL>::iterator it;
vector<LL> oke;
LL val;


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL prin = 0;

    cin >> n >> a;
    FOR(i,0,n-1) cin >> ara[i].F >> ara[i].S;
    FOR(i,0,n-1) pro[i] = a - ara[i].S, prin = max(prin, pro[i]);
    FOR(i,1,n-1) pro[i] += pro[i - 1];
    FOR(i,0,n-1) update(0, 1, 0, MAX, i, pro[i]);
    FOR(i,0,n-1) update(1, 1, 0, MAX, i, pro[i]);

    FOR(i,0,n-2)
    {
        LL v = (1ll*(ara[i].F - ara[i + 1].F)) * (1ll*(ara[i].F - ara[i + 1].F));
        que.push( {v, i} );
    }

    sota.insert( -1 ); sota.insert( n - 1 );
    val = LLONG_MIN;
    while(!que.empty())
    {
        pii hd = que.top(); que.pop();
        LL l, r;

        it = sota.lower_bound(hd.S);
        r = *it; it--; l = *it;

        prin = max(prin, query(0, 1, 0, MAX, hd.S, r) - query(1, 1, 0, MAX, l, hd.S) - hd.F);
        oke.PB( hd.second );
        if(val != hd.F)
        {
            for(auto x : oke) sota.insert( x );
            oke.clear();
            val = LLONG_MIN;
        }
    }

    cout << prin << endl;

    return 0;
}




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
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int tree[2][4*MAX], ara[MAX];

void update(int lev,int idx,int b,int e,int p,int v)
{
    if(p > e || p < b) return;
    if(b == e)
    {
        ara[p] = tree[lev][idx] = v;
        return;
    }

    int m = (b + e)>>1;

    update(lev, lnd, b, m, p, v); update(lev, rnd, m + 1, e, p, v);
    tree[lev][idx] = max(tree[lev][rnd], tree[lev][lnd]);
    return;
}

int query(int lev,int idx,int b,int e,int l,int r)
{
    if(b > r || e < l) return 0;
    if(l <= b && e <= r) return tree[lev][idx];

    int m = (b + e)>>1;
    return max(query(lev, lnd, b, m, l, r), query(lev, rnd, m + 1, e, l, r));
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf
    int n, l, r, v;

    cin >> n >> l >> r;
    FOR(i,0,n-1)
    {
        cin >> v;
        update(0, 1, 0, MAX, i, v);
    }

    FOR(i,0,n)
    {
        if(!i)
        {
            v = INT_MAX;
        }
    }

    return 0;
}

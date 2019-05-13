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
#define M              1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

LL tree[2][MAX*4], val[MAX];

LL sum(LL x,LL y)
{
    return x + y;
}
int maax(int u,int v)
{
    return val[u] >= val[v] ? u : v;
}

void update(int lev,int idx,int b,int e,int p,int v)
{
    if(p < b || p > e) return;
    if(b == e)
    {
        if(lev == 0) tree[lev][idx] = p, val[p] = v;
        else tree[lev][idx] = val[p] = v;

        return;
    }

    int mid = (b + e)>>1;

    update(lev, lnd, b, mid, p, v);
    update(lev, rnd, mid + 1, e, p, v);

    tree[lev][idx] = lev == 0 ? maax( tree[lev][lnd],  tree[lev][rnd]) : sum( tree[lev][lnd],  tree[lev][rnd]);
}

LL query(int lev,int idx,int b,int e,int st,int en)
{
    if(st > e || en < b ) return lev == 0 ? 0 : 0;
    if(st <= b && en >= e)
        return tree[lev][idx];

    LL lft = query(lev, lnd, b, (b+e)>>1, st, en);
    LL rgt = query(lev, rnd, ((b+e)>>1) + 1, e, st, en);

    return lev == 0 ? maax(lft, rgt) : sum(lft, rgt);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n, q, ty, x, l, r;

    cin >> n >> q;

    FOR(i,1,n)
    {
        cin >> l;
        update(0, 1, 1, n, i, l);
        update(1, 1, 1, n, i, l);
    }

    FOR(oo, 0, q-1)
    {
        cin >> ty;
        if(ty == 1)
        {
            cin >> l >> r;
            cout << query(1, 1, 1, n, l, r) << endl;
        }
        else if(ty == 2)
        {
            cin >> l >> r >> x;
            while(true)
            {
                int p = query(0, 1, 1, n, l, r);

                if(val[p] >= x)
                {
                    int nv = val[p]%x;
                    update(0, 1, 1, n, p, nv);
                    update(1, 1, 1, n, p, nv);
                }
                else break;
            }
        }
        else
        {
            cin >> l >> x;
            update(0, 1, 1, n, l, x);
            update(1, 1, 1, n, l, x);
        }
    }

    return 0;
}

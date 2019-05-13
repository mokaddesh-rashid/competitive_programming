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

int tree[2][MAX*4];

void update(int lev,int idx,int b,int e,int p,int v)
{
    if(p < b || p > e) return;
    if(b == e)
    {
        tree[lev][idx] = v;
        return;
    }

    int mid = (b + e)>>1;

    update(lev, lnd, b, mid, p, v);
    update(lev, rnd, mid + 1, e, p, v);

    tree[lev][idx] = lev == 0 ? max( tree[lev][lnd],  tree[lev][rnd]) : min( tree[lev][lnd],  tree[lev][rnd]);
}

int query(int lev,int idx,int b,int e,int st,int en)
{
    if(st > e || en < b ) return lev == 0 ? -M : M;
    if(st <= b && en >= e)
        return tree[lev][idx];

    int lft = query(lev, lnd, b, (b+e)>>1, st, en);
    int rgt = query(lev, rnd, ((b+e)>>1) + 1, e, st, en);

    return lev == 0 ? max(lft, rgt) : min(lft, rgt);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n, q, a, b, i, x, y, l, r;
    char ch;

    cin >> n >> q;

    FOR(i,0,n-1)
    {
        cin >> l >> r;
        update(0, 1, 0, n-1, i, l);
        update(1, 1, 0, n-1, i, r);
    }

    FOR(oo, 0, q-1)
    {
        cin >> ch;
        if(ch != '?')
        {
            cin >> i >> l >> r; i--;
            update(0, 1, 0, n-1, i, l);
            update(1, 1, 0, n-1, i, r);
        }
        else
        {
            cin >> l >> r; l--; r--;
            x = query(0, 1, 0, n-1, l, r);
            y = query(1, 1, 0, n-1, l, r);

            cout << max(0, (y - x) + 1) << endl;
        }
    }

    return 0;
}

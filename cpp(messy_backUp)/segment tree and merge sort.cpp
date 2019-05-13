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
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

pair<int,PR> ar[MAX], tree[22][MAX];
PR moa[22][MAX];

int n, pre[MAX], nex[MAX], val[MAX];

void mergeIt(int b, int e, int l, int r, int lev)
{
    int x = b, y = r;

    for(int p = b; b <= e || l <= r; p++)
    {
        if(b > e || (tree[lev + 1][l].F <= tree[lev + 1][b].F && l <= r))
        {
            tree[lev][p] = tree[lev + 1][l];
            l++;
        }
        else
        {
            tree[lev][p] = tree[lev + 1][b];
            b++;
        }
    }
}

void divide(int b, int e,int lev)
{
    if(b < e)
    {
        int mid = (b + e)>>1;

        divide(b, mid, lev + 1);
        divide(mid + 1, e, lev + 1);

        mergeIt(b, mid, mid + 1, e, lev);
    }
    else
    {
        tree[lev][b] = ar[b];
    }

    return;
}

int query(int lev,int b,int e,int st,int en)
{
    ///cout << lev << ' ' << b << ' ' << e << endl;
    if(st > e || en < b ) return -1;
    if(st <= b && en >= e)
    {
        ///do query on node

        return v;
    }

    int mid = (b + e)>>1;

    int ret = query(lev + 1, b, mid, st, en);
    if(ret != -1) return ret;

    return query(lev + 1, mid + 1, e, st, en);
}

int main()
{
    ///ios::sync_with_stdio(false);
    ///inf;
    //outf;

    int q, l, r;

    sf(n);
    FOR(i,0,n-1) sf(ar[i].F);
    divide(0, n - 1, 0);

    return 0;
}


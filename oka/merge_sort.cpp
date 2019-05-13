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
int n, pre[MAX], nex[MAX], val[MAX], moa[22][MAX];

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

void divide(int st, int en,int lev)
{
    if(st < en)
    {
        int mid = (st + en)>>1;

        divide(st, mid, lev + 1);
        divide(mid + 1, en, lev + 1);

        mergeIt(st, mid, mid + 1, en, lev);
    }
    else
    {
        tree[lev][st] = ar[st];
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    cin >> n;
    FOR(i,0,n-1) cin >> val[i];
    FOR(i,0,MAX-1) pre[i] = -1, nex[i] = n;

    FOR(i,0,n-1)
    {
        ar[i].F = pre[ val[i] ];
        pre[ val[i] ] = i;
    }
    REV(i,n-1,0)
    {
        ar[i].S = {nex[ val[i] ], val[i]};
        nex[ val[i] ] = i;
    }

    divide(0, n - 1, 0);
    FOR(i,0,n-1) cout << tree[0][i].F << ' ' << tree[0][i].S.S << endl;

    return 0;
}



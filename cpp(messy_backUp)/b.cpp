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
#define MAX 300010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

piii ed[MAX];
int n, ara[MAX], m, k, p, pa[MAX], prin;

int finPa(int p)
{
    return (pa[p] == p) ? p : pa[p] = finPa( pa[p] );
}

int mergeNode(int u,int v)
{
    int r1 = finPa( u ), r2 = finPa( v );
    if(r1 == r2) return 0;

    pa[r1] = r2;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    FOR(i,0,MAX-1) pa[i] = i;
    cin >> n >> m >> k; k--;
    FOR(i,0,n-1) cin >> ara[i];

    int prin = (ara[n - 1] - ara[0]) + 1;

    FOR(i,1,n-1)
        ed[p] = MP(ara[i] - ara[i - 1], MP(i, i - 1)), p++;

    sort(ed, ed + p);
    reverse(ed, ed + p);

    FOR(i,0,k-1)
    {
        int c = ed[i].F - 1;
        prin -= c;
    }

    cout << prin << endl;

    return 0;
}


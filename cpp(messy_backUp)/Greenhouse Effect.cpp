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
#define MAX 5010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<double,int> pr;

pr boo[MAX];
int ar[MAX], n, m, dp[MAX][MAX];

int rec(int p,int v)
{
    if(p==n) return 0;
    if(dp[p][v]!=-1) return dp[p][v];

    if(ar[p]==v) return dp[p][v]=rec(p+1,v);
    else if(v==m) return dp[p][v]=1+rec(p+1,v);
    else return dp[p][v]=min(rec(p,v+1),1+rec(p+1,v));
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j;

    cin>>n>>m;
    FOR(i,0,n-1) cin>>boo[i].S>>boo[i].F;
    sort(boo,boo+n);
    FOR(i,0,n-1) ar[i]=boo[i].S;
    cout<<rec(0,1)<<NL;
    return 0;
}



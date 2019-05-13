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
#define MAX 90
#define sz  4010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[sz][MAX][MAX][2], n, ar[sz], sm[sz], l, r;

int rec(int x,int d,int k,int t)
{
    int l,r,a,b,c;
    l=x; r=n-x+d;
    if(l>r) return 0;
    if(dp[x][d][k][t]!=-1) return dp[x][d][k][t];

    if(t==0)
    {
        c=0;
        if(x!=0) c=sm[x-1];
        a=sm[x+k-1]-c; b=sm[x+k]-c;

        if(x+k-1<=r) dp[x][d][k][t]=a+rec(x+k,d+k,k,1);
        else return 0;

        if(x+k<=r) dp[x][d][k][t]=max(dp[x][d][k][t],b+rec(x+k+1,d+k+1,k+1,1));
    }
    else
    {
        c=0;
        if(r-k+1>0) c=sm[r-k];
        a=(sm[r]-c)*-1;
        if(r-k+1>=x) dp[x][d][k][t]=a+rec(x,d-k,k,0);
        else return 0;

        c=0;
        if(r-k>0) c=sm[r-k-1];
        b=(sm[r]-c)*-1;
        if(r-k>=x) dp[x][d][k][t]=min(dp[x][d][k][t],b+rec(x,d-k-1,k+1,0));
    }
    return dp[x][d][k][t];
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,x,y,a=0;

    cin>>n; n--;
    FOR(i,0,n) cin>>x, a+=x, sm[i]=a;
    cout<<rec(0,0,1,0);
    return 0;
}



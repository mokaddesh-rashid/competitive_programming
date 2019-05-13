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
#define MAX 100010
#define sz 5010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL cow[sz], bull[sz], n, m, dp[sz][sz];

LL rec(int x,int y)
{
    if(x==0&&y==0) return 0;
    if(dp[x][y]!=-1) return dp[x][y];

    int a,b,c;
    a=n-x; b=m-y;
    dp[x][y]=abs(cow[a]-bull[b])+rec(x-1,y-1);

    if(x<y)
    {
        dp[x][y]=min(dp[x][y],rec(x,y-1));
    }
    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    cin>>n>>m;
    FOR(i,0,n-1) cin>>cow[i];
    FOR(i,0,m-1) cin>>bull[i];
    sort(cow,cow+n);
    sort(bull,bull+m);
    cout<<rec(n,m)<<NL;

    return 0;
}



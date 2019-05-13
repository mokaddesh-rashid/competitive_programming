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
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,m,ar[1510],dp[750][750][5];

int rec(int x,int y,int z)
{
    int p=1440-x-y;

    if(x==0||y==0) return 0;
    if(x<0||y<0) return 10000000;
    if(dp[x][y][z]!=-1) return dp[x][y][z];
    if(ar[p]==1)
    {
        dp[x][y][z]=rec(x,y-1,2);
        if(z==1) return dp[x][y][z]+=1;
    }
    else if(ar[p]==2)
    {
        dp[x][y][z]=rec(x-1,y,1);
        if(z==2) return dp[x][y][z]+=1;
    }
    else
    {
       if(z==1)return dp[x][y][z]=min(rec(x-1,y,1),1+rec(x,y-1,2));
       else return dp[x][y][z]=min(1+rec(x-1,y,1),rec(x,y-1,2));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(dp,-1); mem(ar,0);
        int i,j,x,y,a,b,c;
        cin>>n>>m;
        FOR(i,1,n)
        {
           cin>>a>>b;
           FOR(j,a,b) ar[j]=1;
           //cout<<a<<' '<<b<<' '<<ar[b-1]<<NL;
        }
        FOR(i,1,m)
        {
           cin>>a>>b;
           FOR(j,a,b) ar[j]=2;
           //cout<<a<<' '<<b<<' '<<ar[b-1]<<NL;
        }
        x=rec(720,720,1);
        cout<<x<<NL;
        x=rec(720,720,2);
        cout<<x<<NL;
    }
    return 0;
}

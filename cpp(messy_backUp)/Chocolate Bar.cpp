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
#define sz 60
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[sz][sz][sz];

int rec(int x,int y,int z)
{
    if(x*y==z||z==0) return 0;
    if(x*y<z||0>z) return mod;
    if(dp[x][y][z]!=-1) return dp[x][y][z];

    int a,b,c,d, temp=mod;
    FOR(i,1,y-1)
    {
      a=y-i;
      temp=min(temp,x*x+rec(x,i,z));
      temp=min(temp,x*x+rec(x,a,z));
      if(z>=a*x)temp=min(temp,x*x+rec(x,i,z-(a*x)));
      if(z>=i*x)temp=min(temp,x*x+rec(x,a,z-(i*x)));
    }
    FOR(i,1,x-1)
    {
      a=x-i;
      temp=min(temp,y*y+rec(i,y,z));
      temp=min(temp,y*y+rec(a,y,z));
      if(z>=a*y)temp=min(temp,y*y+rec(i,y,z-(a*y)));
      if(z>=i*y)temp=min(temp,y*y+rec(a,y,z-(i*y)));
    }

    return dp[x][y][z]=temp;
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,x=mod,y,n,m,k;
        cin>>n>>m>>k;
        cout<<rec(n,m,k)<<NL;
    }
    return 0;
}



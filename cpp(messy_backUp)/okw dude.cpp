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

int dp[sz][sz], n, ar[sz];
vector<int> mat[MAX], mo[MAX];
vector<int>::iterator low,up;

int rec(int x,int y)
{
    if(max(x,y)==n) return 0;
    if(dp[x][y]!=-1) return dp[x][y];

    if(x==0)
    {
        FOR(i,max(x,y)+1,n)
        dp[x][y]=max(dp[x][y],1+rec(i,y));///, cout<<x<<" = "<<i<<NL;
    }
    else
    {
        int a,b,c,d=ar[x];
        a=d-1; b=d%7; c=d+1;

        low=lower_bound(mat[a].begin(),mat[a].end(),max(x,y)+1);
        if(mat[a].end()!=low)
        a=low-mat[a].begin(),dp[x][y]=max(dp[x][y],1+rec(mat[d-1][a],y));


        low=lower_bound(mo[b].begin(),mo[b].end(),max(x,y)+1);
        if(mo[b].end()!=low)
        a=low-mo[b].begin(),dp[x][y]=max(dp[x][y],1+rec(mo[b][a],y));

        low=lower_bound(mat[c].begin(),mat[c].end(),max(x,y)+1);
        if(mat[c].end()!=low)
        a=low-mat[c].begin(),dp[x][y]=max(dp[x][y],1+rec(mat[c][a],y));
    }

    if(y==0)
    {
        FOR(i,max(x,y)+1,n)
        dp[x][y]=max(dp[x][y],1+rec(x,i));///, cout<<y<<" = "<<i<<NL;
    }
    else
    {
        int a,b,c,d=ar[y];
        a=d-1; b=d%7; c=d+1;

        low=lower_bound(mat[a].begin(),mat[a].end(),max(x,y)+1);
        if(mat[a].end()!=low)
        a=low-mat[a].begin(),dp[x][y]=max(dp[x][y],1+rec(x,mat[d-1][a]));


        low=lower_bound(mo[b].begin(),mo[b].end(),max(x,y)+1);
        if(mo[b].end()!=low)
        a=low-mo[b].begin(),dp[x][y]=max(dp[x][y],1+rec(x,mo[b][a]));

        low=lower_bound(mat[c].begin(),mat[c].end(),max(x,y)+1);
        if(mat[c].end()!=low)
        a=low-mat[c].begin(),dp[x][y]=max(dp[x][y],1+rec(x,mat[c][a]));
    }

    dp[x][y]=max(dp[x][y],rec(n,y));
    return dp[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,x,y;

    cin>>n;
    FOR(i,1,n)
    {
        cin>>ar[i];
        mat[ar[i]].push_back(i);
        mo[ar[i]%7].push_back(i);
    }
    ///FOR(i,1,n) cout<<ar[i]%7<<' ';

    cout<<rec(0,0)<<NL;
    return 0;
}

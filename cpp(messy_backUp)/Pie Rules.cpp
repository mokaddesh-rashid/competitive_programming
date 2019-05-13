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
#define MAX 100010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX],n,dp[MAX][2],a,b;

int rec(int p,int v)
{
    if(p==n)return 0;
    if(dp[p][v]!=-1) return dp[p][v];

    if(v==0) return dp[p][v]=max(rec(p+1,1)+ar[p],rec(p+1,0)-ar[p]);
    else return dp[p][v]=min(rec(p+1,0)-ar[p],rec(p+1,1)+ar[p]);

}

void prin(int p,int v)
{
    if(p==n)return;

    if(v==0)
    {
        if(rec(p+1,1)+ar[p]==rec(p,v))
        {
            a+=ar[p];
            prin(p+1,1);
        }
        else
        {
            b+=ar[p];
            prin(p+1,0);
        }
        ///return max(rec(p+1,1)+ar[p],rec(p+1,0)-ar[p]);
    }
    else
    {
        if(rec(p+1,0)-ar[p]==rec(p,v))
        {
            b+=ar[p];
            prin(p+1,0);
        }
        else
        {
            a+=ar[p];
            prin(p+1,1);
        }
        ///return min(rec(p+1,0)-ar[p],rec(p+1,1)+ar[p]);
    }

    return;

}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,m,c=0;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i],c+=ar[i];
    j=rec(0,0);
    prin(0,0);

    cout<<b<<' '<<a<<NL;
    return 0;
}



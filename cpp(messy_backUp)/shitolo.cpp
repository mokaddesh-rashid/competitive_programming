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
#define LL              long long
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

LL dp[65][65][65][2],k,n;
LL rec(int p,int l,int r,int t)
{
    if(p==n&&l==r)return t;
    if(p==n)return 0;
    if(dp[p][l][r][t]!=-1)return dp[p][l][r][t];

    int a=t;
    if(r+1>l)a=1;
    return dp[p][l][r][t]=rec(p+1,l+1,r,t)+rec(p+1,l,r+1,a);
}


void prin(int p,int l,int r,int t)
{
    if(p==n)return;

    int a=t;
    if(r+1>l)a=1;
    ///cout<<p<<' '<<rec(p+1,l+1,r,t)<<' '<<rec(p+1,l,r+1,a)<<NL;
    if(rec(p+1,l+1,r,t)>=k)
    {
        cout<<'(';
        prin(p+1,l+1,r,t);
    }
    else
    {
        k-=rec(p+1,l+1,r,t);
        cout<<')';
        prin(p+1,l,r+1,a);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(dp,-1);
    int i,j,m;
    LL c=0,a;

    cin>>n>>k;
    n*=2;
    cout<<rec(0,0,0,0)<<NL;
    prin(0,0,0,0);

    return 0;
}



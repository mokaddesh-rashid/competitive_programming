#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld %lld", &a, &b)
#define sfff(a,b,c)    scanf("%lld %lld %lld", &a, &b, &c)
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
#define MAX 65
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL ar[MAX],ami[MAX],dp[MAX][MAX];

LL rec(LL p,LL l)
{
    if(l==0&&ar[p]<ami[p])return 0;
    if(p==64) return 1;
    if(dp[p][l]!=-1) return dp[p][l];

    if(l==0)
    {
        if(ami[p]==1) return dp[p][l]=rec(p+1,0);
        else if(ar[p]==1) return dp[p][l]=rec(p+1,0)+rec(p+1,1);
        else return dp[p][l]=rec(p+1,0);
    }
    else
    {
        if(ami[p]==1) return dp[p][l]=rec(p+1,1);
        else return dp[p][l]=rec(p+1,1)+rec(p+1,1);
    }
}

LL up(LL v,LL p)
{
    mem(ar,0);mem(ami,0);mem(dp,-1);

    LL a,b,c=0,x,y,z;
    x=v; y=p;
    FOR(i,0,63)
    {
        ar[i]=x%2; ami[i]=y%2;
        x/=2; y/=2;
    }
    reverse(ar,ar+64);
    reverse(ami,ami+64);
    ///FOR(i,0,63)cout<<ami[i]<<' ';

    return rec(0,0);
}
int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL tc;
    sf(tc);///cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,n,m;
        LL a,b,c,x,d;

        sfff(a,b,x);////cin>>a>>b>>x;

        c=up(b,x);
        if(a>1)c-=up(a-1,x);
        pf("%lld\n",c);///cout<<c<<NL;
    }
    return 0;
}



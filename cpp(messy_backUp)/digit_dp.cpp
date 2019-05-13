#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define sfff(a,b,c)    scanf("%I64d %I64d %I64d", &a, &b, &c)
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
typedef pair<LL,LL> pr;

LL ar[65], dp[11][65][2][1<<10], ole[11][65][2][1<<10],n,dud[11][65][2][1<<10],tim;

LL rec(LL b,LL p,LL t,LL mask)
{
    //cout<<p<<' '<<mask<<NL;
    if(p==64&&mask==0)return 1;
    if(p==64)return 0;
    if(dud[b][p][t][mask]==tim)return dp[b][p][t][mask];
    if(ole[b][p][t][mask]!=-1&&t==1)return ole[b][p][t][mask];

    LL temp=0,v;
    if(t==0)
    {
        FOR(i,0,ar[p])
        {
            v=mask^(1<<i);
            if(i==ar[p]) temp+=rec(b,p+1,0,v);
            else temp+=rec(b,p+1,1,v);
        }
    }
    else
    {
        FOR(i,0,b-1)
        {
            v=mask^(1<<i);
            temp+=rec(b,p+1,1,v);
        }
    }
    dud[b][p][t][mask]=tim;
    return ole[b][p][t][mask]=dp[b][p][t][mask]=temp;
}

LL ret(LL b,LL v)///b=base and v=value, number with even number of every digit in base B till V
{
    tim++;
    REV(i,63,0)
    {
        ar[i]=v%b;
        v/=b;
    }
    LL a,c=0,d=0,e=0;
    FOR(i,0,63)
    {
        if(ar[i]!=0)d=1; e+=d;
        a=b-1;
        if(e<=1)a=ar[i];

        FOR(j,1,a)
        {
            LL v=(1<<j);
            if(e==1&&j==a) c+=rec(b,i+1,0,v);
            else c+=rec(b,i+1,1,v);
        }
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(ole,-1);
    LL tc;
    sf(tc);//cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,n,m,b,l,r,a;

        sfff(b,l,r);///cin>>b>>l>>r;
        a=ret(b,r);
        if(l>1)a-=ret(b,l-1);
        pf("%I64d\n",a);//cout<<a<<NL;
    }
    return 0;
}



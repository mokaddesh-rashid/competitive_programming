#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
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
typedef pair<LL,LL> pr;

LL ar[100],mat[100][100], cnt[60][60];
LL con[2501][2501];
LL chk(LL x, LL i,LL b)
{
    LL c;
    b=b*ar[i];
    c=(100*x)/b;///x is value
    if(c>=90) return 1;
    return 0;
}

LL chk2(LL x, LL i,LL b)
{
    LL c;
    b=b*ar[i];
    c=(100*x)/b;///x is value
    if(c<=120) return 1;
    return 0;
}

pr bs(LL i,LL j)
{
    LL st,en,c,d,mid,x;
    st=0; en=10000000; c=10000000;
    while(st<=en)
    {
           mid=(st+en)/2;
           x=chk(mat[i][j],i,mid);
           if(x==1) c=min(c,mid), en=mid-1;
           else st=mid+1;
    }
    if(c==10000000) c=0;

    st=c; en=10000000; d=0;
    while(st<=en)
    {
        mid=(st+en)/2;
        x=chk2(mat[i][j],i,mid);
        if(x==1) d=max(d,mid), en=mid-1;
        else st=mid+1;
    }
    cout<<c<<' '<<d<<NL;
    return MK(c,d);
}

LL vis[101], pa[101], wor[101];

LL n,s,t;
void dfs(LL p, LL c)
{
    int x;
    vis[p]=1; wor[p]=c;
    FOR(i,1,n)
    {
        if(vis[i]==0&&con[p][i]>0)
        {
            pa[i]=p;
            if(p==s) c=con[p][i];
            else c=min(c,con[p][i]);
            dfs(i,c);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(cnt,0);
    LL i,j,x,y,n,m,a,b,c,d,k=1;
    pr f;
    cin>>n>>m;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,n-1)
        FOR(j,0,m-1)
        {
           cin>>mat[i][j]; cnt[i][j]=k;
           k++;
        }
    FOR(i,0,n-2)
    {
        FOR(k,0,m-1)
        {
            f=bs(i,k); c=f.F; d=f.S;
            FOR(j,0,m-1)
            {
               f=bs(i+1,j); a=f.F; b=f.S;
               if((c<=a&&a<=d)||(c<=b&&b<=d)||(a<=c&&c<=b)||(a<=d&&d<=b)) con[cnt[i][k]][cnt[i+1][j]]=1;
            }
        }
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<NL;
    }
    FOR(i,1,k-1)
    FOR(j,1,k-1)
    {
        cout<<con[i][j]<<' ';
        if(j==k-1) cout<<NL;
    }
    return 0;
}

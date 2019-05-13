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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (LL)-1000000000000000000
#define maxx          (LL) 9000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL            long long
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

LL ar[70],n,dp[70][10][2];

LL rec(LL p,LL lv,LL t)
{
    if(p==n)
    {
        //cout<<v<<NL;
        return 1;
    }
    if(dp[p][lv][t]!=-1) return dp[p][lv][t];

    LL temp=0,nv,a,b;
    if(t==0)
    {
        if(lv+1==ar[p]) temp+=rec(p+1,lv+1,0);
        else if(lv+1<ar[p]) temp+=rec(p+1,lv+1,1);

        if(lv-1==ar[p]&&lv-1>=0) temp+=rec(p+1,lv-1,0);
        else if(lv-1<ar[p]&&lv-1>=0) temp+=rec(p+1,lv-1,1);

        if(lv==ar[p]) temp+=rec(p+1,lv,0);
        else if(lv<ar[p]) temp+=rec(p+1,lv,1);
    }
    else
    {
        if(lv+1<=9)temp+=rec(p+1,lv+1,1);
        temp+=rec(p+1,lv,1);
        if(lv-1>=0)temp+=rec(p+1,lv-1,1);
    }

    return dp[p][lv][t]=temp;
}


LL ret(LL v)
{
    if(v==0)return 1;
    //cout<<v<<NL;
    n=0; mem(dp,-1);
    LL i,j,a,c=0;
    while(v>0)
    {
        ar[n++]=v%10;
        v/=10;
    }

    i=0;j=n-1;
    while(i<j)
    {
        swap(ar[i],ar[j]);
        i++;j--;
    }
    //FOR(i,0,n-1)cout<<ar[i];
    //cout<<NL;

    FOR(i,0,n-1)
    {
        a=9;
        if(i==0)a=ar[0];
        FOR(j,1,a)
        {
            if(i==0&&j==a)c+=rec(i+1,j,0);
            else c+=rec(i+1,j,1);
        }
    }

    return c+1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,n,m,x,st,en,mid,c;
    //cout<<ret(110)<<NL;
    //FOR(i,0,100000)cout<<i<<' '<<ret(i)<<NL;

    cin>>m>>n;
    x=ret(n);m+=x;
    ///cout<<n<<' '<<x<<NL;

    st=0; en=c=maxx;

    while(st<=en)
    {
        mid=(st+en)/2;
        x=ret(mid);
        ///cout<<mid<<' '<<x<<NL;
        if(x>=m)c=min(c,mid),en=mid-1;
        else st=mid+1;
    }

    cout<<c<<NL;
    return 0;
}



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
#define sz 8010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz], lf[sz], rg[sz], cnt[sz], val[sz], dp[sz],n;

int rec(int x)
{
    if(x==n) return 0;
    if(dp[x]!=-1) return dp[x];

    int a,b,c,d=ar[x];

    if(x==lf[d]) dp[x]=max(val[d]+rec(rg[d]+1),rec(x+1));
    else dp[x]=rec(x+1);

    return dp[x];
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(val,-1); mem(lf,-1); mem(rg,-1); mem(dp,-1);
    int i,j,x,y,m,a,b,c,d,z;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>ar[i];
        if(lf[ar[i]]==-1) lf[ar[i]]=i;
        rg[ar[i]]=i;
    }

    FOR(i,0,n-1)
    {
       a=ar[i];
       if(val[a]==-1)
       {
           mem(cnt,0);
           x=lf[a]; y=rg[a]; c=d=i; z=0;
           while(true)
           {
               if(c==d||c>x) a=ar[c];
               else a=ar[d];

               x=min(x,lf[a]); y=max(y,rg[a]);
               if(cnt[a]==0) z=z^a;
               cnt[a]=1;

               if(c>x) c--;
               else if(d<y) d++;
               else break;
           }
           a=ar[i]; val[a]=z;
           lf[a]=x; rg[a]=y;
           ///cout<<a<<' '<<z<<' '<<x<<' '<<y<<NL;
       }

    }

    cout<<rec(0)<<NL;
    return 0;
}

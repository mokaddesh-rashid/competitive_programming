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

int dp[MAX], ar[MAX], n;

int ole(int p,int v)
{
    int st=0, en=p, c=0, mid;

    if(ar[p]-ar[0]<v) return -1;
    while(st<=en)
    {
        mid=(st+en)>>1;
        if(ar[p]-ar[mid]>=v) st=mid+1, c=max(c,mid);
        else en=mid-1;
    }

    return c;
}

int rec(int p)
{
    if(p==-1) return 0;
    if(dp[p]!=-1) return dp[p];

    int temp=mod, a, b;
    a=ole(p,90);///lower_bound(ar,ar+n,ar[p]+50)-ar;
    b=ole(p,1440);///lower_bound(ar,ar+n,ar[p]+1440)-ar;
    //cout<<p<<' '<<a<<' '<<90<<' '<<ar[p]-ar[a+1]<<NL;
    temp=20+rec(p-1);
    temp=min(temp,50+rec(a));
    temp=min(temp,120+rec(b));

    return dp[p]=temp;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,m,x,c=0;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    x=rec(n-1);
    FOR(i,0,n-1)
    {
       x=rec(i);
       ///cout<<x<<' '<<c<<NL;
       cout<<x-c<<NL;
       c+=(x-c);
    }
    return 0;
}




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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL ar[sz], xr[sz], yr[sz];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,n,m,l,r,a=1,b=1,c=0, d=0;

    cin>>x>>y>>l>>r;
    n=m=0;

    while(a<=r)
    {
        xr[n]=a; n++;
        a=a*x;
        if(a%x!=0) break;
        if(n>1&&xr[n-2]>xr[n-1]) break;
    }
    while(b<=r)
    {
        yr[m]=b; m++;
        b=b*y;
        if(b%y!=0) break;
        if(m>1&&yr[m-2]>xr[m-1]) break;
    }

    FOR(i,0,n-1)
    {
        FOR(j,0,m-1)
        {
            x=xr[i]+yr[j];
            if(x<=r&&x>=l)ar[c]=x, c++;
        }
    }

    sort(ar,ar+c);///handle 0
    FOR(i,0,c-1)
    {
        ///cout<<ar[i]<<' ';
        if(i==0&&ar[i]>l) d=ar[i]-l;
        if(ar[i]>=l&&ar[i+1]<=r&&ar[i+1]>0)
            d=max(d,ar[i+1]-ar[i]-1);
        else if(ar[i]>=l)
            d=max(d,r-ar[i]);
        else if(ar[i]<l)
            d=max(d,ar[i+1]-l);
    }
    if(c==0) cout<<r-l+1<<NL;
    else cout<<d<<NL;
    return 0;
}

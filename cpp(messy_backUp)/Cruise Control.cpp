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
typedef pair<double,double> pr;

double d;
int n;
pr ar[10010];

int chk(double sp)
{
    double a,b,c,e=0;
    c=d/sp;
    FOR(i,0,n-1)
    {
        a=(d-ar[i].F);
        a/=ar[i].S;
        e=max(e,a);
    }
    if(e>c)return 0;
    return 1;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,x,y;
        cin>>d>>n;
        FOR(i,0,n-1) cin>>ar[i].F>>ar[i].S;
        double st,en,mid,a,b,c=0;
        st=0; en=mod;

        FOR(i,0,100)
        {
          mid=(st+en)/2;
          x=chk(mid);
          //cout<<x<<NL;
          if(x==1) st=mid;
          else en=mid;
        }
        cout<<"Case #"<<tt<<": ";
        cout<<fixed;
        cout<<setprecision(9)<<mid<<NL;
    }
    return 0;
}

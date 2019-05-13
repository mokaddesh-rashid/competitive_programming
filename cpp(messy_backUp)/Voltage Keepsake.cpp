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

int n;
pr ar[100010];
double p;

int chk(double x)
{
   double a,b,c,d=x*p;

   FOR(i,0,n-1)
   {
       a=(x*ar[i].F)-ar[i].S;
       if(a>0) d-=a;
   }
   if(d<0) return 0;
   else return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y;
    double a=0,b,c=0,d,st,en,mid;
    cin>>n>>p;
    FOR(i,0,n-1) cin>>ar[i].F>>ar[i].S, c+=ar[i].F;
    st=0; en=maxx;
    FOR(i,0,100)
    {
      mid=(st+en)/2;
      x=chk(mid);
      if(x==0) en=mid;
      else st=mid, a=max(a,mid);
    }
    if(c<=p)
    {
        cout<<-1<<NL;
        return 0;
    }
    cout << fixed;
    cout << setprecision(9) << a << '\n';
    return 0;
}

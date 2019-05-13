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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

class Compare
{
public:
   bool operator()(pr x, pr y)
   {
       if(x.F==y.F) return x.S>y.S;
       else return x.F<y.F;
   }
};
pr ho[sz],vo[sz];
LL n,k,m,ar[sz],h,v,s,f;

void houp(LL a,LL b,LL x,LL y)
{
    if(b>y) swap(b,y);
    ho[h].F=b; ho[h].S=y; h++;
    return;
}

void voup(LL a,LL b,LL x,LL y)
{
    if(a>x) swap(a,x);
    vo[v].F=a; vo[v].S=x; v++;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        h=v=0;
        LL i,j,x,y,a,b,c,d;

        cin>>n>>k>>m;
        f=(n-k)/2+1; s=f+k-1;

        FOR(i,0,m-1)
        {
            cin>>a>>b>>x>>y;
            houp(a,b,x,y); voup(a,b,x,y);
        }

        sort(ho,ho+h,Compare());
        sort(vo,vo+v,Compare());

        b=a=f-1; c=0; i=0;
        //cout<<f<<' '<<s<<' '<<NL<<NL;
        ///FOR(i,0,h-1) cout<<ho[i].F<<' '<<ho[i].S<<NL;
        ///cout<<NL;
        while(true)
        {
           while(i<h&&ho[i].F<=a+1)
           {
              b=max(b,ho[i].S);
              i++;
           }
           if(b!=a)
           {
               c++;
               a=b;
           }
           else
           {
               break;
           }
           if(b>=s) break;
           ///cout<<a<<' '<<b<<NL;
        }
       /// cout<<c<<NL;

      ///  FOR(i,0,v-1) cout<<vo[i].F<<' '<<vo[i].S<<NL;
        d=a=f-1; i=0;
        while(true) ///cout<<ho[i].F<<' '<<ho[i].S<<NL;
        {
           while(i<v&&vo[i].F<=a+1)
           {
              d=max(d,vo[i].S);
              i++;
           }
           if(d!=a)
           {
               c++;
               a=d;
           }
           else
           {
               break;
           }
           if(d>=s) break;
        }

        if(b>=s&&d>=s) cout<<c<<NL;
        else cout<<-1<<NL;
    }
    return 0;
}

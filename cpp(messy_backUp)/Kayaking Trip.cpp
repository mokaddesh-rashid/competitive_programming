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
typedef pair<LL,LL> pr;

LL ar[MAX],n,m,b,e,sb,sn,se;
struct node
{
    LL b,n,e,v;
}val[10];
pr troll[10];

LL chk(LL v)
{
   LL x,y,z,p,q,r,sp,sq,sr,ret=0,c;

   p=b; q=n; r=e;
   sp=sb; sq=sn; sr=se;

   FOR(i,0,m-1)
   {
       c=0;
       FOR(j,0,5)
       {
          x=troll[j].S;
          ///cout<<ar[i]*val[x].v<<NL;
          if( p-val[x].b>=0 && q-val[x].n>=0 && r-val[x].e>=0 && ar[i]*val[x].v>=v )
          {
             ///cout<<x<<"  "<<' '<<val[x].b<<' '<<val[x].n<<' '<<val[x].e<<NL;
             p-=val[x].b; q-=val[x].n; r-=val[x].e;
             c=1;
             break;
          }
       }
       if(c==0)return 0;
   }
   return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL i,j,st,en,mid,c=0;

    cin>>b>>n>>e;
    cin>>sb>>sn>>se;

    m=(b+n+e)/2;
    FOR(i,0,m-1)cin>>ar[i];
    sort(ar,ar+m);

    val[0].v=sb+sb; val[0].b=2;
    val[1].v=sb+sn; val[1].b=1; val[1].n=1;
    val[2].v=sb+se; val[2].b=1; val[2].e=1;

    val[3].v=sn+sn; val[3].n=2;
    val[4].v=sn+se; val[4].n=1; val[4].e=1;
    val[5].v=se+se; val[5].e=2;
    FOR(i,0,5)
    {
        troll[i].F=val[i].v;
        troll[i].S=i;
    }
    sort(troll,troll+6);
    //cout<<chk(1700)<<NL;

    st=0;en=mod;

    while(st<=en)
    {
       mid=(st+en)/2;
       if(chk(mid))st=mid+1,c=max(c,mid);
       else en=mid-1;
    }
    cout<<c<<NL;

    return 0;
}



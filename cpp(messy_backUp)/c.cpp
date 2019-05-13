#include<bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout);
#define pb push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define sf(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d %d",&x,&y)
#define sf3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sl2(x,y) scanf("%lld %lld",&x,&y)
#define sl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define sd(x) scanf("%lf",&x);
#define pii pair<int,int>
#define pLL pair<long long,long long>
#define pDB pair<double,double>
#define ff first
#define sn second
#define PRINT_CASE  printf("Case %d: ",tc++)
#define PRINT_CASENL  printf("Case %d:\n",tc++)
//#define mx 100005
#define lnd tree[ind<<1]
#define rnd tree[(ind<<1)+1]
#define cnd tree[ind]
#define lndp b,(b+e)>>1,(ind<<1)
#define rndp ((b+e)>>1)+1,e,(ind<<1)+1
#define IN(a,x,y) (a>=x && a<=y)
#define popcountL __builtin_popcountll
#define popcount __builtin_popcount
/// int other=mask^((1<<n)-1);
typedef long long ll;
typedef long long int lln;
ll INF=1<<28;
//typedef long long lld;
const double pi=acos(-1.0);
int fx[]={1,-1,0,0}; //direction array
int fy[]={0,0,1,-1};
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int knight[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1};
const long double EPS=1e-7;
//#define INF 10000
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
//struct compare
//{
//  bool operator()(const int& l, const int& r)
//  {
//      return l>r;
//  }
//};

bool cmp(int a, int b)
{
    return a<b;
}
int on(int mask,int st)
{
    return mask|(1<<st);
}
int off(int mask,int st)
{
    return mask&(~(1<<st));
}
bool check(int mask,int st)
{
    return mask&(1<<st);
}
///code goes from here


#define MX 200100
ll inf=1e8;
ll MOD=1e9+7;
ll mod=1e9+7;
int arr[MX];
int tree[4*MX];
void build(int b,int e,int ind)
{
    if(b==e)
    {
        cnd=arr[b];
        return;
    }
    build(lndp);
    build(rndp);
    cnd=max(lnd,rnd);
    return;
}
int query(int b,int e,int ind,int st,int en)
{
    if(st>e || en<b)
        return 0;
    if(st<=b && e<=en)
        return cnd;
    return max(query(lndp,st,en),query(rndp,st,en));
}
int n;
pii fun(int ind)
{
    int l=1,r=ind,mid;
//    cout<<ind<<endl;
    int x=-1,y=-1,q;
    while(l<=r)
    {
        mid=(l+r)>>1;
//        cout<<mid<<endl;
        q=query(1,n,1,mid,ind);
        if(q==arr[ind])
        {
            x=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    l=ind,r=n;
    while(l<=r)
    {
        mid=(l+r)>>1;
        q=query(1,n,1,ind,mid);
        if(q==arr[ind])
        {
            y=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return {x,y};

}
int vis[MX];
int main()
{
    READ;
//    WRITE;
    sf(n);
    for(int i=1;i<=n;i++)
    {
        sf(arr[i]);
        vis[arr[i]]=i;
    }
    build(1,n,1);
    ll ans=0;
    int ind;
    for(int i=1;i<=n;i++)
    {
        ind=vis[i];
        pii p=fun(ind);
        int x=ind-p.ff;
        int y=p.sn-ind;
//        cout<<p.ff<<" "<<p.sn<<endl;
//        return 0;
        if(x>y)
        {
            int l=ind+1;
            while(l<=p.sn)
            {
                x=abs(i-arr[l]);
                if(vis[x]>=p.ff && vis[x]<ind)
                {
                    ans++;
                }
                l++;
            }
        }
        else
        {
            int l=p.ff;
            while(l<ind)
            {
                x=abs(i-arr[l]);
                if(vis[x]<=p.sn && vis[x]>ind)
                {
                    ans++;
                }
                l++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}

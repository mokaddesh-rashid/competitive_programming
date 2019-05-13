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
#define ff first
#define sn second
#define PRINT_CASE  printf("Case %d: ",tc++)
#define PRINT_CASENL  printf("Case %d:\n",tc++)
#define mx 100005
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
int on(int mask,int pos)
{
    return mask|(1<<pos);
}
int off(int mask,int pos)
{
    return mask&(~(1<<pos));
}
bool check(int mask,int pos)
{
    return mask&(1<<pos);
}
ll inf=1e18;
//ll mod=1e9+7;
ll mod=993344777;
const int sz=300005;
struct Edge{
    int u,v,w;
    bool operator<(const Edge& p)const
    {
        return w<p.w;
    }
};
ll dp[(1<<16)+1][21];
int vis[(1<<16)+1][21],n,m,color;
int base,k;
string s;
int basemul[20][20];
map<char,int>mp;
ll fun(int mask,int rem)
{
//    cout<<mask<<" "<<rem<<endl;
    int x=popcount(mask);
    if(x==n)
        return rem==0;
    if(vis[mask][rem]==color)
    {
        return dp[mask][rem];
    }
    vis[mask][rem]=color;
    ll ans=0;
    int y;
    for(int i=0;i<n;i++)
    {
        if(!check(mask,i))
        {
            y=mp[s[i]];
            ans+=fun(on(mask,i),((rem+(basemul[base][x]*y))%k));
        }
    }
    return dp[mask][rem]=ans;
}
int main(void){
    READ;
    for(int i=0;i<=9;i++)
    {
        mp[(char)(i+'0')]=i;
    }
    mp['A']=10;
    mp['B']=11;
    mp['C']=12;
    mp['D']=13;
    mp['E']=14;
    mp['F']=15;
    int t,tc=1;
    sf(t);
    while(t--)
    {
        color++;
        sf2(base,k);
        for(int i=2;i<=16;i++)
        {
            basemul[i][0]=1;
            basemul[i][1]=i%k;
        }
        for(int i=2;i<=16;i++)
        {
            for(int j=2;j<=16;j++)
            {
                basemul[i][j]=basemul[i][j-1]*i;
                basemul[i][j]%=k;
            }
        }
        cin>>s;
        n=s.length();
        PRINT_CASE;
        cout<<fun(0,0)<<endl;
    }

    return 0;
}

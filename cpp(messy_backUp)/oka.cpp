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
#define mx 100005
#define lnd tree[ind<<1]
#define rnd tree[(ind<<1)+1]
#define cnd tree[ind]
#define lndp b,(b+e)>>1,(ind<<1)
#define rndp ((b+e)>>1)+1,e,(ind<<1)+1
#define IN(a,x,y) (a>=x && a<=y)
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

bool cmp(int a, int b)
{
    return a<b;
}

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return l>r;
  }
};
bool cmp1(int a,int b)
{
    return a>b;
}
int a,b;
int len;
vector<int>num;
int mod=1e9+7;
int vis[52][2][18][18][18];
int dp[52][2][18][18][18],color;
void numm(string n)
{
    num.clear();
    len=n.length();
    for(int i=0;i<len;i++){
        num.pb(n[i]-'0');
    }
}
ll fun(int pos,int f,int freq3,int freq6,int freq9)
{
//    cout<<" pos "<<pos<<" "<<freq3<<endl;
    if(pos==len)
    {
        if(freq3==freq6 && freq6==freq9 && freq3)
            return 1;
        else
            return 0;
    }
    if(freq3>=17 || freq6>=17 || freq9>=17)
        return 0;
    if(vis[pos][f][freq3][freq6][freq9]==color)
        return dp[pos][f][freq3][freq6][freq9];
    vis[pos][f][freq3][freq6][freq9]=color;
    int ans=0;
    int j=num[pos];
    if(f)
        j=9;
    for(int i=0;i<=j;i++)
    {
        ans+=fun(pos+1,i<j?1:f,freq3+(i==3),freq6+(i==6),freq9+(i==9));
        ans%=mod;
    }
    return dp[pos][f][freq3][freq6][freq9]=ans;
}
int cn[11];
int main()
{
    READ;
//    WRITE;
    int t,tc=1;
    sf(t);
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        numm(b);
        color++;
        int x=fun(0,0,0,0,0);
        numm(a);
        color++;
        for(int i=0;i<len;i++)
        {
            cn[a[i]-'0']++;
        }
        int f=0;
        if(cn[3]== cn[6] && cn[6]==cn[9] && cn[3])
        {
            f=1;
        }
        cn[3]=0;
        cn[6]=0;
        cn[9]=0;
        int y=fun(0,0,0,0,0);
        printf("%d\n",(x-y+f+mod)%mod);
    }
    return 0;
}

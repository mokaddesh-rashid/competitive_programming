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
ll inf=1e18;
//ll MOD=1e9+7;
ll MOD=1e9+7;
ll mod=1e9;
int arr[200000];
pii tree[4*200000];
void build(int b,int e,int ind)
{
    if(b==e)
    {
        cnd={arr[b],b};
        return;
    }
    build(lndp);
    build(rndp);
    cnd=max(lnd,rnd);
}
void update(int b,int e,int ind,int st,int en,ll val)
{
    if(st>e || en<b || st>en)
    {
        return;
    }
    if(st<=b && e<=en)
    {
        cnd.ff=INT_MIN;
        return;
    }
    update(lndp,st,en,val);
    update(rndp,st,en,val);
    cnd=max(lnd,rnd);
}
pii query(int b,int e,int ind,int st,int en)
{
    if(st>e || en<b)
    {
        return {INT_MIN,0};
    }
    if(st<=b && e<=en)
    {
        return cnd;
    }
    if(lnd.ff>rnd.ff)
        return lnd;
    return rnd;
}
int ans[200000];
int main()
{
//    READ;
//    WRITE;
    mem(ans,-1);
    int n,k;
    ///sf2(n,k);
    n = 200000; k = 1;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        ///sf(arr[i]);
        arr[i] = i;
        st.insert(i);
    }
    build(1,n,1);
    vector<int>v;
    set<int> :: iterator it,itr;
    int turn=0;
    while(st.size()!=0)
    {
        pii q=query(1,n,1,1,n);
//        cout<<q.sn<<endl;
        it=st.find(q.sn);
        int tmp=k+1;
        for(itr=it;;itr--)
        {
            v.pb(*itr);
//            cout<<"left "<<*itr<<endl;
            tmp--;
            if(tmp==0 || itr==st.begin())
                break;
        }
        tmp=k+1;
        for(itr=it;itr!=st.end();itr++)
        {
            v.pb(*itr);
            tmp--;
            if(tmp==0)
                break;
        }
        for(int i=0;i<v.size();i++)
        {
            update(1,n,1,v[i],v[i],INT_MIN);
            if(v[i] > 200000) cout << "dhur " << endl;
            if(ans[v[i]]==-1)
                st.erase(v[i]);
            ans[v[i]]=turn;
        }
        v.clear();
        turn++;
        turn%=2;
    }
//    cout<<ans[1]+1;
//    for(int i=2;i<=n;i++)
//    {
//        printf("%d",ans[i]+1);
//    }
//    cout<<endl;
    return 0;
}

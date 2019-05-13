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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


struct info
{
    LL x,y,z,p,t;
}ar[sz];
LL t1,t2;

class compare
{
public:
    bool operator()(info f,info s)
    {
        if(f.z==s.z) return f.p>s.p;
        else return f.z>s.z;
    }
};

LL cnt[sz];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,n=0,m,a,b,c,d,e=0;

    cin>>t1>>t2;
    cin>>c;
    FOR(j,1,c)
    {
       ///cout<<j<<"  L  "<<c<<NL;
       a=b=0;
       cin>>e;
       ///cout<<n<<"  k "<<n+e<<NL;
       FOR(i,n,n+e-1) cin>>ar[i].x;// a+=ar[i].x;
       FOR(i,n,n+e-1) cin>>ar[i].y;// b+=ar[i].y;
       FOR(i,n,n+e-1)
       {
           ar[i].z=abs(ar[i].x-ar[i].y);
           ar[i].p=j;
           if(ar[i].x>ar[i].y) ar[i].t=1;
           else ar[i].t=2;
       }
       n+=e;
       ///cout<<a<<' '<<b<<NL;
    }
    sort(ar,ar+n,compare());

    d=c;
    a=b=c=0;
    FOR(i,0,n-1)
    {
        ///cout<<ar[i].z<<NL;
        if(a==t1) c+=ar[i].y;
        else if(b==t2) c+=ar[i].x, cnt[ar[i].p]++;
        else if(ar[i].t==1) c+=ar[i].y;
        else c+=ar[i].x, cnt[ar[i].p]++;
    }

    FOR(i,1,d)  cout<<cnt[i]<<' ';
    cout<<c<<NL;
    return 0;
}



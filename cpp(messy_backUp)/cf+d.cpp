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
#define MAX 300010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL sum[MAX],pos[MAX],neg[MAX],tim[MAX],n,m,a,b,c,d,start,len,babu[MAX];
pr in[MAX];


int chk(int v)
{
    LL x=v, y=v+len-1,z=0,px,py,so,sp,sn;

    if(v<0)return 0;

        px=lower_bound(tim,tim+n,x)-tim;
        py=upper_bound(tim,tim+n,y)-tim;
        py--;

        if(tim[px]<=y&&px<=py)
        {
            so=sum[py]; sp=pos[py]; sn=neg[py];
            if(px!=0) so-=sum[px-1], sp-=pos[px-1], sn-=neg[px-1];
            so=so+(so*(c-a)-sn*(d-b));
            ///cout<<v<<' '<<so<<NL;
            ///cout<<babu[py]<<' '<<py<<' '<<px<<' '<<sp<<' '<<sn<<NL;
            if(so>=0&&so+babu[py]>=0)return 1;
        }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;

    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,x,y,z=0,po,ne,mx=-1,st=0,en=mod,mid,ans=mod;

        cin>>n>>a>>b>>c>>d>>start>>len;

        po=ne=0;
        FOR(i,0,n-1) cin>>in[i].F>>in[i].S;
        sort(in,in+n);

        z=start;
        FOR(i,0,n-1)
        {
            x=in[i].F; y=in[i].S;
            if(y)po++,z+=a;
            else ne++,z-=b;

            if(z<0)en=min(en,tim[i]-1);

            sum[i]=z; pos[i]=po; neg[i]=ne;
            tim[i]=x;
        }
        REV(i,n-1,0)
        {
            if(i==n-1)x=sum[i];
            else x=min(x,sum[i]);
            babu[i]=x;
        }

        if(chk(0))ans=0;
        if(babu[0]>=0)ans=min(ans,tim[n-1]+1);

        FOR(i,0,n-1)
        {
            if(tim[i]>en)continue;
            if(chk(tim[i]-len+1))ans=min(ans,tim[i]-len+1);
            if(chk(tim[i]-len))ans=min(ans,tim[i]-len);
            if(chk(tim[i]+1))ans=min(ans,tim[i]+1);
            if(chk(tim[i]))ans=min(ans,tim[i]);
        }
        if(ans==mod)ans=-1;
        cout<<ans<<NL;
    }
    return 0;
}



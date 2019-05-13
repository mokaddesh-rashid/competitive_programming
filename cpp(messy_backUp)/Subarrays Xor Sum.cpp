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

LL ar[MAX],in[MAX],a,b,n,sm[MAX],br[MAX];

LL up()
{
    LL x,y,z=0,c=0,cnt=0,d=0;

    FOR(i,1,n-1) ar[i]=ar[i]^ar[i-1];
    //FOR(i,0,n-1)cout<<ar[i]<<' ';
    ///cout<<NL;

    FOR(i,0,n-1) c+=ar[i],sm[i]=c;
    ///FOR(i,0,n-1)cout<<sm[i]<<' ';
    ///cout<<NL<<NL;

    c=0;
    FOR(i,0,n-1)
    {
        x=i+a-1; y=min(i+b-1,n-1);
        if(x>=n)break;

        z=sm[y];
        if(x!=0)z-=sm[x-1];
        if(cnt%2) z=((y-x)+1)-z;
        ///cout<<x<<' '<<y<<' '<<z<<' '<<c<<' '<<' '<<NL;
        c+=z;
        cnt+=br[i];
    }
    ///cout<<c<<NL;
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    LL i,j;
    LL c=0,x,y,z;

    cin>>n>>a>>b;
    FOR(i,0,n-1)cin>>in[i];

    FOR(j,0,31)
    {
        mem(ar,0);mem(br,0);
        FOR(i,0,n-1)if(in[i]&(1<<j))br[i]=ar[i]=1;

        ///FOR(i,0,n-1)cout<<ar[i]<<' ';
        ///cout<<NL;
        x=up()*(1<<j);
        //cout<<x<<NL<<NL;
        c+=x;
        c%=mod;
    }

    cout<<c<<NL;
    return 0;
}



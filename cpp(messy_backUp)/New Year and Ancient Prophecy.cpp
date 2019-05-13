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
#define Mo          1000000000
#define M1          1000000007
#define M2          100000007
#define B1          11
#define B2          11
#define M_PI           3.14159265358979323846  /* pi */
#define LL            long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 5010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

pr ar[MAX], inv[MAX], po[MAX], br[MAX];
string str,ss;

LL bm(LL n, LL p, int m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bm(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

LL modinv( LL n, LL p )
{
    return bm( n, p-2, p );
}

void info()
{
    LL n=str.size(),x=1,y=1;

    FOR(i,0,MAX-1)
    {
        po[i].F=x; x*=B1; x%=M1;
        po[i].S=y; y*=B2; y%=M2;
    }
    FOR(i,0,MAX-1)
    {
        inv[i].F=modinv(po[i].F,M1);
        inv[i].S=modinv(po[i].S,M2);
    }
}

void hasho()
{
    LL n=str.size(),m,i,j,a,b,c,x=0,y=0,z;

    FOR(i,0,n-1)
    {
       a=str[i]-'0';a++;
       x+=(po[i].F*a); y+=(po[i].S*a);
       x%=M1; y%=M2;
       ar[i].F=x;  ar[i].S=y;
    }
}

LL sub_hasho(pr ar[],int l,int r)
{
    LL a,b,c,x,y,z;

    x=ar[r].F; x+=M1;
    if(l!=0) x-=ar[l-1].F;
    x*=inv[l].F;
    x%=M1;

    y=ar[r].S; y+=M2;
    if(l!=0) y-=ar[l-1].S;
    y*=inv[l].S;
    y%=M2;

    return x*Mo+y;
}

int sdp[MAX][MAX];
int big(int p1, int p2, int v)
{
    if(sdp[p1][v]!=-1)return sdp[p1][v];
    int mid,st=0,en=v,a,b,c=0;
    LL x,y,z;

    while(st<=en)
    {
        mid=(st+en)>>1;
        x=sub_hasho(ar,p1,p1+mid); y=sub_hasho(ar,p2,p2+mid);
        if(x==y) st=mid+1, c=max(c,mid+1);
        else en=mid-1;
    }
    p1+=c; p2+=c;
    if(v<c) return sdp[p1][v]=0;
    if(str[p1]>str[p2]) return sdp[p1][v]=1;
    if(str[p1]<str[p2]) return sdp[p1][v]=2;
}

LL  dp[MAX][MAX], n;

LL rec(int p,int v)
{
    if(p+v==n) return 1;
    if(p+v>n) return 0;
    if(dp[p][v]!=-1) return dp[p][v];

    dp[p][v]=rec(p,v+1);

    int np=p+v;
    if(np+v<=n&&big(p,np,v-1)==2&&str[np]!='0') dp[p][v]+=rec(np,v);
    else if(np+v+1<=n&&str[np]!='0') dp[p][v]+=rec(np,v+1);

    return dp[p][v]%M1;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    info();
    mem(dp,-1);mem(sdp,-1);

    int i,j,m;
    LL a,b,c,x,y,z;
    pr d,e;

    cin>>n;
    cin>>str;
    hasho();

    cout<<rec(0,1)<<NL;
   /// cout<<big(0,4,3)<<NL;

    return 0;
}

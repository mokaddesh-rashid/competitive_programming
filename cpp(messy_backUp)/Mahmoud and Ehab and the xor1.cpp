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
#define Mo          10000000000
#define M1          1000000007
#define M2          100000007
#define B1          11
#define B2          11
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
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

string str,ss;

int sdp[MAX][MAX];
int big(int p1, int p2, int v)
{
    if(sdp[p1][v]!=-1)return sdp[p1][v];

    string ss="",so="";

    FOR(i,p1,p1+v)ss+=str[i];
    FOR(i,p2,p2+v)so+=str[i];

    if(ss>=so) return sdp[p1][v]=1;
    else return sdp[p1][v]=2;
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
//    info();
    mem(dp,-1);mem(sdp,-1);

    int i,j,m;
    LL a,b,c,x,y,z;
    pr d,e;

    cin>>n;
    cin>>str;
//    hasho();

    cout<<rec(0,1)<<NL;
   /// cout<<big(0,4,3)<<NL;

    return 0;
}

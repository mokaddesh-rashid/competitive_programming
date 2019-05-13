
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
typedef pair<int,int> pr;

struct info
{
    LL x,y,z,p;
}in[MAX];
LL ar[MAX],br[MAX],cnt[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,n,s,a,b,c=0,d;

    cin>>n>>s;
    FOR(i,0,n-1)cin>>in[i].p>>in[i].x>>in[i].y;

    FOR(i,0,n-1)
    {
        a=in[i].p; c+=a; cnt[i]=c;
        ar[i]=a*in[i].x; br[i]=a*in[i].y;
    }
    FOR(i,1,n-1)
    {
        ar[i]+=ar[i-1]
        br[i]+=br[i-1];
    }

    d=c/s;
    if(c%s)d++;

    st=0;en=d;

    while(st)
    return 0;
}


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
#define MAX 2050
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
    int i,d,p,pos;
}in[MAX];
int dp[MAX][MAX],n;

class compare
{
public:
    bool operator()(info x,info y)
    {
        return x.d<y.d;
    }
};

int rec(int p,int t)
{
    if(p==n)return 0;
    if(dp[p][t]!=-1)return dp[p][t];

    int a=t+in[p].i;

    if(a<in[p].d)return dp[p][t]=max(in[p].p+rec(p+1,a),rec(p+1,t));
    else return dp[p][t]=rec(p+1,t);


}

int np,ans[MAX];
void prin(int p,int t)
{
    if(p==n)return;

    int a=t+in[p].i;

    if(a<in[p].d)
    {
        if(in[p].p+rec(p+1,a)==rec(p,t))
        {
           ans[np++]=in[p].pos;
           prin(p+1,a);
           return;
        }
    }
    prin(p+1,t);
    return;


}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,m;

    cin>>n;
    FOR(i,0,n-1)cin>>in[i].i>>in[i].d>>in[i].p,in[i].pos=i+1;
    sort(in,in+n,compare());

    cout<<rec(0,0)<<NL;
    prin(0,0);
    sort(ans,ans+np);
    cout<<np<<NL;
    FOR(i,0,np-1)cout<<ans[i]<<' ';
    return 0;
}



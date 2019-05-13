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
#define MX 5010
#define inf (1<<30)
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[MX][MX];
vector<int>mat[MX], cost[MX];
int n, m, v;

int rec(int p,int ase)
{
    //cout<<p<<' '<<ase<<NL;
    if(p==n&&ase==0) return 0;
    if(p==n||ase==0) return inf;
    if((int)mat[p].size()==0) return inf;
    //cout<<p<<NL;
    if(dp[p][ase]!=-1) return dp[p][ase];

    int ret=inf, x, y;
    FOR(i,0,(int)mat[p].size()-1)
    {
        x=mat[p][i];
        y=cost[p][i];

        ret=min(ret,y+rec(x,ase-1));
    }
    return dp[p][ase]=ret;
}

void prin(int p,int ase)
{
    cout<<p<<' ';
    if(p==n&&ase==0) return;
    if(p==n||ase==0) return;
    if((int)mat[p].size()==0) return;

    int ret=inf, x, y;
    FOR(i,0,(int)mat[p].size()-1)
    {
        x=mat[p][i];
        y=cost[p][i];
        if(y+rec(x,ase-1)==dp[p][ase]) return prin(x,ase-1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,x,y,a,b,c;

    cin>>n>>m>>v;
    FOR(i,0,m-1)
    {
        cin>>a>>b>>c;
        mat[a].PB(b);
        cost[a].PB(c);
    }

    c=0;
    FOR(i,1,n)
    {
        x=rec(1,i);
        if(x<=v) c=i;
        ///cout<<x<<' '<<v<<NL;
    }
    cout<<c+1<<NL;
    prin(1,c);
    return 0;
}



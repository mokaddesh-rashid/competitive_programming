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
#define MAX 5010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int nex[MAX],n,k,t,asol[MAX];
vector<int>mat[MAX];
int dp[MAX][MAX];
bool can[MAX][MAX];

int dfs(int p,int pa)
{
    asol[t++]=p;
    int pc;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)dfs(x);
    }
    nex[p]=t;
}

int asol[MAX],off[MAX];
int rec(int p,int k)
{
    if(p==n&&k==0)return 0;
    if(p==n)return 0;

    return dp[p][k]=min()

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(child,-1); mem(sib,-1);
    int i,j,n,m,a,b,c=0;

    cin>>n>>k;
    FOR(i,1,n)
    {
        cin>>asol[i]>>off[i];
        if(i>1) cin>>a, mat[a].PB(i);
    }
    dfs(1,1);

    return 0;
}




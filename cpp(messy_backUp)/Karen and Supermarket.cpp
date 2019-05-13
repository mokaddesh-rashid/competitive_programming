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

int child[MAX],sib[MAX],n,k;
vector<int>mat[MAX];
int dp[MAX][MAX][2];
bool can[MAX][MAX][2];

int dfs(int p,int pa)
{
    int pc;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(x!=pa)
        {
            if(child[p]==-1) child[p]=x,pc=x;
            else sib[pc]=x, pc=x;
            dfs(x,p);
        }
    }
}

int asol[MAX],off[MAX];
int rec(int p,int k,int x)
{
    //cout<<p<<' '<<k<<NL;
    if(p==-1&&k==0)return 0;
    if(p==-1||k<0)return mod;
    if(can[p][k][x]==true)return dp[p][k][x];

    int temp=mod,a=asol[p];

    FOR(i,0,k)temp=min(temp,rec(child[p],i,1)+rec(sib[p],k-i,x));

    if(x==0)a-=off[p];
    FOR(i,0,k-1)temp=min(temp,a+rec(child[p],i,x)+rec(sib[p],(k-1)-i,x));
    can[p][k][x]=true;
    return dp[p][k][x]=temp;

}

int main()
{
    ios::sync_with_stdio(false);
    inf;
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

    int st=0,en=n,mid;

    while(st<=en)
    {
        mid=(st+en)/2;
        a=rec(1,mid,0);
        if(a>k)en=mid-1;
        else st=mid+1,c=max(mid,c);
    }
    cout<<c<<NL;

    return 0;
}




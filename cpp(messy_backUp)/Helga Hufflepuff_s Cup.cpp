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

LL dp[MAX][12][2],n,m,k;
vector<int>mat[MAX];

LL rec(int p, int x, int t,int pa)
{
    cout<<p<<' '<<x<<NL;
    if(mat[p].size()==0&&t==0&&x>0) return m;
    if(mat[p].size()==0&&t==0) return m-1;
    if(mat[p].size()==0) return k-1;
    //if(dp[p][x][t]!=-1) return dp[p][x][t];

    LL temp=0,te=0;
    if(t==0)
    {
        temp=1;
        FOR(i,0,(int)mat[p].size()-1)
        {
            int v=mat[p][i];
            if(v!=pa&&x>0) temp*=rec(v,x-1,1,p), temp%=mod;
        }
    }

    FOR(i,0,(int)mat[p].size()-1)
    {
        if(t==0) te=m-1;
        else te=k-1;
        int v=mat[p][i];
        if(v!=pa)
        {
            te*=rec(v,x,0,p); te%=mod;
        }
    }

    return dp[p][x][t]=temp+te;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    LL i,j,a,b,c,d;

    cin>>n>>m;
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b);
        mat[b].PB(a);
    }

    cin>>k>>b;
    FOR(i,1,n)
    {
        if((int)mat[i].size()==1)
        {
            cout<<rec(i,b,0,i)<<NL;
            return 0;
        }
    }
    return 0;
}



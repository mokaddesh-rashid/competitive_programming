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

int child[MAX],sib[MAX],n,k;
vector<int>mat[MAX];
int dp[MAX][100][2];

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

int rec(int p,int k,int x)
{
    //cout<<p<<' '<<k<<NL;
    if(p==-1&&k==0)return 1;
    if(p==-1||k<0)return 0;
    if(dp[p][k][x]!=-1)return dp[p][k][x];

    int temp=0;
    FOR(i,0,k)temp+=(rec(child[p],i,0)*rec(sib[p],k-i,x)); ///amr position_a_keso_bosche_naki_ta_amr_sibling_k_effect_kore_naah
    if(x==0)FOR(i,0,k-1)temp+=(rec(child[p],i,1)*rec(sib[p],(k-1)-i,x)); ///ami_and_amr_sibling_r_condition_same

    return dp[p][k][x]=temp;

}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(child,-1); mem(sib,-1); mem(dp,-1);
    int i,j,n,m,a,b;

    cin>>n>>k;
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    dfs(1,1);
    cout<<rec(1,k,0)<<NL;


    return 0;
}




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
#define MAX 3010
#define SZ 3010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    LL v, pa, l;
}bfa[MAX];

vector<int> mat[MAX];
int que[MAX], h, r, dp[3010][3010];

void bfs(int p,int pa)
{
    h = r = 0;
    dp[pa][p] = bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = p;
    r++;
    while( h != r )
    {
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( bfa[x].v == 0 )
            {
                dp[pa][x] = bfa[x].l = bfa[p].l+1;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        h++;
        p = que[h];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i,j,n,m,s,t,l,so,to,lo,a,b,c,x,y,z;

    cin>>n>>m;
    FOR(i,0,m-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    FOR(i,1,n) mem(bfa,0), bfs(i,i);
    cin>>so>>to>>lo;
    cin>>s>>t>>l;
    FOR(i,1,n)
    {
        ///FOR(j,1,n) cout<<dp[i][j]<<' ';
        ///cout<<NL;
    }

    if(dp[s][t]>l||dp[so][to]>lo||dp[s][t]==-1||dp[so][to]==-1)
    {
        cout<<-1<<NL;
        return 0;
    }
    c=dp[s][t]+dp[so][to];
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            x=dp[s][i]+dp[so][i]+dp[i][j]+dp[j][t]+dp[j][to];
            if(dp[s][i]+dp[i][j]+dp[j][t]<=l)
                if(dp[so][i]+dp[i][j]+dp[j][to]<=lo) c=min(c,x);
            swap(s,t);
            x=dp[s][i]+dp[so][i]+dp[i][j]+dp[j][t]+dp[j][to];
            if(dp[s][i]+dp[i][j]+dp[j][t]<=l)
                if(dp[so][i]+dp[i][j]+dp[j][to]<=lo) c=min(c,x);
        }
    }
    cout<<m-c<<NL;
    return 0;
}



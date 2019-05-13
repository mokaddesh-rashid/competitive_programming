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
#define MAX 1010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int mat[MAX][MAX],vis[MAX][MAX],row,col,n,m,ans[MAX][MAX],ty[MAX][MAX],shit;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

void dfs(int x,int y)
{
    vis[x][y]=1;
    int a,b,c;

    FOR(i,0,3)
    {
        a=x+fx[i];b=y+fy[i];
        if(valid(a,b)&&vis[a][b]==0&&mat[a][b]==0)
        {
            dfs(a,b);
            if(ty[a][b]==0)ans[x][y]+=ans[a][b];
        }
    }
    ans[x][y]++;
    shit=max(shit,ans[x][y]);
    c=0;
    FOR(i,0,3)
    {
        a=x+fx[i];b=y+fy[i];
        c+=ty[a][b];
        if(!valid(a,b)||c>1)ty[x][y]=1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,a,b,c=0;

    cin>>n>>m;row=n;col=m;

    FOR(i,0,n-1)
    FOR(j,0,m-1)
    {
        cin>>mat[i][j];
        c+=mat[i][j];
    }

    FOR(i,0,n-1)
    FOR(j,0,m-1)
    {
        if(vis[i][j]==0&&mat[i][j]==0)dfs(i,j);
    }
    cout<<shit<<NL;
    return 0;
}



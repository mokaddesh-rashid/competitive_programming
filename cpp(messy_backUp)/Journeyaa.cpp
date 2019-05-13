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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int leaf[MAX], vis[MAX], dis[MAX];
double shit[MAX];
vector<int>mat[MAX];

int dfs(int p,double b)
{
    shit[p]=b;
    double a;
    vis[p]=1; a=(int)mat[p].size();
    if(p!=1) a--;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(vis[x]==0)
        {
            dis[x]=dis[p]+1;
            dfs(x,b/a);
            leaf[p]=1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a;
    LL c=0, b=0;
    double x=0,y=0,z=0;

    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b); mat[b].PB(a);
    }
    dfs(1,1);
    b=0;
    FOR(i,1,n)
    {
        if(leaf[i]==0)
        {
            x=dis[i]; y=shit[i];
            z+=(x*y);
            ///cout<<i<<' '<<x<<' '<<y<<NL;
        }
    }
    cout << fixed;
    cout << setprecision(9) << z << '\n';

    return 0;
}



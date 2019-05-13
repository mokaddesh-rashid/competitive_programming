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
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))


int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

string str[1001], wa[1001];
int n,m, vis[1001][1001], col[1000100], ole[1000100];

void dfs(int x,int y,int c)
{
    //cout<<x<<' '<<y<<NL;
    int a,b,d,z;
    vis[x][y]=c; col[c]++;
    FOR(i,0,3)
    {
        a=x+fx[i]; b=y+fy[i];
        if(valid(a,b)&&str[a][b]=='.'&&vis[a][b]==0) dfs(a,b,c);

    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, a, b, c=0;
    cin>>n>>m;
    FOR(i,0,n-1)
    {
        cin>>str[i]; wa[i]=str[i];
    }
    FOR(i,0,n-1)
    FOR(j,0,m-1)
    {
        if(vis[i][j]==0&&str[i][j]=='.') c++,  dfs(i,j,c);
    }

    FOR(i,0,n-1)
    {
        FOR(j,0,m-1)
        {
           if(str[i][j]=='*')
           {
               x=0;
               FOR(k,0,3)
               {
                   a=i+fx[k]; b=j+fy[k];
                   if(valid(a,b))
                   {
                       c=vis[a][b]; if(ole[c]==0) x+=col[c];
                       ole[c]=1;
                   }
               }
               FOR(k,0,3)
               {
                   a=i+fx[k]; b=j+fy[k];
                   if(valid(a,b))
                   {
                       c=vis[a][b];
                       ole[c]=0;
                   }
               }
               x++;
               x%=10;
               wa[i][j]=x+'0';
           }
        }
    }
    FOR(i,0,n-1) cout<<wa[i]<<NL;
    return 0;
}



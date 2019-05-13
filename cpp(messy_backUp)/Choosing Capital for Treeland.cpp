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
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[sz],cost[sz],ans;
int dp[sz][3],in[sz],vis[sz],mn;

int rec(int p)
{
   vis[p]=1;
   if(mat[p].size()==0) return 0;

   int a=0,b,c,d,x,y,z;
   z=mat[p].size();
   FOR(i,0,z-1)
   {
       x=mat[p][i]; y=cost[p][i];
       if(vis[x]==0)
       {
           a+=( y+rec(x) );
       }
   }
   return a;
}

void value(int p,int v)
{
    mn=min(mn,v);
    vis[p]=1; in[p]=v;
    int a,b,x,y,z;
    z=mat[p].size();
    FOR(i,0,z-1)
    {
       x=mat[p][i]; y=cost[p][i];
       if(vis[x]==0)
       {
           if(y==0) value(x,v+1);
           else value(x,v-1);
       }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c;
    mn=mod;
    cin>>n;
    FOR(i,0,n-2)
    {
        cin>>a>>b;
        mat[a].PB(b); cost[a].PB(0);
        mat[b].PB(a); cost[b].PB(1);
    }

    x=rec(1);
    mem(vis,0);
    value(1,x);

    cout<<mn<<NL;
    FOR(i,1,n) if(in[i]==mn) cout<<i<<' ';
    return 0;
}



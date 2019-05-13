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
#define sz 110
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    int l,r,p;
}ar[sz];

vector<int> mat[sz];
int vis[sz];

void dfs(int p)
{
    vis[p]=1;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(vis[x]==0)dfs(x);
    }
    return;
}

int up(int v,int j)
{
   if(ar[j].l<ar[v].l&&ar[v].l<ar[j].r)return 1;
   if(ar[j].l<ar[v].r&&ar[v].r<ar[j].r)return 1;
   return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,x,y,z,v=1;

    cin>>n;
    FOR(i,1,n)
    {
       cin>>a;
       if(a==1)
       {
           cin>>b>>c;
           ar[v].l=b; ar[v].r=c; ar[v].p=v;
           v++;
       }
       else
       {
           cin>>b>>c;

           mem(vis,0);
           FOR(j,0,v)mat[j].clear();
           FOR(j,1,v-1)
           {
               FOR(k,1,v-1)
               {
                   x=ar[j].p; y=ar[k].p;
                   if(j!=k&&up(j,k)) mat[x].PB(y);
               }
           }
           dfs(b);

           if(vis[c]==1) cout<<"YES"<<NL;
           else cout<<"NO"<<NL;
       }
    }
    return 0;
}


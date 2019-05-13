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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    int c,l,g,v;
}dfa[sz];

int vis[sz], dur[sz];
vector<int>mat[sz];
pr ar[sz], tp;

void dfs(int p)
{
    vis[p]=1;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];

        if(vis[x]==0)
        {
            dfa[x].l=dfa[p].l+1;
            dfs(x);

            int a=dfa[x].c, b=dfa[p].c;

            if(a>0)
            {
                if(b==0) dfa[p].c=a;
                else if(dfa[b].l<dfa[a].l) dfa[p].c=a;
            }
        }
    }
    if(dfa[p].c==0&&dfa[p].g==1) dfa[p].c=p;

    dfa[p].v=dfa[dfa[p].c].l-dfa[p].l;
    if(dfa[p].c==0) dfa[p].v=mod*-1;
}

void rec(int p,int v)
{

    vis[p]=1;
    dur[p]=max(dfa[p].v,dur[p]);
    dur[p]=max(dur[p],v);
    int a,b,c,d,x,y,z;

    c=d=a=b=mod*-1-10;
    FOR(i,0,(int)mat[p].size()-1)
    {
        x=mat[p][i];
        if(vis[x]==0&&dfa[x].v>a)
        {
            c=a; d=b;
            a=dfa[x].v; b=x;
        }
        else if(vis[x]==0&&dfa[x].v>c)
        {
            c=dfa[x].v; d=x;
        }
    }

    FOR(i,0,(int)mat[p].size()-1)
    {
        x=mat[p][i];
        if(vis[x]==0)
        {
            if(x!=b) rec(x,max(v+1,a+2));
            else rec(x,max(v+1,c+2));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,d,x,y,z;

    cin>>n>>m>>d;
    FOR(i,1,m)
    {
        cin>>a;
        dfa[a].g=1;
    }
    FOR(i,1,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b);
        mat[b].PB(a);
    }

    FOR(i,1,n)
    {
        if(dur[i]==0)
        {
           mem(vis,0);
           FOR(j,1,n) dfa[j].c=dfa[j].v=dfa[j].l=0;
           dfs(i);
           mem(vis,0);
           rec(i,mod*-1);
        }
    }

    c=0;
    FOR(i,1,n) if(dur[i]<=d) c++;

    cout<<c<<NL;
    return 0;
}



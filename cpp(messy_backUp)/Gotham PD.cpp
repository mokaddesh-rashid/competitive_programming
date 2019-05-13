#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

struct node
{
    LL v, pa, l, k;
}dfa[100010];
vector<LL> mat[100010];
map<LL,LL>shit;
LL mx,mn;

void dfs( LL p )
{
    dfa[p].v = 1;
    for(LL i=0; i<mat[p].size(); i++ )
    {
        LL x = mat[p][i];
        if( dfa[x].v == 0 )
        {
            dfa[x].l = dfa[p].l;
            dfa[x].pa = p;
            dfs(x);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL i,j,x,y,n,m,p=1,u,v,k,a,b,c=0,s,q;

    cin>>n>>q>>s>>k;
    shit[s]=p; dfa[p].k=k; p++;

    FOR(i,0,n-2)
    {
        cin>>u>>v>>k;
        x=shit[v];
        y=shit[u]=p; dfa[p].k=k; p++;
        mat[x].PB(y); mat[y].PB(x);
        //cout<<x<<' '<<y<<NL;
    }
    dfs(shit[s]);

    FOR(i,0,q-1)
    {
        cin>>a;
        a=a^c;
        if(a==0)
        {
            cin>>v>>u>>k;
            v=v^c; u=u^c; k=k^c;
            //cout<<v<<' '<<u<<' '<<k<<NL;
            x=shit[v];
            y=shit[u]=p; dfa[p].k=k; p++;
            dfa[y].pa=x;
        }
        else
        {
            cin>>v>>k;
            v=v^c; k=k^c;
            v=shit[v];
            //cout<<v<<' '<<k<<NL;
            mx=mn=-1;
            while(v!=0)
            {
               //cout<<v<<' '<<dfa[v].k<<NL;
               a=k^dfa[v].k;
               //cout<<a<<NL;
               if(mx==-1) mx=mn=a;
               else
               {
                   mx=max(mx,a);
                   mn=min(mn,a);
               }
               v=dfa[v].pa;
            }
            cout<<mn<<" "<<mx<<NL;
            c=mx^mn;
        }
    }
    return 0;

}

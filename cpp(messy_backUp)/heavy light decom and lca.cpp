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
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct info
{
    int g,sg,cp,pa,mc,tc,l;  ///g=group, sg=start node of the group, cp=position in seg array, mc=max child, tc=total child in sub tree
    int vis;
}dfa[100010];

vector<int>mat[100010];
int col,pos,ar[100010];

void dfs(int p)
{
    dfa[p].vis=1;
    int a,b,c,x,y,z;
    z=mat[p].size();
    FOR(i,0,z-1)
    {
        x=mat[p][i];
        if(dfa[x].vis==0)
        {
            dfa[x].l=dfa[p].l+1; dfa[x].pa=p;
            dfs(x);
            dfa[p].tc += dfa[x].tc;
            if(dfa[dfa[p].mc].tc < dfa[x].tc) dfa[p].mc=x;
        }
    }
    dfa[p].tc++;
}

void shit(int p,int st)
{
    dfa[p].vis=0;
    dfa[p].g=col; dfa[p].sg=st; dfa[p].cp=pos; ar[pos]=p; pos++;
    cout<<p<<' ';
    if(dfa[p].mc==0) return;
    shit(dfa[p].mc,st);
}

int fin_lca(int a, int b)
{
    int x,y,z;
    x=dfa[a].sg; y=dfa[b].sg;
    if(dfa[a].g==dfa[b].g)
    {
        if(dfa[a].l<dfa[b].l) return a;
        return b;
    }
    if(dfa[x].l>dfa[y].l) return fin_lca(dfa[x].pa,b);
    else return fin_lca(a,dfa[y].pa);
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    outf;
    int i,j,x,y,n,m;
    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>x>>y;
        mat[x].PB(y); mat[y].PB(x);
    }
    dfs(1); pos=col=1;
    FOR(i,1,n)
    {
       if(dfa[i].vis==1)
       {
           shit(i,i);
           col++;
           cout<<NL;
       }
    }
    FOR(i,1,n)
    {
        cin>>x>>y;
        cout<<fin_lca(x,y)<<NL;
    }
    return 0;
}


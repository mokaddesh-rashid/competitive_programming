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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    LL v, pa, low, lev, col;
}dfa[100010];

int stk[100010], top, ins[100010], ti, col, in[100100], v, n, m;
vector<int> mat[100010];

void tarzan( int p )
{
    int i, j, y;
    dfa[p].v = 1;
    dfa[p].low = dfa[p].lev = ++ti;
    ins[p] = 1;
    stk[++top] = p;

    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i], y;
        if( dfa[x].v == 0 )
        {
            tarzan(x);
            dfa[p].low = min( dfa[x].low, dfa[p].low );
        }
        else if(ins[x]==1) dfa[p].low = min( dfa[x].lev, dfa[p].low );

    }

    if( dfa[p].low == dfa[p].lev )
    {
        int c=0;
        while( top > -1 )
        {
            c++;
            y = stk[top];
            ins[y] = 0;
            top--;
            dfa[y].col = col;
            if( y == p ) break;
        }
        if(c>1) in[col]=1;
        col++;
    }
}

vector<int>con[100010], reve[100010];

void up()
{
    int x, y;
    for( int i=1; i<=n; i++ )
    {
        x = dfa[i].col;
        for( int j=0; j<mat[i].size(); j++ )
        {
            y=mat[i][j];
            y=dfa[y].col;
            if(x!=y) con[x].PB(y), cout<<x<<' '<<y<<NL;
            if(x!=y) reve[y].PB(x);
        }
    }
}

int vis[sz], low[sz], lev[sz], bit[sz], pa[sz], tm;
vector<int> ans;
void r_dfs(int p)
{
    vis[p]=1;
    //cout<<p<<" + ";
    FOR(i,0,(int)reve[p].size()-1)
    {
        int x=reve[p][i];
        ///cout<<x<<' ';
        if(vis[x]==0) r_dfs(x);
    }
    //cout<<NL;
}

void dfs(int p)
{
    int i, j, y;
    bit[p]=1;
    low[p]=lev[p]=++ti;

    FOR(i,0,(int)con[p].size()-1)///for(int i=0; i<mat[p].size(); i++ )
    {
        int x=con[p][i], y;
        if(bit[x]==0&&vis[x]==1)///if( dfa[x].v == 0 )
        {
            pa[x]=p;
            dfs(x);
            low[p]=min(low[x],low[p]);
        }
    }
    FOR(i,0,(int)reve[p].size()-1)
    {
        int x=reve[p][i];
        if(x!=pa[p])low[p]=min(lev[x],low[p]);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    ///outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(in,0); mem(dfa,0);
        mem(vis,0); mem(lev,0); mem(low,0);

        int i, j, x, y, c = 0, s, t;

        ti = 0; top = -1;
        cin >> n >> m;
        col=1;

        FOR(i,0,n)mat[i].clear(), con[i].clear(), reve[i].clear();
        FOR(i,0,m-1)
        {
            cin >> x >> y;
            mat[x].push_back( y );
        }
        FOR(i,1,n) if( dfa[i].v == 0 ) tarzan( i );
        cout<<NL;
        up(); col--;

        s=dfa[1].col; t=dfa[n].col;
        r_dfs(t);
        ti=0;
        dfs(s);

        cout<<NL<<s<<' '<<t<<NL;
        FOR(i,1,col) cout<<in[i]<<' '<<lev[i]<<' '<<low[i]<<' '<<vis[i]<<' '<<bit[i]<<NL;
    }

    return 0;

}




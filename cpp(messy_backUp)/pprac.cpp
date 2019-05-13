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
#define MAX 1010
#define sz 1010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    LL v, pa, low, lev, col;
}dfa[sz];

int stk[sz], top, ins[sz], ti, col, in[sz], v, n, m;
vector<int> mat[sz];

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
           // cout << p << ' ' << x  << ' ' << dfa[x].low << ' ' << dfa[p].low << endl;

        }
        else if( ins[x] == 1 ) dfa[p].low = min( dfa[x].lev, dfa[p].low );

    }
    //cout << p << ' ' << dfa[p].low <<  ' ' << dfa[p].lev << endl;
    if( dfa[p].low == dfa[p].lev )
    {
        while( top > -1 )
        {
            y = stk[top];
            ins[y] = 0;
            top--;
            dfa[y].col = col;
            if( y == p ) break;
        }
        col++;
    }
    return;
}

int con[sz][sz], job[sz], vis[sz], nex[sz];
vector<int> mat2[sz];

bool bpm(int p)
{
    FOR(i,1,col)
        if(con[p][i]!=0&&vis[i]==0&&job[i]==0)
        {
                job[i]=p;
                return true;
        }

    FOR(i,1,col)
    {
        if(con[p][i]!=0&&vis[i]==0)
        {
            vis[i]=1;
            if(bpm(job[i]))
            {
                job[i]=p;
                nex[p]=i;
                return true;
            }
        }
    }

    return false;
}

void up()
{
    int x, y;
    for( int i=1; i<=n; i++ )
    {
        x = dfa[i].col;
        for( int j=0; j<mat[i].size(); j++ )
        {
            y = mat[i][j];
            y = dfa[y].col;

            if( x != y )  in[y]++, mat2[x].PB(y);
            //cout<<x<<' '<<y<<NL;
        }
    }
    return;
}

void dfs(int p,int bp)
{
    if(p!=bp) con[bp][p]=1;// cout<<bp<<' '<<p<<NL;
    ///cout<<mat2[p].size()<<NL;

    dfa[p].v = 1;
    for(int i=0; i<mat2[p].size(); i++ )
    {
        int x = mat2[p][i];
        if( dfa[x].v == 0 ) dfs(x,bp);
    }
    return;
}

int main()
{
    ///ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    sf(tc);///cin>>tc;
    FOR(tt,1,tc)
    {
        mem(con,0); mem(job,0); ///mem(nex,0);
        mem(in,0); mem(dfa,0);
        int i, j, x, y, c = 0;

        ti=0; top=-1;
        sff(n,m);///cin>>n>>m;
        col=1;

        for(i=0;i<=n+1;i++) mat[i].clear(), mat2[i].clear();

        for(i=0;i<m;i++)
        {
            sff(x,y);///cin>>x>>y;
            mat[x].push_back( y );
           // mat[y].push_back( x );
        }

        for(i=1;i<=n;i++)
            if(dfa[i].v==0) tarzan(i);
        up();
        //cout<<col<<NL;
        n=col-1;
        FOR(i,1,n)
        {
            mem(dfa,0);
            dfs(i,i);
        }

        int cnt=0;

        FOR(l,1,10)
        FOR(i,1,n)
        {
            mem(vis,0);
            if(bpm(i));
        }

        mem(vis,0); cnt=0;
        FOR(i,1,n)
        {
            //cout<<i<<' '<<job[i]<<NL;
            if(job[i]==0) cnt++;

        }
        pf("Case %d: %d\n",tt,cnt);
    }

    return 0;

}




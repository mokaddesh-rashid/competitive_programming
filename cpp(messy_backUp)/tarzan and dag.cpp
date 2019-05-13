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
}

vector<int>mat2[100010];

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        for(int i=0; i<mat2[p].size(); i++ )
        {
            int x = mat2[p][i];
            if( dfa[x].v == 0 )
            {
                dfs(x);
            }
        }
    }
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

            if( x != y )  in[y]++, mat2[x].pb( y );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;
    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        mem( in, 0 );
        mem( dfa, 0 );

        int i, j, x, y, c = 0;

        ti = 0;
        top = -1;
        cin >> n >> m;
        col = 1;

        for( i=0; i<=n+1; i++ )
            mat[i].clear(), mat2[i].clear();

        for( i=0; i<m; i++ )
        {
            cin >> x >> y;
            mat[x].push_back( y );
           // mat[y].push_back( x );
        }

        for( i=1; i<=n; i++ )
        {
            if( dfa[i].v == 0 ) tarzan( i );
        }

        up();
        mem( dfa, 0 );


        for( int i=1; i<col; i++ )
        {
            if( in[i] == 0 ) dfs(i), c++;
        }
        for( int i=1; i<col; i++ )
        {
            if( dfa[i].v == 0 ) dfs(i), c++;
        }
        cout << "Case " << ca++ << ": " << c << endl;
    }

    return 0;

}




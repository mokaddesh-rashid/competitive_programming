#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define pb push_back
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

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
        dfa[p].v = 1;
        for(int i=0; i<mat2[p].size(); i++ )
        {
            int x = mat2[p][i];
            if( dfa[x].v == 0 )
            {
                v = x;
                dfs(x);
                return;
            }
        }
}

int out[100010];
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

            if( x != y )  out[x]++, in[y]++, mat2[x].pb( y );
        }
    }
}

int cnt[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        mem( cnt, 0 );
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

        x = y = 0;

        for( i=1; i<col; i++ )
        {
            if( in[i] == 0 ) x++;
            if( out[i] == 0 ) y++;
        }

        if( col == 2 ) cout << "Case " << ca++ << ": " << 0 << endl;
        else cout << "Case " << ca++ << ": " << max( x, y ) << endl;

    }

    return 0;

}




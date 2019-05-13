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
#define FF first
#define SS second
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


set<pr>::iterator ii;
set<pr> damn;


struct node
{
    LL v, pa, low, lev, c, f;
}dfa[100010];

int stk[100010], top, ins[100010], ti, ans;
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
            dfa[x].pa = p;
            dfa[x].c = ( dfa[p].c + 1 ) % 2;
            tarzan(x);
            dfa[p].low = min( dfa[x].low, dfa[p].low );
            if( dfa[p].lev < dfa[x].low ) damn.insert( make_pair( p, x ) );

        }
        else if( x != dfa[p].pa )
        {
            if( ins[x] == 1 ) dfa[p].low = min( dfa[x].lev, dfa[p].low );
            if( dfa[x].c == dfa[p].c ) dfa[x].f = 1;

        }

    }

}


int in[20010][11], ck;

void dfs( int p )
{
   // cout << p << " = ";
    ans++;
    dfa[p].v = 1;
    for( int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
       // cout << x << ' ';
        if( dfa[x].v == 0 )
        {
            dfa[x].c = ( dfa[p].c + 1 ) % 2;
            dfs( x );
        }

        if( dfa[x].c == dfa[p].c ) ck = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int tt, ca = 1;

    cin >> tt;

    while( tt-- )
    {
        while( !damn.empty() )
        {
            damn.erase( damn.begin() );
        }
        mem( dfa, 0 );
        int i, j, x, y, n, m, a, b;

        ti = 0;
        top = -1;
        cin >> n >> m;

        for( i=0; i<=n+1; i++ ) mat[i].clear();

        for( i=0; i<m; i++ )
        {
            cin >> x >> y;
            x++; y++;
            in[i][0] = x; in[i][1] = y;
            mat[x].push_back( y );
            mat[y].push_back( x );
        }

        ans = 0;
        for( i=1; i<=n; i++ )
        {
            if( dfa[i].v == 0 ) tarzan( i );
        }

        //cout << endl << endl;
        for( i=0; i<=n; i++ ) mat[i].clear();

        for( i=0; i<m; i++ )
        {
            pr lel, lol;

            ii = damn.begin();
            lel = *ii;

            //cout << lel.FF << ' ' << lel.SS << endl;
            x = in[i][0]; y = in[i][1];
            //cout << x << ' ' << y << endl;

            lol = make_pair( x, y );
            ii = damn.find( lol );
            lel = *ii; a = lel.FF; b = lel.SS;
            if( a == x && y == b ) continue;
             //cout << a << ' ' << b << endl;

            lol = make_pair( y, x );
            ii = damn.find( lol );
            lel = *ii; a = lel.FF; b = lel.SS;
            if( a == y && x == b ) continue;
            //cout << a <<  ' ' << b << endl;

            mat[x].push_back( y );
            mat[y].push_back( x );

            //cout << x << ' ' << y << endl;
        }

        mem( dfa, 0 );
        x = 0;
        for( i=1; i<=n; i++ )
        {
            if( dfa[i].v == 0 )
            {
                ans = ck = 0;
                dfs( i );
                if( ck == 1 ) x += ans;
               // cout << endl;
            }
        }

        cout << "Case " << ca++ << ": " << x << endl;
    }

    return 0;

}

/*
4

4 4
1 2
1 3
1 0
3 2
*/



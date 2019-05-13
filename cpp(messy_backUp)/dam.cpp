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
#define PB push_back
#define F first
#define S second
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
    LL v, pa, l, c, lev;
}dfa[200010];

vector<int> mat[200010];
int in[200010];
LL ty, ans;

void dfs( int p )
{
    ans = max( ans, dfa[p].lev );
    dfa[p].l = ty;
    dfa[p].v = 1;
    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];
        if( dfa[x].v == 0 && dfa[x].c == dfa[p].c )
            in[p]++, in[x]++, dfa[x].lev = dfa[p].lev+1, dfs(x);
    }
}

int stk[200010], top;


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    set<pr> ms;
    set<pr>::iterator it;

    pr dm[200011];
    int i, j, x, y, n, m;

    cin >> n;

    for( i=1; i<=n; i++ ) cin >> dfa[i].c;

    for( i=0; i<n-1; i++ )
    {
        cin >> x >> y;

        mat[x].PB( y );
        mat[y].PB( x );
    }


    int p = 0;
    ty = 0;
    for( i=1; i<=n; i++ )
    {
        if( dfa[i].v == 0 ) ty++, dfs( i );
    }

    for( i=1; i<=n; i++ )
    {
        for( j=0; j<mat[i].size(); i++ )
        {
            x = mat[i][j];

            if( dfa[x].l  != dfa[i].l )
            {
                dm[p].F = dfa[x].l;
                dm[p].S = dfa[x].c;
                p++;
                dm[p].F = dfa[i].l;
                dm[p].S = dfa[i].c;
                p++;
            }
        }
    }

    for( i=1; i<=n; i++ ) mat[i].clear();
    mem( dfa, 0 );

    pr fin, vhk;

    for( i=0; i<p; i += 2 )
    {
        x = dm[i].F; y = dm[i+1].F;

        fin.F = x; fin.S = y;
        it = ms.find( fin );
        vhk = *it;

        if( vhk.F == fin.F && vhk.S == fin.S ) continue;
        ms.insert( make_pair( x, y ) );
        ms.insert( make_pair( y, x ) );

        mat[x].PB( y );
        mat[y].PB( x );

        dfa[x].c = dm[i].S;
        dfa[y].c = dm[i+1].S;
        //cout << x << ' ' << y << ' ' << dfa[x].c << ' ' << dfa[y].c << endl;
    }

     for( i=1; i<=ty; i++ ) cout << dfa[i].c << ' ';

     cout << endl;
    mem( in, 0 );

    mem( dfa, 0 );
    dfs( 1 );


    for( i=1; i<=ty; i++ )
    {
        if( in[i] == 1 ) stk[top++] = i;
    }

    int dude = 0;
    cout << top << endl;

    while( dude < top )
    {
        cout << p << endl;
        p = stk[dude]; dude++;
        for( i=0; i<mat[p].size(); i++ )
        {
            x = mat[p][i];
            in[x]--;
            if( in[i] == 1 ) stk[top++] = i;
        }
    }

    mem( dfa, 0 );
    ans = 0;
    dfs( p );

    return 0;

}
/*
15
0 1 0 0 1 1 0 1 1 1 1 1 0 1 0
10 7
10 3
10 8
5 7
13 14
8 13
15 4
15 13
5 2
9 3
11 15
13 6
1 12
9 1
*/



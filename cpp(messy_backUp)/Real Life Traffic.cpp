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
    LL v, pa, st, en, l, c, u;
}dfa[100010];

vector<int> mat[100010];
int ti, cnt, pp, lf;

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        dfa[p].st = ti, ti++;
        dfa[p].l = dfa[p].st;
        //cout << p << ' ';
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                if( p == 0 ) pp++;
                dfa[x].pa = p;
                dfs(x);
                dfa[p].l = min( dfa[p].l, dfa[x].l );
            }
            else if( dfa[p].pa != x )
                dfa[p].l = min( dfa[p].l, dfa[x].st );
        }
        int a = 0, b = 0;
        for( int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            a = 0;
            if( pp == 1 && p == 0 ) a = 0;
            else if( dfa[x].u != 0 ) a = 1, b++;

            if( dfa[x].l > dfa[p].st && dfa[x].pa == p && a == 0 ) cnt++, b++;
        }

        if( b != 0 ) dfa[p].u = 1;

    }
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        memset( dfa, 0, sizeof( dfa ) );
        ti = 1;
        lf = pp = cnt = 0;

        int i, j, x, y, n, m;

        cin >> n >> m;
        for( i=0; i<=n+1; i++ )
            mat[i].clear( );

        for( i=0; i<m; i++ )
        {
            cin >> x >> y;

            mat[x].push_back( y );
            mat[y].push_back( x );
        }

        dfs(0);
        if( cnt%2 ) cnt++;
        cnt /= 2;
        cout << "Case " << ca++ << ": " << cnt << endl;
    }

    return 0;

}




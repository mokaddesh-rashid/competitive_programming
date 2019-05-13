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
#define mx          (long long) 1000000000000000000
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

int stk[100010], top, ins[100010], ti, col, in[100100], v, n, m, sst[100010], maxx, mv, too;
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
        int c = 0, d = 1000010;
        while( top > -1 )
        {
            y = stk[top];
            c++; d = min( d, y );
            ins[y] = 0;
            top--;
            dfa[y].col = col;
            if( y == p ) break;
        }
        col++;
        if( maxx < c )
        {
            maxx = c;
            mv = d;
        }
        if( maxx == c && mv > d )
        {
            maxx = c;
            mv = d;
        }
    }

    sst[++too] = p;
}

int dp[100010];

int dfs( int p , int pa )
{
    //cout << p << endl;
    ///if( pa == 1 ) cout << p << ' ' << dp[1] << endl;
    if( dp[p] != 0 ) return 1+dp[p];
    dfa[p].v = 1;

    for(int i=0; i<mat[p].size(); i++ )
    {
        int x = mat[p][i];

        if( dfa[x].v == 0 )
        {
            ///if( pa == 1 ) cout << x << ' ' << dfa[x].v << endl;
            dp[p] = 1+dfs( x , pa );
        }
    }

    dfa[p].v = 0;
    ///if( pa == 1 ) cout << p << ' ' << dp[1] << endl;
    return 1+dp[p];

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
        mem( dfa, 0 );
        mem( in, 0 );

        int i, j, x, y, c = 0;

        maxx = ti = 0;
        top = -1;
        too = -1;
        cin >> n;
        m = n;

        for( i=0; i<=n+1; i++ )
            mat[i].clear();

        for( i=0; i<m; i++ )
        {
            cin >> x >> y;
            mat[x].push_back( y );
            in[y]++;
           // mat[y].push_back( x );
        }

        for( i=1; i<=n; i++ )
        {
            if( dfa[i].v == 0 ) tarzan( i );
        }

        //cout << maxx << ' ' << mv << endl;
        mem( dfa, 0 );
        mem( dp, 0 );

        for( i=1; i<=n; i++ )
        {
           int len = dfs( i , i );
            ///cout << i << ' ' << len  << ' ' << maxx << endl;
            if( len > maxx )
            {
                maxx = len;
                mv = i;
            }
            if( len == maxx && i < mv )
            {
                maxx = len;
                mv = i;
            }
        }

        cout << "Case " << ca++ << ": " << mv << endl;
    }

    return 0;

}
/*

1
5
1 2
2 1
5 3
3 4
4 5

3
3
1 2
2 3
3 1

4
1 2
2 1
4 3
3 2

5
1 2
2 1
5 3
3 4
4 5
*/




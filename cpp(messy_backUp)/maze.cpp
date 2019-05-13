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
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};

int n, m, k, cnt, vis[510][510], t;
string str[501];

int chk( int x, int y )
{
    if( x < 0 || y < 0 || x >= n || y >= m ) return 1;
    else if( str[x][y] == '#' || str[x][y] == 'X' ) return 1;

    return 0;
}

void dfs( int x, int y )
{
    if( vis[x][y] == 0 )
    {
        vis[x][y] = t, t++;
        int a, b, c;
        a = b = 0;
        for( int i=0; i<4; i++ )
        {
            a = chk( x+fx[i], y+fy[i] );

            if( a == 0 )
            {
                dfs( x+fx[i], y+fy[i] );
            }
        }
        for( int i=0; i<4; i++ )
        {


            a = chk( x+fx[i], y+fy[i] );
           // cout << x << ' ' << y << ' ' << vis[x][y] << ' ' << vis[x+fx[i]][y+fy[i]]
            if( a == 0 && vis[x+fx[i]][y+fy[i]] > vis[x][y] ) b = 1;

        }
        if( b == 0 && cnt < k ) str[x][y] = 'X', cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y;

    cin >> n >> m >> k;

    for( i=0; i<n; i++ )
        cin >> str[i];
    t = 1;
    for( i=0; i<n; i++ )
    {
        for( j=0; j<m; j++ )
        {
            if( str[i][j] == '.' ) dfs( i, j ), x = 1;

            if( x == 1 ) break;
        }
        if( x == 1 ) break;
    }

    for( i=0; i<n; i++ )
        cout << str[i] << endl;

    return 0;

}



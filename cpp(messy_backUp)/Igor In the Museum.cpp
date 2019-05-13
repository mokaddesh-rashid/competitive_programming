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
#define FF first
#define SS second
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
*/

//4 moves
int fx[11]={+1,-1,+0,+0};
int fy[11]={+0,+0,+1,-1};
int vis[1001][10001], col[100010], c, n , m, tok[1001][1001], ty[1001][1001];
string str[10001];
vector<pr> mv;

void dfs( int x, int y )
{
   // if( str[x][y] == '*' ) cout << x << ' ' << y << ' ' << c << ' ' << tok[x][y] << endl;

    if( x < 0 || y < 0 || x >= n || y >= m )return;

    if( str[x][y] == '*' )
    {
        //if( tok[x][y] != c )
        col[c]++;
        tok[x][y] = c;
        //cout << x << ' ' << y << ' ' << tok[x][y] << endl;

        return;
    }

    vis[x][y] = c;
    ty[x][y] = c;

    for( int i=0; i<4; i++ )
    {
        int a, b;
        a = x+fx[i]; b = y+fy[i];
        if( vis[a][b] == 0 ) dfs( a, b );
    }

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    mem( tok, 0 );
    int i, j, x, y, q, a, b;

    cin >> n >> m >> q;

    for( i=0; i<n; i++ )
        cin >> str[i];

    for( i=0; i<n; i++ )
        {
            for( j=0; j<m; j++ )
            {
                if( str[i][j] == '.' && vis[i][j] == 0 )
                {
                    c++;
                    dfs( i, j );
                }
            }
        }

    for( i=0; i<q; i++ )
    {
        cin >> a >> b;
        a--; b--;
        x = ty[a][b];
        cout << col[x] << endl;

    }

    return 0;

}



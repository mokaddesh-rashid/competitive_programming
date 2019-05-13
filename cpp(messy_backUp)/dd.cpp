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
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/

int fx[100]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[100]={-1,+1,+0,+0,+1,+1,-1,-1};
//set<int>::iterator ii;


string str[1000];
int n, m;
int vis[100][100];

int chk( int x, int y )
{
    if( x < 0 || y < 0 || x >= n || y >= m ) return 0;
    //if( str[x][y] == 'F' ) cout << x << ' ' << y << ' ' << str[x][y] << endl;
    vis[x][y]++;
    if( str[x][y] == 'F' ) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t;

    cin >> t;

    while( t-- )
    {
        memset( vis, 0, sizeof( vis ) );
        int i, j, x = 0, y, a = 0, b, c;

        cin >> n >> m ;

        for( i=0; i<n; i++ )
            cin >> str[i];

        for( i=0; i<n; i++ )
        {
            for( j=0; j<m; j++ )
            {
                if( str[i][j] != 'F' )
                {
                    vis[i][j]++;
                    x = str[i][j]-'0';
                    y = 0;
                    for( int k=0; k<8; k++ )
                    {
                        b = chk( i+fx[k], j+fy[k] );
                        y += b;
                    }

                    if( x != y ) a = 1;
                }
            }
        }

        for( i=0; i<n; i++ )
            for( j=0; j<m; j++ )
                if( vis[i][j] == 0 ) a = 1;

        if( a == 0 ) cout << "Well done Clark!\n";
        else cout << "Please sweep the mine again!\n";
    }


    return 0;

}



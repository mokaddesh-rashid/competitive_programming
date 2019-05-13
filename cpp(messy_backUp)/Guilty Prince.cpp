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


//set<int>::iterator ii;

int dis[30][30], n, m, cnt ;

string str[30];


int rec( int x, int y )
{
    if( x < 0 || y < 0 || x >= m || y >= n ) return 0;
    if( dis[x][y] == 0 ) return 0;
    else
    {
        dis[x][y] = 0;
        return 1+rec( x-1, y) + rec(x+1, y) + rec(x,y-1) + rec( x, y+1 );
    }
}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t , ca = 1;

    cin >> t;

    while(t--)
    {
        memset( dis, 0, sizeof(dis) );
        cnt = 0;

        int i, j, x, y , c;

        cin >> n >> m ;

        for( i=0; i<m; i++ )
            cin >> str[i];

        for( i=0; i<m; i++ )
            for( j=0; j<n; j++ )
        {
            if( str[i][j] == '.' ) dis[i][j] = 1;
            if( str[i][j] == '@' ) x = i, y = j, dis[i][j] = 1;

        }

        c = rec( x, y );
        cout << "Case " << ca++ << ": " << c << endl;
    }
    return 0;

}



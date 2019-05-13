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
#define maxx          (long long) 1000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

vector<int> mat[100010];
LL  path[1001][1001], n, m, dir[10][2], po, cnt[100010], p1, p2, p3, ho;
string str[21];

void mess()
{
    int k = 1;
    for(int i=0; i<n; i++ )
        for(int j=0; j<m; j++ , k++ )
             path[i][j] = k;
}

void get_dir()
{
    dir[0][0] = -1;
    dir[1][1] = -1;
    dir[2][1] = 1;
    dir[3][0] = 1;

}
int chk( int x, int y )
{
    if( x < 0 || y < 0 || x >= n || y >= m ) return 0;
    if( str[x][y] == '#' || str[x][y] == 'm' ) return 0;

    return 1;
}
void asin( int x, int y )
{
    LL a, b, c, p, q, k;

    if( str[x][y] == 'a' ) p1 = path[x][y];
    if( str[x][y] == 'b' ) p2 = path[x][y];
    if( str[x][y] == 'c' ) p3 = path[x][y];
    if( str[x][y] == 'h' ) ho = path[x][y];

    c = chk(x,y);

    if( c == 0 ) return;

    for(int i=0; i<4; i++ )
    {
        a = x+dir[i][0], b = y+dir[i][1];
        c = chk( a, b );
        if( c == 1 )
        {
            k =  path[x][y];
            p = path[a][b];
            // << k << ' ' << p << endl;
            mat[p].push_back( k );
            mat[k].push_back( p );
        }
    }

    return;
}


struct node
{
    LL v, pa, l;
}bfa[100010];

int que[100010], h, r;

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = 1;
    r++;
    while( h != r )
    {
        //cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
        {

            int x = mat[p][i];
            if( bfa[x].v == 0 )
            {
                //cout << x << ' ';
                bfa[x].l = bfa[p].l+1;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
        }
        //cout << endl;
        h++;
        p = que[h];
    }

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        memset( bfa, 0, sizeof(bfa) );

        LL i, j, x = 0, y, a, b, c, k, z ;

        cin >> n >> m;

        mess();
        get_dir();

        for( i=0; i<n; i++ )
            cin >> str[i];

        for( i=0; i<401; i++ )
            mat[i].clear();

        for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
            asin( i, j );

        n = n*m;

        bfs( ho );
        //cout << ho << ' ' << p1 << ' ' << p2 << ' ' << p3 << endl;
        //cout << bfa[p1].l << ' ' << bfa[p2].l << ' ' << bfa[p3].l << endl;
        x = max( x, bfa[p1].l );
        x = max( x, bfa[p2].l );
        x = max( x, bfa[p3].l );

        cout << "Case " << ca++ << ": " << x << endl;

    }
    return 0;

}




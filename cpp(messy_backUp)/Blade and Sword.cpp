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

vector<int> mat[40010];
int  path[202][202], n, m, dir[10][2], po, p1, d1, cnt, ar[40010], star[40010];
string str[201];

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
    if( str[x][y] == '#' ) return 0;
    return 1;
}
void asin( int x, int y )
{
    LL a, b, c, p, q, k;

    if( str[x][y] == 'P' ) p1 = path[x][y];
    if( str[x][y] == 'D' ) d1 = path[x][y];
    if( str[x][y] == '*' ) a = path[x][y], ar[cnt] = a, cnt++, star[a] = 3;


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
    int v, pa, l;
}bfa[40010];

int que[40010], h, r;

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 0;
    bfa[p].pa = 0;
    bfa[p].v = 1;
    que[r] = 1;
    r++;
    while( h != r )
    {
        int x;
        //cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
            {
                x = mat[p][i];
                if( star[p] != 0 && star[x] !=  0 && bfa[p].l == bfa[x].l ) star[x] = 2, star[p] = 2;
            }
        for(int i=0; i<mat[p].size(); i++ )
        {

            int x = mat[p][i], co = 1, y = 0;
            if( star[p] != 0 && star[x] == 0 && star[bfa[p].pa] == 0 ) co = star[p];
            if( bfa[x].v == 0 || bfa[x].l > bfa[p].l+co )
            {
                //cout << x << '(' << co << ')' << ' ' ;
                bfa[x].l = bfa[p].l+co;
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
        memset( star, 0, sizeof(star) );
        int i, j, x = 0, y, a, b, c, k, z ;
        cnt = 0;
        cin >> n >> m;

        mess();
        get_dir();

        for( i=0; i<n; i++ )
            cin >> str[i];

        for( i=0; i<40002; i++ )
            mat[i].clear();

        for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
            asin( i, j );

        for( i=0; i<cnt; i++ )
        for( j=0; j<cnt; j++ )
        {
            x = ar[i], y = ar[j];
            if( x == y ) continue;
            mat[x].push_back( y );
            mat[y].push_back( x );

        }

        if( cnt == 1 ) mat[ar[0]].clear();
        n = n*m;

        bfs( p1 );
        bfs( p1 );
        //cout << cnt << ' ' << p1 << ' ' << p2 << ' ' << p3 << endl;
        //cout << bfa[p1].l << ' ' << bfa[p2].l << ' ' << bfa[p3].l << endl;
        if( bfa[d1].l == 0 && p1 != d1 ) cout << "Case " << ca++ << ": impossible" << endl;
        else cout << "Case " << ca++ << ": " << bfa[d1].l << endl;

    }
    return 0;

}





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
string str[501];

void mess()
{
    int k = 1;
    for(int i=0; i<n; i++ )
        for(int j=0; j<m; j++ , k++ )
             path[i][j] = k;
    ho = k;
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
    if( str[x][y] == '*' ) return 0;

    return 1;
}
void asin( int x, int y )
{
    LL a, b, c, p, q, k;

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
    LL v, pa, l, c;
}bfa[100010];

int que[100010], h, r, col;

void bfs( int p )
{

    h = r = 0;
    bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    bfa[p].c = col;
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
                bfa[x].c = bfa[p].c;
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
        memset( bfa, 0, sizeof(bfa) );

        LL i, j, x = 0, y, a, b, c, k, z ;

        cin >> n >> m >> k;

        mess();
        get_dir();

        for( i=0; i<n; i++ )
            cin >> str[i];

        for( i=0; i<401; i++ )
            mat[i].clear();

        for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
            asin( i, j );

        for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
        {
            if( str[i][j] == '.' && ( i == 0 || j == 0 || i == n-1 || j == m-1 ) )
                col = 0, bfs( path[i][j] );
        }

        for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
        {
            x = path[i][j];

            if( str[i][j] != '*' &&  bfa[x].v == 0 )
                col++, bfs( path[i][j] );
        }

        for( i=1; i<ho; i++ )
        {
            x = bfa[i].c;
            if( x != 0 ) cnt[x]++;
        }

        p_i pr[100010];

        pr[0].first = 0, pr[0].second = 0;

        j = 0;
        for( i=1; i<=col; i++, j++ )
        {
            if( cnt[i] > 0 )
            {
               pr[i].first = cnt[i];
               pr[i].second = i;
               //cout << i << ' ' << cnt[i] << endl;
            }
        }

        sort( pr, pr+col+1 );


//         for( i=0; i<=col; i++ )
//            cout << pr[i].first << ' ' << pr[i].second << endl;
        int v = 0;

        for( i=0; i<n; i++ )
        {
            for( j=0; j<m; j++ )
            {
                x = path[i][j];
                if( bfa[x].c != 0 )
                {
                    a = 0;
                    for( int l=1; l<=col-k; l++ )
                    {
                        //cout << pr[l].second << endl;
                        if( pr[l].second == bfa[x].c ) a = 1;
                    }
                   // cout << x << ' ' << bfa[x].c << ' ' << a << endl;
                    if( a == 1 ) str[i][j] = '*', v++;
                    //else  cout << str[i][j];
                }
                //else cout << str[i][j];

            }
        }

        cout << v << endl;

        for( i=0; i<n; i++ )
            cout << str[i] << endl;





    return 0;

}




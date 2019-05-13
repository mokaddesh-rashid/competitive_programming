#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<int,int> p_i;


//set<int>::iterator ii
vector<int> mat[40010];
int  path[201][201], n, dir[10][2], po, cnt[40010], p, q, pp, qq , dis[40010], m, fir[40010], ck;
string str[222];

void mess()
{
    int k = 0;
    for(int i=0; i<n; i++ )
        for(int j=0; j<m; j++ , k++ )
             {
                 dis[k] = maxx;
                 path[i][j] = k;
                 if( i == 0 || j == m-1 || i == n-1 || j == 0 ) cnt[k]++;
             }
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
    int a, b, c, p, q, k;

    if( str[x][y] == 'J' ) pp = path[x][y];
    if( str[x][y] == 'F' ) fir[path[x][y]] = 1;

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
            //cout << k << ' ' << p << endl;
            mat[p].push_back(p);
            mat[k].push_back(p);
        }
    }

    return;
}


struct node
{
    int v, pa, l;
}bfa[100010];

int que[100010], h, r;

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 1;
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
            if( bfa[x].l == 0 || bfa[p].l+1 < bfa[x].l )
            {
                bfa[x].l = bfa[p].l+1;
                if( fir[x] == 1 && ck == 0 ) bfa[x].l = 1;
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

    inf;
    //outf;
    get_dir();

    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        memset( fir, 0 ,sizeof(fir) );
        memset( cnt, 0, sizeof(cnt) );
        int i, j, x, y, a, b, c, k, z;

        cin >> n >> m;

        mess();

        for( i=0; i<n; i++ )
            cin >> str[i];

        for( i=0; i<n*m+1; i++ )
            mat[i].clear();

        for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
            asin( i, j );

        b = m;
        a = n;
        n = n*m;
        int u = 0;
        ck = 0;
        memset( bfa, 0, sizeof(bfa) );
        for( i=0; i<a; i++ )
        for( j=0; j<b; j++ )
        {
            if( str[i][j] == 'F' && u == 0 )
            {
                qq = path[i][j];
                bfs(qq);
                for(int l=0; l<n; l++ )
                    if( bfa[l].l != 0 ) dis[l] = min( dis[l], bfa[l].l );
                u = 1;
            }
        }

        ck = 1;
        memset( bfa, 0, sizeof(bfa) );
        bfs(pp);

        c = maxx;

        for( i=0; i<n; i++ )
        {
            //cout << cnt[i] << ' ' << i << ' ' << bfa[i].l << ' ' << dis[i] << endl;
            if( bfa[i].l < dis[i] && cnt[i] != 0 && bfa[i].l != 0 ) c = min( c, bfa[i].l );
        }
        //cout << c+1 << endl;
        cout << "Case " << ca++ << ": ";
        if( c >= maxx ) cout << "IMPOSSIBLE\n";
        else cout << c << endl;

    }
    return 0;

}



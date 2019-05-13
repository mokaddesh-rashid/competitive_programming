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

int path[30][30][30], p, d, vld[100030];
vector<int> mat[100000];

void mess()
{
    int k = 1, i, j, l;

    for( i=0; i<26; i++ )
        for( j=0; j<26; j++ )
            for( l=0; l<26; l++, k++ )
                path[i][j][l] = k;
}

int ck( int x )
{
    if( x == -1 ) return 25;
    else if( x == 26 ) return 0;
    return x;
}

void ed( int x, int a, int b, int c )
{
    a = ck(a), b = ck(b), c = ck(c);
    int y = path[a][b][c];
    mat[x].push_back( y );
}

void conn()
{
    int i, j, l;
    for( i=0; i<26; i++ )
        for( j=0; j<26; j++ )
            for( l=0; l<26; l++ )
                {
                    ed( path[i][j][l], i+1, j, l );
                    ed( path[i][j][l], i-1, j, l );
                    ed( path[i][j][l], i, j+1, l );
                    ed( path[i][j][l], i, j-1, l );
                    ed( path[i][j][l], i, j, l+1 );
                    ed( path[i][j][l], i, j, l-1 );
                }
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
            if( bfa[x].v == 0 && vld[x] == 0 )
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
    mess();
    conn();


    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        memset( bfa, 0, sizeof( bfa ) );
        memset( vld, 0, sizeof( vld ) );
        int i, j, x, y, z, n, m, a, b, c, d, l;
        string st, en, f, s, t;

        cin >> st >> en ;

        cin >> n;

        while( n-- )
        {
            cin >> f >> s >> t;

            a = f.size(), b = s.size(), c = t.size();

            for( i=0; i<a; i++ )
                for( j=0; j<b; j++ )
                    for( l=0; l<c; l++ )
            {
                x = f[i]-'a', y = s[j]-'a', z = t[l]-'a';
                x = path[x][y][z];
                vld[x] = 1;
            }
        }

        a = st[0]-'a', b = st[1]-'a', c = st[2]-'a';
        x = path[a][b][c];
        if( vld[x] == 0 ) bfs( x );
        //cout << x << endl;

        a = en[0]-'a', b = en[1]-'a', c = en[2]-'a';
        y = path[a][b][c];

        if( st == en && vld[x] == 0 ) cout << "Case " << ca++ << ": " << 0 << endl;
        else if( bfa[y].l == 0 || vld[x] == 1 || vld[y] == 1 ) cout << "Case " << ca++ << ": " << -1 << endl;
        else cout << "Case " << ca++ << ": " << bfa[y].l << endl;
    }


    return 0;

}

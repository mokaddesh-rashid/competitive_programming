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
#define PB  push_back
typedef pair<int,int> pr;


//set<int>::iterator ii;

struct nude
{
    int x, y, z;
};

class compare
{
public:
    bool operator()( nude f, nude s )
    {
        if( f.x == s.x && f.y == s.y ) return f.z < s.z;
        else if( f.x == s.x ) return f.y < s.y;
        return f.x < s.x;
    }
};


set<nude,compare> ms;
set<nude>::iterator ii;

struct node
{
    LL v, pa, l, vv;
}bfa[100010];

vector<int> mat[100010];
int que[100010], h, r, con[3001][3001];

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 0;
    bfa[p].pa = -1;
    que[r] = 1;
    r++;
    while( h != r )
    {

        int n = mat[p].size();
        for(int i=0; i<n; i++ )
        {
            int x = mat[p][i], a = 1, b, c, y, z;

            b = c = 0;

            nude damn, chk;
            damn.x = bfa[p].pa; damn.y = p; damn.z = x;
            ii = ms.find( damn );
            damn = *ii;

            if( damn.x == bfa[p].pa && damn.y == p && damn.z == x ) a = 0;
            if( bfa[x].l > bfa[p].l+1 && a == 1  )
            {
                bfa[x].l = bfa[p].l+1;
                bfa[x].pa = p;
                que[r] = x;
                r++;
            }

            if( a == 0 )
            {
                for( int j=0; j<n; j++ )
                {
                    y = mat[p][j];
                    if( con[y][p] == 1 && con[y][x] == x )
                    {
                        chk.x = p; chk.y = y; chk.z = x;
                        ii = ms.find( chk );
                        if( chk.x == p && chk.y == y && chk.z == x ) a = 1;
                        if( bfa[x].l > bfa[p].l+1 && a == 1  )
                        {
                            bfa[x].l = bfa[p].l+2;
                            bfa[x].v = y;
                            bfa[x].pa = p;
                            que[r] = x;
                            r++;
                            break;
                        }
                    }
                }
            }

            if( a == 0 )
            {
                for( int j=0; j<n; j++ )
                {
                    int lol = 1;
                    y = mat[p][j];
                    damn.x = bfa[p].pa; damn.y = p; damn.z = y;
                    ii = ms.find( damn );
                    damn = *ii;

                    if( damn.x == bfa[p].pa && damn.y == p && damn.z == y ) lol = 0;

                    if( lol == 1 )
                    {
                        chk.x = y; chk.y = p; chk.z = x;
                        ii = ms.find( chk );
                        if( chk.x == y && chk.y == p && chk.z == x ) a = 1;
                        if( bfa[x].l > bfa[p].l+1 && a == 1  )
                        {
                            bfa[x].l = bfa[p].l+3;
                            bfa[x].v = p;
                            bfa[x].vv = y;
                            bfa[x].pa = p;
                            que[r] = x;
                            r++;
                            break;
                        }
                    }
                }
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

    for( int i=0; i<10001; i++ ) bfa[i].l = 100000;
    int i, j, x, y, n, m, k;

    cin >> n >> m >> k;

    for( i=0; i<m; i++ )
    {
        cin >> x >> y;
        con[x][y]++; con[y][x]++;
        mat[x].push_back( y );
        mat[y].push_back( x );
    }

    nude damn;

    for( i=0; i<k; i++ )
    {
        cin >> damn.x >> damn.y >> damn.z;
        ms.insert( damn );
    }

    h = 0;
    r = 0;
    bfs(1);

    if( bfa[n].l == 100000 )
    {
        cout << -1;
        return 0;
    }

    cout << bfa[n].l << endl;

    vector<int> prn;

    while( n > 0 )
    {
        //cout << n << ' ';
        prn.PB( n );
        if( bfa[n].v != 0 ) prn.PB( bfa[n].v );//cout << bfa[n].v << ' ';
        if( bfa[n].vv != 0 ) prn.PB( bfa[n].vv );//cout << bfa[n].vv << ' ';
        n = bfa[n].pa;
    }

    for( i=prn.size(); i>0; i-- )
    {
        cout << prn[i-1] << ' ';
    }

    return 0;

}




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

struct node
{
    LL v, pa, l, wa;
}bfa[110];

vector<int> mat[100010], cost[110], type[110];
int que[100010], h, r;

void bfs( int p )
{
    h = r = 0;
    bfa[p].wa = bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = 1;
    r++;
    while( h != r )
    {
        //cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i], y = cost[p][i], z = type[p][i], a = 0, b = 0;
            if( z == 1 ) a = y;

            if( bfa[x].wa > bfa[p].wa+a ) b = 1;
            else if( bfa[x].wa == bfa[p].wa+a && bfa[x].l > bfa[p].l+y ) b = 1;
            else if( bfa[x].v == 0 ) b = 1;

            if( b == 1 )
            {
                bfa[x].l = bfa[p].l+y;
                bfa[x].wa = bfa[p].wa+a;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
              //  cout << x << '<' << bfa[x].l << ' ' << bfa[x].wa << "> ";
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
    int t;

    cin >> t;

    while( t-- )
    {
        memset( bfa, 0, sizeof( bfa ) );
        int i, j, x, y, n, m, z, ty;

        cin >> n >> m;

        for( i=0; i<n+3; i++ )
            mat[i].clear(), cost[i].clear(), type[i].clear();

        for( i=0; i<m; i++ )
        {
            cin >> x >> y >> z >> ty;

            mat[x].push_back( y ), mat[y].push_back( x );
            cost[x].push_back( z ), cost[y].push_back( z );
            type[x].push_back( ty ), type[y].push_back( ty );
        }

        cin >> x >> y;
        bfs( x );

        if( bfa[y].v == 0 ) cout << -1 << endl;
        else cout << bfa[y].wa << ' ' << bfa[y].l << endl;


    }



    return 0;

}





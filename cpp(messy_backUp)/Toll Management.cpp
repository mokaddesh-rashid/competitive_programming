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
#define pb push_back
typedef pair<LL,LL> pr;


struct node
{
    LL v, l, m, pa, p, c;
}dij[100010];

class compare
{
    public:
        bool operator()( node f, node s )
        {
            return f.v < s.v;
        }

};
priority_queue< node, vector<node>, compare > mq;
vector<LL> mat[100010], cost[100010];
node exo;
LL lim;

void dijkstra( LL p )
{
    dij[p].v = 0; dij[p].l = 0; dij[p].pa = -1;
    exo.p = p;
    exo.v = dij[p].v;
    mq.push( exo );

    while( !mq.empty() )
    {
        p = mq.top().p;
        mq.pop();

        for( LL i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i];
            //cout << p << ' ' << x << ' ' << lim << endl;
            if( dij[p].v + cost[p][i] <= lim && dij[x].c < max( dij[p].c, cost[p][i] ) )
            {
                dij[x].v = dij[p].v + cost[p][i];
                dij[x].c = max( dij[p].c, cost[p][i] );
                dij[x].pa = p;
                exo.p = x; exo.v = dij[x].v;
                mq.push( exo );
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

   int t, ca = 1;

   cin >> t;

   while( t-- )
   {
        mem( dij, 0 );
        LL i, j, x, y, z, n, m, a, b;

        cin >> n >> m >> a >> b >> lim;

        for( i=0; i<=n; i++ )
            mat[i].clear(), cost[i].clear(), dij[i].v = maxx;

        for( i=0; i<m; i++ )
        {
            cin >> x >> y >> z;
            mat[x].pb( y ); cost[x].pb( z );
            //mat[y].pb( x ); cost[y].pb( z );
        }

        dijkstra( a );
        dijkstra( b );

        cout << "Case " << ca++ << ": ";
        if( dij[b].v == maxx ) cout << -1 << endl;
        else cout << dij[b].c << endl;
   }


    return 0;

}



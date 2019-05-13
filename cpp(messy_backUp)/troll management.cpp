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
    LL v, l, m, pa, p;
}dij[100010], dij2[100010];

class compare
{
    public:
        bool operator()( node f, node s )
        {
            return f.v > s.v;
        }

};
priority_queue< node, vector<node>, compare > mq;
vector<LL> mat[100010], cost[100010];
vector<LL> mat2[100010], cost2[100010];
node exo;

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
            if( dij[x].v > dij[p].v + cost[p][i] )
            {
                dij[x].v = dij[p].v + cost[p][i];
                dij[x].pa = p;
                exo.p = x; exo.v = dij[x].v;
                mq.push( exo );
            }
        }
    }
}

void dijkstra2( LL p )
{
    dij2[p].v = 0; dij2[p].l = 0; dij2[p].pa = -1;
    exo.p = p;
    exo.v = dij2[p].v;
    mq.push( exo );

    while( !mq.empty() )
    {
        p = mq.top().p;
        mq.pop();

        for( LL i=0; i<mat2[p].size(); i++ )
        {
            LL x = mat2[p][i];
            if( dij2[x].v > dij2[p].v + cost2[p][i] )
            {
                dij2[x].v = dij2[p].v + cost2[p][i];
                dij2[x].pa = p;
                exo.p = x; exo.v = dij2[x].v;
                mq.push( exo );
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

   int tt, ca = 1;

   cin >> tt;

   while( tt-- )
   {
        mem( dij, 0 );
        mem( dij2, 0 );
        LL i, j, x, y, z, n, m, s, t, k, mx = -1, f;

        cin >> n >> m >> s >> t >> k;

        for( i=0; i<=n; i++ )
            mat[i].clear(), cost[i].clear(), dij[i].v = maxx, dij2[i].v = maxx;

        for( i=0; i<m; i++ )
        {
            cin >> x >> y >> z;
            mat[x].pb( y ); cost[x].pb( z );
            mat2[y].pb( x ); cost2[y].pb( z );
        }

        dijkstra( s );
        dijkstra2( t );

        for( i=1; i<=n; i++ )
        {
            f = dij[i].v;
            for( j=0; j<mat[i].size(); j++ )
            {
                x = mat[i][j];
                x = dij2[x].v;
                //cout << i << ' ' << mat[i][j] <<' '<< f << ' ' << x << "k" << cost[i][j] << endl;
                x = f+x+cost[i][j];

                if( x <= k && cost[i][j] > mx )
                {
                    mx = cost[i][j];
                }
            }
        }
        if( mx >= maxx ) mx = -1;

        cout << "Case " << ca++ << ": " << mx << endl;
   }


    return 0;

}



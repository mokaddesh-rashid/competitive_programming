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
LL L;
LL s, t;

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
node exo;

void dijkstra( LL p )
{
    //cout << p << endl;
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
            //cout << x << endl;
            if( dij[x].v > dij[p].v + cost[p][i] )
            {
                dij[x].v = dij[p].v + cost[p][i];
                if( cost[p][i] == 0 ) dij[x].v++;
                dij[x].pa = p;
                dij[x].c = cost[p][i];
                exo.p = x; exo.v = dij[x].v;
                mq.push( exo );
            }
        }
    }
}

LL bruh[10001][3];
LL info[10021][11];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

        mem( dij, 0 );
        mem( info, -1 );
        LL i, j, x, y, z, n, m, p = 0, a, b, c, d = 0;

        cin >> n >> m >> L >> s >> t;

        for( i=0; i<=n; i++ )
            mat[i].clear(), cost[i].clear(), dij[i].v = maxx;

        for( i=0; i<m; i++ )
        {
            cin >> x >> y >> z;
            info[i][0] = x; info[i][1] = y; info[i][2] = z;
            if( z == 0 )
            {
                info[i][3] = 1;
                bruh[p][0] = x; bruh[p][1] = y;
                p++;
                continue;
            }
            mat[x].pb( y ); cost[x].pb( z );
            mat[y].pb( x ); cost[y].pb( z );
        }

        dijkstra( s );
        //cout << dij[t].v << endl;

       if( dij[t].v > L )
       {
           for( i=0; i<p; i++ )
           {
               x = bruh[i][0]; y = bruh[i][1]; z = 0;
               mat[x].pb( y ); cost[x].pb( z );
               mat[y].pb( x ); cost[y].pb( z );
               if( dij[t].v <= L ) break;
           }
       }
       else if( dij[t].v < L ) d = 1;
       for( i=0; i<=n; i++ ) dij[i].v = maxx;

       dijkstra( s );
       //cout << dij[t].v << ' ' << d << endl;

       LL lel;

       if( dij[t].v > L || d == 1 ) cout << "NO\n";

       else
       {
           int al = 0, ok = 2;
           while( L > dij[t].v )
           {
               x = t;
               while( x != s )
               {
                       //cout << x << endl;
                       a = x;
                       b = dij[x].pa;

                       for( i=0; i<m; i++ )
                       {
                           if( ( info[i][0]  == a && info[i][1] == b && info[i][3] == 1 ) || ( info[i][0]  == b && info[i][1] == a && info[i][3] == 1  ) )
                           {
                               //cout << a << ' ' << b << endl;

                             if( L > dij[t].v )
                             {
                                 info[i][2] = 1 + ( L - dij[t].v );
                                 dij[t].v = L;
                             }
                             else info[i][2] = 1;
                             //cout << info[i][2] << endl;
                           }
                       }

                   x = dij[x].pa;
               }

               mem( dij, 0 );

               for( i=0; i<m; i++ )
               {
                   dij[i].v = maxx;
                   //if( al == 1 ) break;
                   mat[i].clear(); cost[i].clear();
                   if( info[i][2] == 0 ) info[i][2] = L+1;
               }

               for( i=m; i<=n+1; i++ ) dij[i].v = maxx, mat[i].clear(), cost[i].clear();

               for( i=0; i<m; i++ )
                {
                    x = info[i][0]; y = info[i][1]; z = info[i][2];
                    //cout << x << ' ' << y << ' ' << z << endl;
                    mat[x].pb( y ); cost[x].pb( z );
                    mat[y].pb( x ); cost[y].pb( z );
                }

               dijkstra( s );
               //cout << dij[t].v << endl;
               al = 1;

           }

           x = t;
               while( x != s )
               {
                       //cout << x << endl;
                       a = x;
                       b = dij[x].pa;

                       for( i=0; i<m; i++ )
                       {
                           if( ( info[i][0]  == a && info[i][1] == b && info[i][3] == 1 ) || ( info[i][0]  == b && info[i][1] == a && info[i][3] == 1  ) )
                           {
                               //cout << a << ' ' << b << endl;

                             if( L > dij[t].v )
                             {
                                 info[i][2] = 1 + ( L - dij[t].v );
                                 dij[t].v = L;
                             }
                             else info[i][2] = 1;
                             //cout << info[i][2] << endl;
                           }
                       }

                   x = dij[x].pa;
               }

               mem( dij, 0 );

               for( i=0; i<m; i++ )
               {
                   dij[i].v = maxx;
                   //if( al == 1 ) break;
                   mat[i].clear(); cost[i].clear();
                   if( info[i][2] == 0 ) info[i][2] = L+1;
               }

               for( i=m; i<=n+1; i++ ) dij[i].v = maxx, mat[i].clear(), cost[i].clear();

               for( i=0; i<m; i++ )
                {
                    x = info[i][0]; y = info[i][1]; z = info[i][2];
                    //cout << x << ' ' << y << ' ' << z << endl;
                    mat[x].pb( y ); cost[x].pb( z );
                    mat[y].pb( x ); cost[y].pb( z );
                }

               dijkstra( s );
               //cout << dij[t].v << endl;
               al = 1;


           cout << "YES\n";

           for( i=0; i<m; i++ )
           {
               if( info[i][2] == 0 ) info[i][2] = maxx;
               cout << info[i][0] << ' ' << info[i][1] << ' ' << info[i][2] << endl;
           }
       }

    return 0;

}

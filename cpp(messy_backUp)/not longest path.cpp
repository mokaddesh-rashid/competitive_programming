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
#define mn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> pr;


//set<int>::iterator ii;

class Compare{
public:
    bool operator()(pr x, pr y){
        return ( x.first > y.first );
    }
};

vector <LL> mat[5011], cost[5011]; ///adjecency matrix

priority_queue< pr, vector<pr>, Compare > que;
LL cnt;

struct info0
{
    LL v, va, l, m, pa , mi_r, ad_r;
}lar[6001]; // array of info about input


int in[50001];
///**************dij*********
void dij( int p ) ///dij
{
    //cout << p << endl;
    lar[p].v = 0;
    lar[p].va = 0;
    lar[p].pa = -1;

    pair<LL,LL> mp;
    mp = make_pair( 0, p );
    que.push(mp);//que[re] = p;


    while( !que.empty() )
    {
        p = que.top().second;
        que.pop();

        for(LL i=0; i<mat[p].size(); i++ )
        {
            LL x = mat[p][i], y;

            if( lar[p].v + cost[p][i] < lar[x].v )
            {
                lar[x].mi_r = min( cost[p][i], lar[p].mi_r );
                lar[x].va = lar[x].v;
                lar[x].v = lar[p].v + cost[p][i];
                lar[x].pa = p;
                in[x]++;
                mp = make_pair( lar[x].v, x );
                que.push(mp);

            }
            else
            {
                y = lar[x].va;
                lar[x].va = min( lar[x].va, lar[p].v + cost[p][i] );
                if( lar[x].v == lar[x].va ) lar[x].va = y;
            }

        }

    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    memset( lar, 0, sizeof(lar) );

    LL i, j, x, y, n, m, z, a, b, c, e, f, g, h, k;

    cin >> n >> m;

    for( i=0; i<=n+1; i++ )
        {
            mat[i].clear(), cost[i].clear();
            lar[i].v = lar[i].va = lar[i].mi_r =  lar[i].ad_r = maxx;
        }

    for( i=0; i<m; i++ )
    {
        cin >> x >> y >> z;
        lar[x].ad_r = min( z, lar[x].ad_r ); lar[y].ad_r = min( z, lar[y].ad_r );
        mat[y].push_back(x),mat[x].push_back(y); cost[y].push_back(z),cost[x].push_back(z);
    }

    dij(1);
    a = n;
    b = lar[n].mi_r;

    while( a != 1 && a > 0 )
    {
       b = min( b, lar[a].ad_r );
       a = lar[a].pa;

    }

    cout << min( b+lar[n].v+b, lar[n].va );

    return 0;

}


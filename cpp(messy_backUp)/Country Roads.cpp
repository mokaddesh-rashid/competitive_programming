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
#define mn          (long long)-
#define mx          (long long) 10000000000000000
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
        return (x.first > y.first );
    }
};

vector <LL> mat[5100], cost[5100]; ///adjecency matrix

priority_queue< pr, vector<pr>, Compare > que;
LL cnt, tim[100010];

struct info0
{
    LL v, l, pa, va, c;
}lar[5100]; // array of info about input



///**************dij*********
void dij( int p ) ///dij
{
    //cout << p << endl;
    int ti = 1;
    lar[p].v = 0;
    lar[p].l = mx;
    lar[p].pa = -1;
    pair<LL,LL> mp;
    mp = make_pair( 0, p );
    que.push(mp);//que[re] = p;


    while( !que.empty() )
    {
        p = que.top().second;
        que.pop();
        //cout << p << " = ";
        for(LL i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];

            if( cost[p][i]+lar[p].v  < lar[x].v )
            {
                //cout << x << '(' << lar[p].v + cost[p][i] << ')' << ' ';
                cout << p << ' ' << x << ' ' << lar[x].v << ' ' << lar[p].v << ' ' << cost[p][i] << ' ' << lar[x].va << endl;
                LL a = lar[x].va;
                lar[x].va = lar[x].v;
                if( lar[x].va == lar[x].v ) lar[x].va = a;
                cout << lar[x].va << endl;
                lar[x].c = cost[p][i];
                lar[x].l = min( lar[p].l, cost[p][i] );
                lar[x].v = cost[p][i]+lar[p].v;
                lar[x].pa = p;
                tim[x]++;
                mp = make_pair( lar[x].v, x );
                que.push(mp);//que[re] = x;

            }
            else if( x != lar[p].pa )
            {
               // cout << p << ' ' << x << ' ' << lar[x].v << ' ' << lar[p].v << ' ' << cost[p][i] << ' ' << lar[x].va << endl;
                LL a = lar[x].va;
                lar[x].va = min( lar[x].va, cost[p][i]+lar[p].v );
                if( lar[x].va == lar[x].v ) lar[x].va = a;
                cout << lar[x].va << endl;
            }

        }
        //cout << endl;
        //hd++;
    }
    return;
}

LL val( int n )
{
    LL x = n, y = 0, z = mx;

    cout << endl;

    while( x != 1 )
    {
cout << x << ' ' << lar[x].va << ' ' << y << endl;
        z = min( lar[x].va+y, z );
        y = y+lar[x].c;
        x = lar[x].pa;
    }

    return z;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        mem( tim, 0 );
        LL i, j, x, y, n, m, z, a, b, c, e, f, g, h, k;

        cin >> n >> m;

        mem( lar, 0 );
        for( i=0; i<=n; i++ )
            lar[i].v = mx, lar[i].va = mx, mat[i].clear(), cost[i].clear();

        for( i=0; i<m; i++ )
        {
            cin >> x >> y >> z;

            mat[y].push_back(x),mat[x].push_back(y);
            cost[y].push_back(z),cost[x].push_back(z);
        }
        dij( 1 );
        for( i=0; i<mat[1].size(); i++ ) lar[n].l = min( lar[n].l , cost[1][i] );
        if( lar[n].v == mx ) cout << "Case " << ca++ << ": Impossible" << endl;
        else cout << "Case " << ca++ << ": " << min( lar[n].v+lar[n].l+lar[n].l, val( n ) ) << endl;

    }
    return 0;

}

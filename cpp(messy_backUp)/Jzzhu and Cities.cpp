#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%I64d", &n)
#define sff(a,b)    scanf("%I64d %I64d", &a, &b)
#define sfff(a,b,c)    scanf("%I64d %I64d %I64d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
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

vector <LL> mat[100011], cost[100011]; ///adjecency matrix

priority_queue< pr, vector< pr >, Compare > que;
LL cnt;

struct info0
{
    LL v, l, pa;
}lar[200001]; // array of info about input



///**************dij*********
void dij( int p ) ///dij
{
    //cout << p << endl;
    lar[p].v = 0;
    lar[p].l = 1;
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

            if( lar[p].v + cost[p][i] < lar[x].v )
            {
                //cout << x << '(' << lar[p].v + cost[p][i] << ')' << ' ';
                lar[x].v = lar[p].v + cost[p][i];
                lar[x].l = lar[p].l+1;
                lar[x].pa = p;
                mp = make_pair( lar[x].v, x );
                que.push(mp);//que[re] = x;

            }
            if( lar[p].v + cost[p][i] == lar[x].v && p != 1 )
                lar[x].pa = p;

        }
        //cout << endl;
        //hd++;
    }
    return;
}

LL save[100010];
void mess()
{
   for(int i=1; i<=100010; i++ )
         lar[i].v = maxx;
}

void sa()
{
    for(int i=1; i<= 100010; i++ )
        save[i] = lar[i].v;
}

int main()
{
    //ios::sync_with_stdio(false);
    //memset( lar, 0, sizeof(lar) );
    LL i, j, x, y, n, m, z, a, b, c, e, f, g, h, k;

    //cin >> n >> m >> k;
    sfff( n, m, k );
    mess();
    for( i=0; i<m; i++ )
    {
        sfff( x, y, z );
        //cin >> x >> y >> z;
        mat[y].push_back(x),mat[x].push_back(y);
        cost[y].push_back(z),cost[x].push_back(z);
    }

    dij(1);
    sa();

    for( i=0; i<k; i++ )
    {
        sff( y, z );
        //cin >> y >> z;
        x = 1;
        mat[y].push_back(x),mat[x].push_back(y);
        cost[y].push_back(z),cost[x].push_back(z);
    }

    //mess();
    dij(1);
    cnt = 0;

    for( i=1; i<=n; i++ )
        if( save[i] > lar[i].v && lar[i].pa == 1 )
            cnt++;
    pf("%I64d", k-cnt );
    //cout << k-cnt << endl;

    return 0;

}


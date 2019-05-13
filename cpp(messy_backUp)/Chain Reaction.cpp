#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;


vector<PR> mat[MAX];
vector<PR> paInfo[MAX];
int lev[MAX], pa, cen, sub[MAX], tr_sz, dis[MAX];

void col_info(int p,int baap)
{
    if(cen) paInfo[p].PB( {cen, dis[p]} ); sub[p] = 1;
    for(auto x : mat[p])
    {
        if(lev[pa] < lev[x.F]) pa = x.F;
        if(x.F == baap || lev[x.F]) continue;

        dis[x.F] = dis[p] + 1; col_info(x.F, p); sub[p] += sub[x.F];

    }
}

int centroid(int p,int baap)
{
    if((sub[p]<<1) <= tr_sz) return baap;

    for(auto x : mat[p])
        if((sub[x.F]<<1) > tr_sz && !lev[x.F] && x.F != baap)
            return centroid(x.F, p);

    return p;
}

map<PR,int> mopa;
multiset<int> sota[MAX*2], gigi[MAX], prin;
multiset<int>::iterator it, iit;
int cici[MAX];

int getId(int p,int q)
{
    if(mopa[ MP(p, q) ] == 0) mopa[ MP(p, q) ] = mopa.size();
    return mopa[ MP(p, q) ];
}


int get_val(int p)
{
    it = gigi[p].end(); it--; iit = it; iit--;
    return (*it + *iit);
}
void update(int p,int t)
{
    if(gigi[p].size() < 2) return;
    int v = get_val( p );

    if(t) prin.insert( v );
    else if(prin.size()) prin.erase( prin.find( v ) );
}

void add_node(int p)
{
    int lp = p;
    for(auto x : paInfo[p])
    {
        int ii = getId(x.F, lp);
        update(x.F, 0);
        if(sota[ii].size())
            gigi[x.F].erase( gigi[x.F].find( *(sota[ii].rbegin()) ) );

        sota[ii].insert( x.S );
        gigi[x.F].insert( *(sota[ii].rbegin()) );
        update(x.F, 1);

        lp = x.F;
       /// cout << "add " << ' ' << ' ' << x.F << ' ' << x.S << endl << endl;
    }
}

void delete_node(int p)
{
    int lp = p;
    for(auto x : paInfo[p])
    {
        int ii = getId(x.F, lp);

        update(x.F, 0);
        gigi[x.F].erase( gigi[x.F].find( *(sota[ii].rbegin()) ) );
        sota[ii].erase( sota[ii].find( x.S ) );

        if(sota[ii].size())
            gigi[x.F].insert( *(sota[ii].rbegin()) );
        update(x.F, 1);

        lp = x.F;
        ///cout << "del " << ' ' << x.F << ' ' << x.S << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    int n, u, v, k, c;

    cin >> n;
    cout << n << endl;
    FOR(i,1,n-1)
    {
        cin >> u >> v >> c;
        cout << u << ' ' << v << ' ' << c << endl;
        mat[u].PB( MP(v, c) ); mat[v].PB( MP(u, c) );
    }

    FOR(l,1,18)
        FOR(i,1,n)
        {
            if(lev[i]) continue;

            pa = 0; col_info(i, i); tr_sz = sub[i];
            cen = centroid(i, i);

            dis[cen] = 0; col_info(cen, cen);
            lev[cen] = lev[pa] + 1; cen = 0;
        }

    FOR(i,1,n) reverse(paInfo[i].begin(), paInfo[i].end());
    FOR(i,1,n) {u = i; add_node( u ); cici[u] = 1;}
    c = n;
    cout << "Fuck" << endl;
    char ch;

    cin >> k;
    cout << k << endl;
    FOR(oo,0,k-1)
    {
        cout << oo << ' ' << k << endl;
        cin >> ch;
        if(ch == 'A')
        {
            if(!c) cout <<  "They have disappeared." << endl;
            else if(c == 1) cout << 0 << endl;
            else cout << *(prin.rbegin()) << endl;
        }
        else
        {
            cin >> u;
            if(!cici[u]) add_node( u );
            else delete_node( u ); c-= cici[u];
            cici[u] ^= 1;
        }
    }

    return 0;
}

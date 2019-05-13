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
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str;
map<LL,int> mopa;

LL hashVal(string str)
{
    int ba = 1;
    LL c = 0;
    FOR(i,0,(int)str.size()-1)
    {
        LL x = str[i] - 'a'; x++;
        c += (x * ba);
        ba *= 31;
    }
    return c;
}

LL giveId(string str, int id)
{
    return mopa[ hashVal( str ) ] = id;
}
LL getId(string str)
{
    return mopa[ hashVal( str ) ];
}

int n, m, q, pa[MAX];
string xo, yo;
pair<int,PR> in[MAX];

int finPa(int p)
{
    return (pa[p] == p) ? p :( pa[p] = finPa( pa[p] ) );
}

int mergeAB(int x,int y)
{
    int a = finPa(x);
    int b = finPa(y);

    if(a == b) return 0;

    pa[a] = b;
    return 1;
}

int bfs[MAX], lev[MAX], vis[MAX];
vector<PR> mat[MAX];

void dfs(int p)
{
    vis[p] = 1;
    for(auto x : mat[p])
    {
        if(vis[x.F]) continue;
        lev[x.F] = lev[p] ^ x.S;
        dfs(x.F);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int ty, a, b, x, y;

    cin >> n >> m >> q;
    FOR(i,1,n)
    {
        cin >> str;
        giveId(str, i);
        pa[i] = i;
    }

    FOR(i,0,m-1)
    {
        cin >> in[i].F >> xo >> yo;
        in[i].S = {getId(xo), getId(yo)};

        if( mergeAB(in[i].S.F, in[i].S.S) )
        {
            mat[in[i].S.F].PB(MP(in[i].S.S, in[i].F - 1));
            mat[in[i].S.S].PB(MP(in[i].S.F, in[i].F - 1));
        }
    }

    FOR(i,1,n) if(!vis[i]) dfs(i);

    FOR(i,0,m-1)
    {
        if(in[i].F - 1 == ( lev[in[i].S.F] ^ lev[in[i].S.S] ) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    FOR(i,1,q)
    {
        cin >> xo >> yo;

        x = getId(xo); y = getId(yo);
        if(finPa(x) != finPa(y)) cout << 3 << endl;
        else cout << ( lev[x] ^ lev[y] ) + 1 << endl;
    }

    return 0;
}


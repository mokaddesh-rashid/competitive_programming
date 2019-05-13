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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
typedef pair<int,int> PR;

vector<int> mat[MAX];
int lev[MAX], low[MAX], ti, art[MAX];

int artc(int p,int pa = -1)
{
    lev[p] = low[p] = ++ti;

    int ret = 0, chichi = 0;
    art[p] = 0;

    for(auto x : mat[p])
    {
        if(!lev[x])
        {
            ret += artc(x, p);
            low[p] = min(low[p], low[x]);

            if(lev[p] <= low[x])
                if(pa != -1) art[p] = 1;
                else if(chichi) art[p] = 1;

            chichi++;
        }
        else if(x != pa) low[p] = min(low[p], lev[x]);
    }


    return min(1, ret + art[p]);
}

void add_edge(int u,int v)
{
    mat[u].PB( v );
    mat[v].PB( u );
}

int iii[55][55], n, m;
string str[55];

int giveId(int n,int m)
{
    int id = 0;

    FOR(i,0,n-1)
    FOR(j,0,m-1) iii[i][j] = id++;
}

int fx[4] = {0, 0, 1, -1};
int fy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
//    inf;
//    outf;
    int u, v, x, y, c = 0;

    cin >> n >> m;
    FOR(i,0,n-1) cin >> str[i];
    giveId(n, m);

    FOR(i,0,n-1)
    {
        FOR(j,0,m-1)
        {
            if(str[i][j] == '#')
            {
                x = i; y = j; c++;
                FOR(k,0,3)
                {
                    u = i + fx[k]; v = j + fy[k];
                    if( valid(u, v) && str[u][v] == '#' )
                        add_edge(iii[i][j], iii[u][v]);
                }
            }
        }
    }

    if(c < 3) cout << -1 << endl;
    else cout << 2 - artc( iii[x][y] ) << endl;

    return 0;
}

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
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

struct edge
{
    int a, b, cost;
};

int n, m;
vector<edge> e;
const int INF = 1000000000;
int cursed[1010];

int solve(int v)
{
    int p = 0;
    vector<int> d (n, INF);

    d[v] = 0;
    for (;;)
    {
        p++;
        bool any = false;

        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    any = true;
                }

        if (!any || p == n + n + n) break;
    }

    FOR(i,0,n-1) cursed[i] = d[i];

    if(d[v] < 0 || p == n + n + n) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        edge ed;

        cin >> n >> m;
        e.clear();

        FOR(i,0,m-1)
        {
            cin >> ed.a >> ed.b >> ed.cost;
            e.push_back( ed );
        }
        int prin = solve( 0 );
        prin = max(prin, ole( 0 ));
        if( prin ) cout << "Case #" << tt << ": possible\n";
        else cout << "Case #" << tt << ": not possible\n";

    }

    return 0;
}


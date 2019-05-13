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
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int N = 2e5 + 5;

vector<int> g[N];
int mt[N];
int used[N];
int T = 1;

bool try_kuhn(int v)
{
    if (used[v] == T)
        return false;
    used[v] = T;

    for (auto to : g[v]) {
        if (mt[to] == -1) {
            mt[to] = v;
            return true;
        }
    }

    for (auto to : g[v]) {
        if (try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }

    return false;
}

pair<int, PR> ara[MAX];

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;
    int n, m;

    cin >> n >> m;
    FOR(i,0,m-1)
        cin >> ara[i].S.F >> ara[i].S.S >> ara[i].F;
    sort(ara, ara + m, greater< pair<int, PR> >());

    FOR(i,0,m-1)
    {
        g[i].PB( ara[i].S.F );
        g[i].PB( ara[i].S.S );
    }

    memset(mt, -1, sizeof(mt));
    LL show = 0;
    for (int i = 0; i < m; ++i) {
        if (try_kuhn(i))
        {
            ++T;
            show = (LL)show + ara[i].F;
        }
    }

    cout << show << endl;

    return 0;
}

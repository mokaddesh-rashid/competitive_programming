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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pii;

vector<int> mat[MAX];
int n, m, P, val[MAX], cost[MAX], dfa[MAX], st[MAX], en[MAX], ti, rev[MAX];

int getAl(int p) {return n + p;}

void dfs(int p)
{
    ++ti;
    st[p] = ti; rev[ti] = p;
    for(auto x : mat[p]) dfs( x );
    en[p] = ti;
}

int dp[3005][1005];
int rec(int p,int baki)
{
    if(p > ti) return 0;

    int &temp = dp[p][baki];
    if(temp != -1) return temp;

    temp = rec(p + 1, baki);

    int cp = rev[p];
    if(baki >= cost[cp]) temp = max(temp, val[cp] + rec(en[cp] + 1, (baki - cost[cp])));
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int a, p, v;

    cin >> n >> m >> P;
    FOR(i,1,n)
    {
        cin >> a >> p >> v;
        mat[getAl( a )].PB( i );
        val[i] = v; cost[i] = p;
        val[ getAl( a ) ] += v;
    }
    FOR(i,1,m)
    {
        cin >> v;
        cost[ getAl( i ) ] = v;
        mat[0].PB( getAl( i ) );
    }
    dfs(0);
    mem(dp, -1);
    cout << rec(0, P) << endl;
    return 0;
}


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
#define MAX 55
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
#define LD long double

double dp[MAX][MAX][MAX][MAX], fac[MAX], gigi[MAX];
bool vis[MAX][MAX][MAX][MAX];
int n, ara[MAX], s;

double rec(int p,int tok,int rem,int ig)
{
    if(rem < 0) return 0;
    if(!p)
    {
        if(rem < ara[ig]) return gigi[tok] * gigi[n - tok - 1] * tok;
        else return (double)0;
    }

    double &temp = dp[p][tok][rem][ig];
    if(vis[p][tok][rem][ig]) return temp;

    vis[p][tok][rem][ig] = 1;
    temp = rec(p - 1, tok, rem, ig);
    if(ig != p) temp += rec(p - 1, tok + 1, rem - ara[p], ig);

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int c = 0;

    cin >> n;
    FOR(i,1,n) cin >> ara[i], c += ara[i];
    cin >> s;

    if(c <= s)
    {
        cout << n << endl;
        return 0;
    }

    FOR(i,0,n)
    {
        if(i == 0) gigi[i] = 1;
        else gigi[i] = i * gigi[i - 1];
    }

    double prin = 0;
    FOR(i,1,n) prin += rec(n, 0, s, i);
    cout << fixed;
    cout << setprecision( 9 ) << prin / gigi[n] << endl;

    return 0;
}


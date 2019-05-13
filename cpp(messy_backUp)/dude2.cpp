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
#define MAX 305
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int n, m, row, col, sum[MAX][MAX];
string str[MAX];

void rec(int x,int y,int c = 0)
{
    if(!valid(x, y)) return;

    if(str[x][y] == '1') c++;
    sum[x][y] = c;

    rec(x - 1, y + 1, c);
}

int getSumPos(int x,int y,int laf)
{
    int u = x, v = y + laf, c;

    if(u + v > n + m) return 0;
    if(v > m) {c = u + v; v = m; u = c - m;}

    int a = x + laf, b = y;
    if(a > n) {c = a + b; a = n; b = c - n;}

    c = sum[u][v];
    if(a != n && b) c -= sum[a + 1][b - 1];

    return c;

}

int getSumNeg(int x,int y,int laf)
{
    int u = x - laf, v = y, c;

    if(u + v < 0) return 0;
    if(u < 0){c = u + v; u = 0; v = c;};

    int a = x, b = y - laf;
    if(b < 0){c = a + b; b = 0; a = c;};

    c = sum[u][v];
    if(a != n && b) c -= sum[a + 1][b - 1];

    cout << u << ' ' << v << ' ' << a << ' ' << b << endl;

    return c;

}



int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n >> m; row = n; col = m;
    n--; m--;

    FOR(i,0,n) cin >> str[i];

    FOR(i,0,n) rec(i, 0);
    FOR(i,1,m) rec(n, i);

    FOR(i,0,n)
    FOR(j,0,m)
    {
        cout << sum[i][j] << ' ';
        if(j == m) cout << endl;
    }

    for(;;)
    {
        int x, y, l;
        cin >> x >> y >> l;
        cout << getSumPos(x, y, l) << ' ' << getSumNeg(x, y, l) << endl;
    }
    return 0;
}

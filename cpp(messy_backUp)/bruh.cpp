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
#define MAX 10
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int dp[MAX][MAX][MAX], ara[MAX], n;

int rec(int p,int x,int y)
{
    if(p == n + 1) return 0;

    int &temp = dp[p][x][y];
    if(temp != -1) return temp;

    if(ara[p] == ara[x] - 1 || ara[p] == ara[x] + 1 || ara[p] % 7 == ara[x] % 7 || !x)
        temp = max(temp, 1 + rec(p + 1, p, y));

    if(ara[p] == ara[y] - 1 || ara[p] % 7 == ara[y] % 7 || !y || ara[p] == ara[y] + 1)
        temp = max(temp, 1 + rec(p + 1, x, p));

    return temp = max(temp, rec(p + 1, x, y));
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    cin >> n;
    FOR(i,1,n) cin >> ara[i];

    FOR(x,1,n)
    {
        FOR(y,1,n)
        {
            FOR(i,0,x-1)
            {

            }
        }
    }

    return 0;
}

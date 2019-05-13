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
#define MOD          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str[4];
LL dp[4][MAX][2], col, row;

LL rec(LL x,LL y,LL t)
{
    if(!valid(x, y) || str[x][y] == '#') return 0;
    if(x == row - 1 && y == col - 1) return t;

    LL &temp = dp[x][y][t];

    if(temp != -1) return temp;

    temp = 0;
    if(!t)
    {
        temp += rec(x + 1, y, (t + 1) % 2); temp %= MOD;
        temp += rec(x - 1, y, (t + 1) % 2); temp %= MOD;
    }
    else
    {
        temp += rec(x, y + 1, (t + 1) % 2); temp %= MOD;
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
//    inf;
//    outf;
    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        mem(dp, -1);
        cin >> col; row = 3;
        FOR(i,0,2) cin >> str[i];

        cout << "Case #" << tt << ": " << rec(0, 0, 0) << endl;
    }

    return 0;
}



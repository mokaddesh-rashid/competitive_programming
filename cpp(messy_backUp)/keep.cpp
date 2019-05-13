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
typedef pair<short,short> PR;

int n, ara[5005];
pair<short, PR> samne[5005][5005];
short dp[5005][5005];

short rec(short x,short y)
{
///    if(!x || !y) cout << x << ' ' << y << endl;
    short &temp = dp[x][y], ret;

    if(temp != -1) return temp;

    temp = 0;
    if(!x)
    {
        FOR(i,y + 1,n)
            temp = max(temp, rec(i, y));
    }
    else if(x <= n)
    {
        ret = 1 + rec(samne[x][max(x,y)].F, y);
        temp = max(temp, ret);

        ret = 1 + rec(samne[x][max(x,y)].S.F, y);
        temp = max(temp, ret);

        ret = 1 + rec(samne[x][max(x,y)].S.S, y);
        temp = max(temp, ret);
    }

    if(!y)
    {
        FOR(i,x + 1,n)
            temp = max(temp, rec(x, i));
    }
    else if(y <= n) temp = max(temp, rec(y, x));

    return temp;

}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n;
    FOR(i,1,n) cin >> ara[i];

    FOR(i,0,n)
    FOR(j,0,n)
    samne[i][j] = MP(n + 1, MP(n + 1, n + 1));

    FOR(i,1,n)
    {
        short a, b, c;
        a = b = c = n + 1;

        REV(j,n,i)
        {
            samne[i][j] = MP(a, MP(b, c));

            if(ara[i] % 7 == ara[j] % 7) a = j;
            if(ara[i] - 1 == ara[j]) b = j;
            if(ara[i] + 1 == ara[j]) c = j;
        }
    }

    short prin = 0;

    mem(dp, -1);
    prin = rec(0, 0);

    cout << prin << endl;

    return 0;
}


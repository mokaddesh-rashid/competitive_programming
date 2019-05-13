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
#define MAX 18
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
#define LD long double
typedef pair<int,int> PR;

int mat[MAX][MAX];
LL val[(1<<16) + 10], v, n;
LL dp[43046730], c;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    cin >> n;
    FOR(i,0,n-1)
    FOR(j,0,n-1) cin >> mat[i][j];

    FOR(mask,1,(1<<n)-1)
    {
        v = 0;
        FOR(i,0,n-1)
            FOR(j,i+1,n-1)
                if(mask & (1<<j) && mask & (1<<i)) v += mat[i][j];
        val[mask] = v;
    }

    int viv = 1;
    FOR(i,0,n) viv *= 3;
    int ms, go, r;

    FOR(op,1,viv-1)
    {
        ms = go = 0; v = op;
        ///cout << v << " = ";
        FOR(i,0,n-1)
        {
            if(v%3 == 0) ms |= (1<<i);
            else if(v%3 == 1) go |= (1<<i);
            ///cout << v%3;
            v /= 3;
        }
        v = go | ms;
        dp[v] = max(dp[v], val[go] + dp[ms]);
        //cout << " o[ " << v << ' ' << ms << " " << go << ' ' << val[go] << ' ' << dp[v] << endl;
    }

    cout << dp[(1<<n)-1] << endl;

    return 0;
}


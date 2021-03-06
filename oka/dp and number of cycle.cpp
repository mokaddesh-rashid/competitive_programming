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
#define MAX 22
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int con[MAX][MAX];
LL dp[1<<19][19];

int first(int mask)
{
    FOR(i,0,18)
        if(mask & (1<<i)) return i;

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    int n, m, a, b;

    cin >> n >> m;

    FOR(i,1,m)
    {
        cin >> a >> b; a--; b--;
        con[a][b] = 1;
        con[b][a] = 1;
    }

    LL prin = 0;

    FOR(mask,0,(1<<n) - 1)
    {
        int fst = first( mask );

        FOR(v,0,n-1)
        {
            if(mask == 1<<v) dp[mask][v] = 1;
            LL ans = dp[mask][v];

            if(ans)
            {
                if(fst != v && con[v][fst] && mask != (1<<v) + (1<<fst))
                    prin += ans;

                FOR(i,fst + 1,n-1)
                    if( !(mask & (1<<i)) && con[v][i] )
                        dp[mask + (1<<i)][i] += ans;
            }

        }
    }

    cout << prin / 2 << endl;

    return 0;
}

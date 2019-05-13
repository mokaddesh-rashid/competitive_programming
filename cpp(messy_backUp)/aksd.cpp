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
#define MAX 3010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

vector<PR> mat[MAX];
int n, can[MAX][MAX];
PR in[MAX];

int dfs(int p,int pa)
{
    int temp = 0;
    for(auto x : mat[p])
    {
        if(can[p][x.F] || pa == x.F) continue;
        temp += dfs(x.F, p);
        temp += x.S;
    }

    return temp;
}

int rec(int p,int pa,int val)
{
   /// cout << p << ' ' << val << endl;
    int temp = val;

    for(auto x : mat[p])
    {
        if(can[p][x.F] || pa == x.F) continue;
        if(x.S) temp = min(temp, rec(x.F, p, val - 1));
        else temp = min(temp, rec(x.F, p, val + 1));
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n, a, b;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> a >> b;
        mat[a].PB( MP(b, 0) );
        mat[b].PB( MP(a, 1) );
        in[i] = {a, b};
    }

    int prin = n - 1;
    FOR(i,1,n-1)
    {
        can[in[i].F][in[i].S] = 1;
        can[in[i].S][in[i].F] = 1;

        int x = dfs( in[i].F, -1);
        int y = dfs( in[i].S, -1);

        prin = min(prin, rec( in[i].F, -1, x)  + rec( in[i].S, -1, y));
        ///cout << << ' ' <<  << endl;

        can[in[i].F][in[i].S] = 0;
        can[in[i].S][in[i].F] = 0;
    }

    cout << prin << endl;

    return 0;
}

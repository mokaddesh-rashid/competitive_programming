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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

vector<int> mat[MAX];
int lev[MAX], root = 0, sub[MAX];

int dfs(int p,int pa)
{
    if(p == pa) root = lev[p] = sub[p] = 0;

    for(auto x : mat[p])
    {
        if(x == pa) continue;
        lev[x] = lev[p] + 1;

        if(p == pa) sub[x] = x;
        else sub[x] = sub[p];

        dfs(x, p);
    }

    if(mat[p].size() >= 3 && lev[p] > lev[root]) root = p;
}

vector<int> up, dwn;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n, u, v, p = -1, pao;

    cin >> n;

    FOR(i,1,n-1)
    {
        cin >> u >> v;
        //cout << u << ' ' << v << endl;
        mat[u].PB( v );
        mat[v].PB( u );
    }

    ///FOR(i,1,n) cout << mat[i].size() << endl;

    dfs(1, 1);
    pao = root;
   // cout << pao << ' ' << mat[pao].size() << endl;
    dfs(root, root);

    for(auto x : mat[pao])
    {
        if(x == sub[root]) continue;
        dwn.PB( x );
    }

    for(auto x : mat[root])
    {
        if(lev[root] > lev[x]) continue;
        up.PB( x );
    }
   /// cout << endl << endl;
    cout << dwn[0] << ' ' << up[0] << endl;
    cout << up[1] << ' ' << dwn[1] << endl;


    return 0;
}

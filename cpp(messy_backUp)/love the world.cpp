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
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

vector<int> mat[MAX], chi[MAX];
int deg[MAX], n, k, prin;
queue<int> que;

int dfs(int p,int pa)
{
    int ret = -1;

    for(auto x: mat[p])
    {
        if(x == pa) continue;
        int r = dfs(x, p);

        if(r != -1) chi[p].PB( r + 1 );
    }
    sort(chi[p].begin(), chi[p].end());
    reverse(chi[p].begin(), chi[p].end());

    FOR(i,0,(int)chi[p].size() - 1)
    {
        int r1 = chi[p][i], r2 = 0;

        if(i + 1 != chi[p].size()) r2 = chi[p][i + 1];

        if(r1 + r2 > k) prin++;
        else return r1;
    }

    if(mat[p].size() == 1) return 0;
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int p, a, b;

    cin >> n >> k;
    FOR(i,1,n-1)
    {
        cin >> a >> b;
        mat[a].PB( b ); mat[b].PB( a );
        deg[a]++; deg[b]++;
    }

    FOR(i,1,n) if(deg[i] == 1) que.push( i ), deg[i] = 0;

    while(!que.empty())
    {
        p = que.front(); que.pop();

        for(auto x : mat[p])
        {
            if(!deg[x]) continue;

            deg[x]--;
            if(deg[x] == 1) que.push( x ), deg[x] = 0;
        }
    }

    //cout << p << endl;
    int x = dfs(p, p);
    cout << prin + (x != -1) << endl;

    return 0;
}


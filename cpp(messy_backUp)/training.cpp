#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out2.txt", "w", stdout)
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
#define MAX 255
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
typedef pair<int,int> pii;

int n, m, lev[MAX][MAX];
string str[MAX];
queue<pii> que;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

int check(int x,int y)
{
    int visited = 0;
    mem(lev, -1);

    FOR(i,0,n-1)
    FOR(j,0,m-1)
    {
        if(str[i][j] == '1' || (x == i && y == j))
        {
            que.push( {i, j} );
            lev[i][j] = 0;
        }
    }

    while(!que.empty())
    {
        int x = que.front().F, y = que.front().S;
        que.pop();
        visited = max(visited, lev[x][y]);

        FOR(i,0,3)
        {
            int a = x + fx[i], b = y + fy[i];
            if(valid(a, b) && lev[a][b] == -1)
            {
                que.push( {a, b} );
                lev[a][b] = lev[x][y] + 1;
            }
        }
    }
    return visited;

}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;

    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        cin >> n >> m;
        FOR(i,0,n-1) cin >> str[i];

        int st = 0, en = n + m, prin = n + m, mid;

        FOR(i,0,n-1)
            FOR(j,0,m-1) prin = min(prin, check(i, j));

        cout << "Case #" << tt << ": " << prin << endl;
    }
    return 0;
}


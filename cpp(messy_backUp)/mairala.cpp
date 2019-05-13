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
#define MAX 1010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n))
typedef pair<int,int> PR;

string str;
int n;
bool can[MAX][MAX][2];

void go(int p,int x,int y)
{
    if(x == n - 1 && y == n - 1) return;
    if(str[p] == 'E')
    {
        can[x][y][0] = 1;
        go(p + 1, x, y + 1);
    }
    else
    {
        can[x][y][1] = 1;
        go(p + 1, x + 1, y);
    }
}

LL dp[MAX][MAX];
LL rec(int x,int y)
{
    if(!valid(x, y)) return 1;
    if(x == n-1 && y == n-1) return 1;

    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;

    if(valid(x, y + 1) && !can[x][y][0]) dp[x][y] += rec(x, y + 1);
    if(valid(x + 1, y) && !can[x][y][1]) dp[x][y] += rec(x, y + 1);
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        cin >> n;
        cin >> str; n = str.size();

        cout << "Case #" << tt << ": ";
        FOR(i,0,n-1)
        {
            if(str[i] == 'S') cout << 'E';
            else cout << 'S';
        }
        cout << endl;
    }

    return 0;
}


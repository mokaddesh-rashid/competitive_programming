#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int dp[1001][1001];
int rec(int x, int y)
{
    if(y<0) return -10000;
    if(y==0) return 0;
    if(x==0) return -1000;
    if( dp[x][y] != -1 ) return dp[x][y];
    return dp[x][y] = max( 1+rec(x-1,y-x), rec(x-1,y) );
}

void prin(int x, int y)
{
    if(y<0) return;
    if(y==0) return;
    if(x==0) return;

    if( 1+rec(x-1,y-x) > rec(x-1,y) )
    {
        cout << x << ' ';
        prin(x-1,y-x);
    }
    else prin(x-1,y);
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    int i, j, x, y, n, m;
    cin >> n;
    x = rec(n,n);
    cout << x << endl;
    prin(n,n);
    return 0;
}


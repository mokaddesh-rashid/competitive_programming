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
#define H first
#define G second
#define MAX 110
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int dp[MAX][MAX*MAX][2], p, q, n;
pr ar[MAX];
int col[MAX][MAX*MAX][2];

int rec(int p,int v,int t)
{
    if(p == -1) return 0;

    int newV = v;

    if(t == 0)
    {
        int ho = ar[i].H - p;

    }
}

int mina[MAX][2*MAX][2];

int can(int v,int turn,int t)
{
    if(v <= 0 && t == 0) return 1000;
    if(v <= 0 ) return 0;
    if(mina[v][turn][t] != -1) return mina[v][turn][t];

    int &temp = mina[v][turn][t];

    temp = 1000;
    if(turn)
        temp = min(temp, can(v - p, turn - 1, t) + 1);

    if(!t)
    {
        temp = min(temp, can(v - p, turn, 1) + 1);
        temp = min(temp, can(v, turn + 1, 1));
    }
    else
    {
        temp = min(temp, can(v - q, turn, 0));
    }

    return temp;

}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    cin >> p >> q >> n;

    FOR(i, 0, n-1) cin >> ar[i].H >> ar[i].G;
    cout << rec(n-1, 0, 0) << endl;

    return 0;
}


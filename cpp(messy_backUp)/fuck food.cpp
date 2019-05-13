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
#define MAX 5010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < 4) && (ny >= 0) && (ny < 4))
typedef pair<int,int> PR;

int fx[] = {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};
int dp[5][5][(1<<16) + 5];

int rec(int x,int y,int mask)
{
    if(mask == ((1<<16) - 1)) return (x == 3 && y == 3);

    int temp = dp[x][y][mask];
    if(temp != -1) return temp;
    temp = 0;

    for(int i = 0; i <= 3; i++)
    {
        int gx = x + fx[i], gy = y + fy[i];
        int id = (gx * 4) + gy;

        if((!valid(gx, gy) || (mask & (1<<id))) && id) continue;
        temp = max(temp, rec(gx, gy, (mask | (1<<id))));
    }

    return temp;
}


void prin(int x,int y,int mask)
{
    cout << x << ' ' << y << endl;
    if(mask == ((1<<16) - 1)) return;

    int temp = dp[x][y][mask];

    for(int i = 0; i <= 3; i++)
    {
        int gx = x + fx[i], gy = y + fy[i];
        int id = (gx * 4) + gy;

        if(!valid(gx, gy) && (mask & (1<<id))) continue;
        if( rec(gx, gy, (mask | (1<<id))) )
        {
            prin(gx, gy, (mask | (1<<id)));
            return;
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

   mem(dp, -1);
   cout << rec(0, 0, 1);

    return 0;
}


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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str;
int m, n;
int dp[(1<<18) + 6][101];

int rec(int mask,int bak)
{
    int can = 0, ara[10] = {-1};
    for(int i = 0; i < n; i++)
    {
        if(mask & (1 << i)) continue;

        int v = str[i] - '0';
        can = can | (1<<v);
        ara[v] = i;
    }
    if(!can) return bak == 0;
    ///cout << mask << ' ' << can << ' ' << bak << endl;

    int &temp = dp[mask][bak];
    if(temp != -1) return temp;

    temp = 0;

    for(int i = 0; i < 10; i++)
    {
        if(can & (1 << i))
        {
            int v = ara[i];
            int newMask = mask | (1<<v);
            int newBak = bak * 10 + i; newBak %= m;
            cout << mask << ' ' << newMask << ' ' << bak << ' ' << newBak << ' ' << i << endl;
            temp += rec(newMask, newBak);
        }
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int prin = 0;

    cin >> str >> m; n = str.size();

    mem(dp, -1);
    FOR(i,0,n-1)
    {
        int v = str[i] - '0';
        if(!v) continue;

        int newMask = (1<<i);
        int newBak = v; newBak %= m;

        prin += rec(newMask, newBak);
    }
    cout << prin << endl;
    return 0;
}

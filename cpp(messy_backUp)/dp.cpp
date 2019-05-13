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
#define MAX 22
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))
#define LD long double
typedef pair<int,int> pii;

int dp[45][1<<6][1<<6], n, m;

int getMask(int mask)
{
    int newMask = 0;
    FOR(i,0,m-1)
        if(mask & (1<<i))
        {
            newMask |= (1<<i);
            if(i != m-1) newMask |= (1<<(i+1));
            if(i) newMask |= (1<<(i-1));
        }
    return newMask;
}
int needBit(int mask)
{
    return ((1<<m) - 1) ^ mask;
}

int rec(int lev,int mask,int covered)
{
    if(n == lev) return 0;

    int &temp = dp[lev][mask][covered];
    if(temp != -1) return temp;

    temp = n*m;
    int newMask = getMask( mask ) | covered;
    newMask = needBit( newMask );
    temp = __builtin_popcount( newMask ) + rec(lev + 1, newMask, mask);

    FOR(i,0,m-1)
    {
        if(mask & (1<<i)) continue;
        int newMask = mask | (1<<i);
        temp = min(temp, 1 + rec(lev, newMask, covered));
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    cin >> n >> m;if(n < m) swap(n, m);
    mem(dp, -1);
    cout << n*m - rec(0, 0, 0) << endl;

    return 0;
}




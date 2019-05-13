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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

LL dp[20][1<<20][2], k;
int l;

LL rec(int p,int mask,int ok)
{
    int n = 18 + ok;
    if(p == n) return 1;

    LL &temp = dp[p][mask][ok];
    if(temp != -1) return temp;

    temp = 0;
    for(int i=0; i<n; i++)
    {
        if(i == p) continue;
        if(mask & (1<<i)) continue;

        temp += rec(p + 1, mask | (1<<i), ok);
    }

    return  temp;
}

void prin(int p,int mask,int ok,LL k)
{
    int n = 18 + ok;
    if(p == n) return;

    for(int i=0; i<n; i++)
    {
        if(i == p) continue;
        if(mask & (1<<i)) continue;

        if(rec(p + 1, mask | (1<<i), ok) < k)
            k -= rec(p + 1, mask | (1<<i), ok);
        else
        {
            if(i + 1 > l) cout << (i + 1) - l << ' ';
            prin(p + 1, mask | (1<<i), ok, k);
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
    int n, ok;

    mem(dp, -1);

    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        cin >> n >> k;
        l = 18 + (n%2) - n;
        prin(0, 0, n%2, k);
        cout << endl;
    }

    return 0;
}


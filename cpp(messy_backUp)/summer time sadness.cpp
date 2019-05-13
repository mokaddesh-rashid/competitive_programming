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

LL dp[18][1<<18], k;
int n;

LL rec(int p,int mask)
{
    if(p == n) return 1;

    LL &temp = dp[p][mask];
    if(temp != -1) return temp;

    temp = 0;
    for(int i=0; i<n; i++)
    {
        if(i == p) continue;
        if(mask & (1<<i)) continue;

        temp += rec(p + 1, mask | (1<<i));
    }

    return  temp;
}

void prin(int p,int mask,LL k)
{
    if(p == n) return;

    for(int i=0; i<n; i++)
    {
        if(i == p) continue;
        if(mask & (1<<i)) continue;

        if(rec(p + 1, mask | (1<<i)) < k)
            k -= rec(p + 1, mask | (1<<i));
        else
        {
            cout << i + 1 << ' ';
            prin(p + 1, mask | (1<<i), k);
            return;
        }
    }

    return;
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
        mem(dp, -1);
        cin >> n >> k;
        prin(0, 0, k);
        cout << endl;
    }

    return 0;
}


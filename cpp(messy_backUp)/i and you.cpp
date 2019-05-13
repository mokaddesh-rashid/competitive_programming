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
#define MAX 110
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int prema[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

int dp[105][1<<18], n, ara[105], maal[MAX];

int rec(int p,int mask)
{
    if(p == n) return 0;

    int &temp = dp[p][mask];
    if(temp != -1) return temp;

    temp = rec(p + 1, mask) + (ara[p] - 1);

    /// baki ase keso part
    FOR(i,2,59)
    {
        if(mask & maal[i]) continue;
        temp = min(temp, abs(ara[p] - i) +
                   rec(p + 1, mask ^ maal[i]));
    }
    return temp;

}

void prin(int p,int mask)
{
    if(p == n) return;

    int &temp = dp[p][mask];

    if(temp == rec(p + 1, mask) + (ara[p] - 1))
    {
        cout << 1 << ' ';
        prin(p + 1, mask);
        return;
    }

    /// baki ase keso part
    FOR(i,2,59)
    {
        if(mask & maal[i]) continue;
        if(temp == abs(ara[p] - i) + rec(p + 1, mask ^ maal[i]))
        {
            cout << i << ' ';
            prin(p + 1, mask ^ maal[i]);
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

    FOR(i,2,59)
        FOR(j,0,17)
            if(i%prema[j] == 0) maal[i] ^= (1<<j);

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];

    rec(0, 0);
    prin(0, 0);

    return 0;
}


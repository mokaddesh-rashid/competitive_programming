#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
#define MAX 2010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> PR;

LL dp[MAX], n, ara[MAX], mid;

LL rec(LL p)
{
    if(p == n) return 0;

    LL &temp = dp[p], jump = 0;
    if(temp != -1) return temp;

    temp = (20000);
    FOR(go,p + 1,n)
    {
        LL x = abs(ara[go] - ara[p]); jump++;
        LL v = (x / jump) + (x % jump != 0);
        ///cout << p << ' ' << go << ' ' << jump << endl;
        if(v <= mid || go == n) temp = min(temp, (jump - 1) + rec(go));
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL r, cc = 0;

    cin >> n >> r;
    FOR(i,0,n-1) cin >> ara[i];

    LL st = 0, en = (2e9);

    while(st <= en)
    {
        mid = (st + en)>>1;
        mem(dp, -1);
        LL prin = (2e9);

        FOR(i,0,n)
            prin = min(prin, i + rec(i));

        if(prin <= r) en = mid - 1;
        else st = mid + 1;

        cc++;
        if(cc > 33) cout << "FUCL" << ' ' << st << ' ' << en << endl;
       // cout << mid << ' ' << prin << endl;
    }
    cout << en + 1 << endl;
    return 0;
}


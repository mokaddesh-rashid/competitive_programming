#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
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
typedef pair<LL,LL> pr;

LL ar[200010], cnt[200010], sm[200010];
LL query[200010][3];
pr damn[200010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m;

    cin >> n >> m ;

    FOR(i,1,n) cin >> ar[i];
    FOR(i,0,m-1)
    {
        cin >> query[i][0] >> query[i][1];
        cnt[query[i][0]]++;
        cnt[query[i][1]+1]--;
    }

    FOR(i,1,n)
    {
       x += cnt[i];
       damn[i].F = x; damn[i].S = i;
    }

    sort( ar+1, ar+n+1, greater<LL>() );
    sort( damn+1, damn+n+1, greater<pr>() );

    FOR(i,1,n)
    {
        //cout << ar[i] << ' ' << damn[i].S << endl;
        sm[damn[i].S] = ar[i];
    }

    x = 0;
    FOR(i,1,n)
    {
        x += sm[i];
        sm[i] = x;
    }

    x = 0;
    FOR(i,0,m-1)
    {
       x += (sm[query[i][1]]-sm[query[i][0]-1]);
    }

    cout << x << endl;
    return 0;

}



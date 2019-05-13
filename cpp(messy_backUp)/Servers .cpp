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

int cnt[1001];
int main()
{
    ios::sync_with_stdio(false);
    int i, j, x, y, n, m, q, t, k, d, a, b, c;
    cin >> n >> q ;
    x = n;
    FOR(i,0,q-1)
    {
        cin >> t >> k >> d;
        FOR(j,1,n)
        {
            //cout << j << ' ' << cnt[j] << endl;
            if( cnt[j] < t && cnt[j] != 0 ) cnt[j] = 0, x++;
        }
        LL ans = 0;
        //cout << x << ' ' << k << endl;
        if( x >= k )
        {
            FOR(j,1,n)
            {
                if(k>0&&cnt[j]==0) cnt[j] = t+d-1, x--, ans += j, k--;
            }
            cout << ans << endl;
        }
        else cout << -1 << endl;
        //cout << x << endl << endl;
    }
    return 0;

}



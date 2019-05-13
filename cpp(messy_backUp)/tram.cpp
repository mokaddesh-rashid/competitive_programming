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

LL tr[20000];
int main()
{
    ios::sync_with_stdio(false);
    mem(tr,-1);
    LL i, j, x, y, n, m, a, b, c, d, nd = 0, cnt = 0, s, t, bus, walk, p;
    LL ans = maxx;
    cin >> n >> s >> t;
    if( s < t ) a = 1;
    else a = 0;
    cin >> bus >> walk;
    cin >> p >> d;
    if( d == -1 ) d = 0;
    while(cnt<=n)
    {
       //cout << p << ' ' << d << endl;
       if( d == a || p == 0 || p == n) tr[p] = nd, cnt++;///cout << p << ' ' << nd << endl;
       nd += bus;
       if( p == n ) d = 0;
       else if( p == 0 ) d = 1;
       if( d == 1 ) p++;
       else p--;
    }
    LL ex = 0;
    if( s < t )
    {
        FOR(i,s,t)
        {
            a = ((t-i)*walk)+ex;

            b = ((t-i)*bus)+tr[i]+ex;
            //cout << a << ' ' << b << endl;
            ans = min( ans, a);
            ans = min( ans, b);
            ex += walk;
        }
    }
    else
    {
        REV(i,s,t)
        {
            a = ((i-t)*walk)+ex;
            b = (i-t)*bus+tr[i]+ex;
            ans = min( ans, a);
            ans = min( ans, b);
            ex += walk;
        }
    }
    cout << ans;
    return 0;

}



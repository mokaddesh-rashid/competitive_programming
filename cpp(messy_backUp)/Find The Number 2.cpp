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
typedef pair<LL,LL> pr;

LL ar[1000], leh[1000010], tim[1000010], s;
LL chk( LL x )
{
    LL c = 0, a = 1, b, d;
    FOR(i,0,s-1)
    {
      if(tim[i]%2) c += (tim[i]*(x/leh[i]));
      else c -= ((x/leh[i])*tim[i]);
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tt;
    cin >> tt;
    FOR(t,1,tt)
    {
        LL i, j, x, y, n, m, low, high, mid, a = maxx, z;
        cin >> n >> m ;

        FOR(i,0,n-1) cin >> ar[i];

        z = 1<<n, y = 0;
        s = 0;
        FOR(i,1,z-1)
        {
           LL a = 1, b, c = 0, d, ck = 0;
           FOR(j,0,n-1)
           {
               if(i&(1<<j))
               {
                  c++;
                  b = a*ar[j];
                  d = __gcd(a,ar[j]);
                  a = b/d;
                  if( a > (LL)1000000000000000) ck = 1;
               }
           }
           if( ck == 1 ) continue;
           leh[s] = a; tim[s] = c; s++;
           //cout << c << 'k' << a << ' ' << y << endl;
        }
        a = maxx;
        low = 0; high = maxx;

        while(low<=high)
        {
            mid = (low+high)/2;
            x = chk( mid );
            //cout << mid << ' ' << x << endl;
            //cout << endl << endl;
            if(x>=m) a = min( a, mid), high = mid-1;
            else low = mid+1;
        }
        cout << a << endl;
    }
    return 0;
}



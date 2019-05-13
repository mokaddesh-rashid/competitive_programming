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

int ar[100], br[100], damn[1000010], oda[1000010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tt;
    cin >> tt;
    FOR(t,1,tt)
    {
        ///mem( ar, 0 ); mem( br, 0 ); mem( oda, 0 ); mem( damn, 0 );
        int i, j, x, y, n, m, a, b, c = 0, k, z;

        cin >> n >> k;
        b = n;
        a = n/2;
        b = n-a;

        n = a;
        FOR(i,0,n-1) cin >> ar[i];
        z = 1<<n;
        FOR(i,1,z-1)
        {
           a = 0;
           FOR(j,0,n-1)
           {
               if(i&(1<<j))
               {
                  a += ar[j];
               }
           }
           damn[i] = a;
           //cout << a << endl;
        }

        m = b;
        FOR(i,0,m-1) cin >> br[i];
        z = 1<<m;
        FOR(i,1,z-1)
        {
           a = 0;
           FOR(j,0,m-1)
           {
               if(i&(1<<j))
               {
                  a += br[j];
               }
           }
           oda[i] = a;
           //cout << a << endl;
        }

        sort( oda, oda+z );

        z = 1<<n;
        x = 1<<m;
        FOR(i,1,z-1)
        {
          if( damn[i] == k || damn[i]*2 == k ) c = 1;
          if( oda[i] == k || oda[i]*2 == k ) c = 1;

          a = k-damn[i];
          b = lower_bound( oda, oda+x, a ) - oda;
          if( a == oda[b] && b < x ) c = 1;

        }
        FOR(i,1,x-1)
           if( oda[i] == k || oda[i]*2 == k ) c = 1;

        int f, s;
        f = k/2;
        s = k/2;
        if(k%2) f++;
        int d = 0;
        FOR(i,1,z-1)
        {
          if( damn[i] == f || damn[i]*2 == f ) d = 1;
          if( oda[i] == f || oda[i]*2 == f ) d = 1;
          a = f-damn[i];
          b = lower_bound( oda, oda+x, a ) - oda;
          if( a == oda[b] && b < x ) d = 1;

        }
        FOR(i,1,x-1)
           if( oda[i] == f || oda[i]*2 == f ) d = 1;

        FOR(i,1,z-1)
        {
          if(( damn[i] == s || damn[i]*2 == s ) && d == 1) c = 1;
          if(( oda[i] == s || oda[i]*2 == s ) && d == 1) c = 1;
          a = s-damn[i];
          b = lower_bound( oda, oda+x, a ) - oda;
          if( a == oda[b] && d == 1 && b < x ) c = 1;

        }
        FOR(i,1,x-1)
           if(( oda[i] == s || oda[i]*2 == s ) && d == 1) c = 1;

        if( c == 1 ) cout << "Case " << t << ": " << "Yes" << endl;
        else cout << "Case " << t << ": " << "No" << endl;
        //cout << c << endl;
    }
    return 0;
}



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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> p_i;


//set<int>::iterator ii;

LL x, y, n, dp[10000001][2];

LL rec( LL i , LL j )
{
       if( i == 1 )
        return x;
       if( dp[i][j] != -1 )
        return dp[i][j];

       LL c = 0, b, d, temp = 0, t=0;
       if( i%2 )
          t = x;
       //cout << i << " = " <<
       dp[i][j] = min( rec( i/2, 0 )+y+t, rec( i-1, 1 )+x );
      //cout << i << ' ' << dp[i][j] << " = " << dp[i/2][0]+y+x << ' ' << dp[i-1][1]+x << endl;
    return dp[i][j];

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
   memset( dp, -1, sizeof(dp) );
    LL i, j, a, b, c, m, d = 0;

    cin >> n >> x >> y;

    d =  min( rec( n, 0 ) , rec( n+2, 0 )+x );
    d = min( rec( n+1, 0 )+x , d );//

    cout << d << endl;
    //cout <<   << endl;


    return 0;

}



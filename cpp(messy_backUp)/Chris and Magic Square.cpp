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

LL mat[1000][1000], ar[10010], br[10010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a, b, c, mx, mn, f , s, p = -1, pp;

    cin >> n ;


    for( i=0; i<n; i++ )
    {
        x = 0;
        for( j=0; j<n; j++ )
        {
           cin >> mat[i][j];
           if( mat[i][j] == 0 )
           {
               p = i;
               pp = j;
           }
           x += mat[i][j];
        }
        ar[i] = x;

        if( i == 0 )
            mx = x;
        else
            mx = max( mx, x );
    }


    y = mx - ar[p];
    mat[p][pp] = y;
    ar[p] += y;
    //cout  << ' ' << p << endl;
    a = 0;

    for( i=0; i<n; i++ )
    {
       x = 0;
       for( j=0; j<n; j++ )
       {
           x += mat[j][i];
       }
       br[i] = x;
    }

    x = 0;
    for( i=0; i<n; i++ )
    {
        x += mat[i][i];
    }
    f = x;

    x = 0;
    for( i=0, j=n-1; i<n; i++, j-- )
    {
        x += mat[i][j];
    }
    s = x;
    //cout << f << ' ' << s << endl;
    for( i=0; i<n; i++ )
    {
       // cout << ar[i] << ' ' << br[i] << endl;
        if( f == s && f == ar[i] && f == br[i] )
            continue;
        else
            a = -1;
    }


  if( n == 1 )
    cout << 1;
  else if(  a == -1 || mat[p][pp] <= 0 )
    cout << a;
  else
    cout << mat[p][pp];


    return 0;

}



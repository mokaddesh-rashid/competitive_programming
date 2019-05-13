#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009


//set<int>::iterator ii;
 long long   n, m;

int chk( long long x )
{
    long long a = x/2 - x/6, c, d, e;
    long long b = x/3 - x/6;

    c = max( n - a,(long long) 0 );
    d = max( m - b,(long long) 0 );
    e = x/6;

    if( d + c <= e )
        return 1;

    return 0;

}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long  i, j, x, y, minn = mx;

    cin >> n >> m ;


    long long st = 0, en = 20000000, mid;


    while( st <= en )
    {
      mid = ( st + en ) / 2;

      x = chk( mid );
      //cout << mid << ' ' << x << endl;
      if( x == 1 )
      {
          en = mid-1;
          minn = min( minn, mid);

      }
      else
        st = mid+1;
    }

    cout << minn ;



    return 0;

}


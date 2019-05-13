#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;

long long  b = 0, s = 0, c = 0, hb, hs, hc, db, ds, dc, tk;

long long chk( long long x )
{
    long long nb = b*x, ns = s*x, nc = x*c, a, b, c, k = tk;

    if( hb < nb )
    {
        a = nb-hb;

        if( a*db <= k )
        {
            nb = hb;
            k = k - a*db;
        }
    }
    if( hs < ns )
    {
        a = ns-hs;

        if( a*ds <= k )
        {
            ns = hs;
            k = k - a*ds;
        }
    }
     if( hc < nc )
    {
        a = nc-hc;

        if( a*dc <= k )
        {
            nc = hc;
            k = k - a*dc;
        }
    }

    if( hc < nc || hs < ns || hb < nb )
        return 0;

    return 1;

}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long i, j, x, y, n, m, st, en, mid, maxx = 0;

    string str;

    cin >> str;

    n = str.size();

    for( i=0; i<n; i++)
    {
      if( str[i] == 'B' )
            b++;
      else if( str[i] == 'S' )
            s++;
      else
            c++;

    }

    cin >> hb >> hs >> hc;

    cin >> db >> ds >> dc;

    cin >> tk;

    st = 0;
    en = 100000000000000;

   while( st <= en )
   {
       long long mid = ( st+en ) / 2;

       x = chk(mid);

       if( x == 1 )
       {
           maxx =max( mid, maxx);
           st = mid+1;
       }
       else
          en = mid-1;
     //cout << st << ' ' << mid << ' ' << en << ' ' << x << endl;
   }

   cout << maxx;



    return 0;

}



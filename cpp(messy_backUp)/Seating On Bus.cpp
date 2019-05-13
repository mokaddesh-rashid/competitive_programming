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



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, d, t;

    cin >> n >> m ;

     a = 1;
     b = 2;
     c = 2*n+1;
     d = 2*n+2;
     t = m;
     //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
     while( t > 0 )
     {
         if( c <= m )
         {
             cout << c << ' ';
             c += 2;
             t--;
         }
         if( t == 0 )
            break;
         if( a <= m )
         {
             cout << a << ' ';
             a += 2;
             t--;
         }
         if( t == 0 )
            break;
         if( d <= m )
         {
             cout << d << ' ';
             d += 2;
             t--;
         }
         if( t == 0 )
            break;
         if( b <= m )
         {
             cout << b << ' ';
             b += 2;
             t--;
         }
         if( t == 0 )
            break;



     }


    return 0;

}



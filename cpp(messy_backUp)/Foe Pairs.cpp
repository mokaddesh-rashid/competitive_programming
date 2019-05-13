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
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    set< pair<int,int> >::iterator ii;
    set< pair<int,int> >::iterator iii;
    set< pair<int,int> > yoo;

    int i, j, x, y, n, m, france = 0;

    cin >> n >> m ;

    int arr[n+1];

    for( i=0; i<n; i++)
        cin >> arr[i];

    for( i=0; i<m; i++)
    {
        cin >> x >> y;
        yoo.insert( make_pair( x , y ) );
    }

    x = 0;
    y = 0;
    while( x < n && y < n )
    {
       //cin >> x >> y;


       ii = yoo.find( make_pair( arr[y+1] , arr[y] ) );
       iii = yoo.find( make_pair( arr[y] , arr[y+1] ) );

       if(ii == yoo.end() && iii == yoo.end() && y < n-1 )
      {
       		y++;
      }
      else
      {
          cout << y << endl;
          while( x < y )
          {
              france += (y-x);
              x++;
          }
          cout << x << endl;
          y++;
          x++;
      }

    }

    cout << france;

//    for( )






    return 0;

}


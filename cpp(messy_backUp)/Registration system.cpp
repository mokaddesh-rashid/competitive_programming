
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
#define sf       scanf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

   // INP;
    //OUT;

    int i, j, x = 0, y, n, m, a;

    cin >> n ;

    string str[n], chk;
    int arr[100010] = {0};

    for( i =0; i<n; i++ )
      {
          cin >> chk;

          a = 0;

          for( j=0; j<x; j++)
          {
              if( str[j] == chk )
              {
                  a = 1;
                  cout << chk << ++arr[j] << endl;
                  break;
              }
          }
          if( a == 0 )
          {
              str[x] = chk;
              x++;
              cout << "OK" << endl;
          }
      }


    return 0;

}


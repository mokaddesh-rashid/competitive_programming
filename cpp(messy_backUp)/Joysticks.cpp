#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x = 0, y, n, m;

    cin >> n >> m ;


     while( n > 0 && m > 0 )
     {
         if( n == 1 && m == 1 )
            break;


         if( n < m )
         {
             n++;
             m -= 2;
         }
         else
         {
             m++;
             n -= 2;
         }

         x++;
     }

     cout << x;

    return 0;

}


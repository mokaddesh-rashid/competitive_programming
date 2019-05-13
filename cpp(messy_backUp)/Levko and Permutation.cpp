#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, k, i, a, b, x, y;

    cin >> n >> k;

    x = k;
    y = n - k;

    if( n == k )
        cout << -1;
    else
    {
       for( i=1; i<=n; i++)
       {
           if( k+1 == n )
           {
               cout << i;
           }
           else if( x == 1 )
           {
               if( i == n-1 )
                    cout << 1;
               else if( i == n )
                    cout << n;
               else
                     cout << i+1;
           }
           else if( x == 0 )
           {
               if( i == n )
                    cout<<1;
               else
                     cout << i+1;
           }
           else if( i <= y )
           {
               if( i == y )
                cout << 1;
               else
                 cout <<i+1;
           }
           else
              cout << i;



            cout<<' ';

       }
    }




}


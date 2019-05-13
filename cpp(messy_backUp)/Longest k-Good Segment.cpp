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

    int n, k;

    cin >> n >> k;

    int arr[n+1], save[1000000+1] ={0}, i, j, a=0, b=-1, x=0, y, z, maxx = -1;

    for( i=0; i<n; i++)
        cin >> arr[i];


    while( b < n-1 && a < n )
    {
       if( x <= k )
       {
           b++;
           if( save[arr[b]] == 0 )
              x++;
           save[arr[b]]++;
           //cout << b <<endl;
           if( maxx < b-a && x <= k && b < n )
       {
           maxx = b-a;
           y = a+1;
           z = b+1;
       }

       }
       else
       {
          save[arr[a]]--;
          if( save[arr[a]] == 0 )
             x--;
           a++;
       }

       //cout << a <<' '<<b << endl;


    }
    cout << y << ' ' << z ;



}


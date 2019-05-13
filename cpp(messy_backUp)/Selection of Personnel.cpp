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

    long long int i, j, x = 1 , y = 1, n, m, a = 5, b = 6, c = 7, arr[11], brr[11];

    cin >> n;

    m = n;

    while( x <= 8  )
    {
        y =(long long) y*m;

        arr[x] = (long long) y;

        m--;
        x++;


    }


    x = 1;

    for( i=1; i<8 ; i++)
    {
        brr[i] = (long long) x;

        x = (long long) (x * (i+1));
    }

     x = 0;
     i = 5;

     while( i<= 7 )
     {
         a = (long long) arr[i];

         b = (long long) brr[i];

         c =  (long long) a / b;

         x = (long long) x + c;
         i++;
     }

     cout << x;


    return 0;

}


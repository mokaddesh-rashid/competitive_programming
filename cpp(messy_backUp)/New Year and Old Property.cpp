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

    long long int i, j, a, b, x=0, y=0, arr[111], brr[111], c, d, ou = 0, bi_f[111], bi_l[111];

    cin >> a >> b;

    if( a==1 && b==2)
        cout<< 1;

    else
    {
        while( a > 0 )
    {
        arr[x] = a%2;
        a /= 2;
        x++;
    }
    c = x-1;
    for( i=0 ; i<x; i++,c--)
    {

        bi_f[i] = arr[c];
        //cout << bi_f[i]<<' ';
    }

    while( b > 0 )
    {
        brr[y] = b%2;
        b /= 2;
        y++;
    }

    //cout << endl;

      c = y-1;
    for( i=0 ; i<y; i++,c--)
    {
        bi_l[i] = brr[c];
         //cout << bi_l[i]<<' ';
    }

    if( x != y )
    {

    c = x+1;

    while( c < y )
    {
        ou += (c-1);
        c++;
    }

    a = 0;

    for( i=0; i<x; i++)
    {
        if( bi_f[i] == 0 )
            a = 1;
        ou += a;
    }

    a = 1;
    for( i=1; i<y; i++)
    {
        //cout << bi_l[i]<<' ';
        if( bi_l[i] == 0 )
            a = 0;
        ou += a;

    }

    cout << ou;

    }

    else
    {
       for( i=1 ; i<x; i++)
       {
           b = 0;
           for( j=0 ; j<x; j++)
           {
               if( j == i )
               {
                   a = 0;

               }
               else
                a = 1;

                if( a < bi_f[j] )
                     b = 1;
                if( a > bi_l[j] )
                    b = 1;
           }

           if( b == 0 )

             ou++;
       }

       cout << ou;
    }
    }





}

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

    int arr[111111], st[111111] = {0}, x = 0, y = 0, top = 0, i, a, b, c, d;

    string str;

    getline( cin, str );

    for( i=0; i < str.size(); i++ )
    {
        a = str[i] - 48;

        if( a >= 0 && a <= 9 )
        {
            if( x == 0 )
                x = a;
            else
            {
                x *= 10;
                x += a;
            }
        }
    }

    for( i=0; i < str.size(); i++ )
    {
        if( str[i] == '?' )
        {
            arr[ top ] = 0;
            top++;

        }
        else if( str[i] == '+' )
        {
            arr[ top ] = -1;
            top++;
        }
        else if( str[i] == '-' )
        {
            arr[ top ] = -2;
            top++;
        }
        else if( str[i] == '=' )
            break;
    }

    a = 0;
    for( i=0; i < top; i++ )
    {
        if( arr[i] == 0 &&  i == 0  )
        {
            arr[i] = 1;
            a += 1;

        }
        else if( arr[i] == 0 &&  arr[i-1] == -1  )
        {
            arr[i] = 1;
            a += 1;

        }
        else if( arr[i] == 0 &&  arr[i-1] == -2  )
        {
            arr[i] = 1;
            a -= 1;

        }
    }

    if( a < x )
    {

        for( i=0; i < top; i++ )
    {
        if( a == x )
            break;

        if(   i == 0  )
        {
            b = x - arr[i];
            c = x - a;

            if( c > b )
            {
               arr[i] = x;
               a += b;
            }
            else
            {
                arr[i] = c+arr[i];
                a = x;
            }

        }
        else if( arr[i-1] == -1  )
        {
            b = x - arr[i];
            c = x - a;

            if( c > b )
            {
               arr[i] = x;
               a += b;
            }
            else
            {
                arr[i] = c+arr[i];
                a = x;
            }

        }
    }

    }

    else if( a > x )
    {

        for( i=0; i < top; i++ )
    {
         if( a == x )
            break;
         if(  arr[i-1] == -2  )
        {
            b = x - arr[i];
            c = a - x;

            if( c > b )
            {
               arr[i] = x;
               a -= b;
            }
            else
            {
                arr[i] = c+arr[i];
                a = x;
            }

        }
    }

    }

     if( a == x )
     {
         cout << "Possible\n";
         for( i=0; i<top; i++ )
        {
            if( arr[i] == -1 )
                cout << '+' << ' ';
            else  if( arr[i] == -2 )
                cout << '-' << ' ';
            else
                cout << arr[i] << ' ';
        }
        cout << ' ' << '=' << ' ' << x << endl;
     }

     else
        cout << "Impossible\n";
    return 0;

}




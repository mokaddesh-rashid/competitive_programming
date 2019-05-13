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

    long long int a, b, n, i, j, arr[11]={0}, brr[11]={0}, x=0;

    cin >> a >> b;

    while(true)
    {
        if( a%2 == 0 )
        {
            arr[1]++;

            a /= 2;
        }
        else if( a%3 == 0 )
        {
            arr[2]++;

            a /= 3;
        }

        else if( a%5 == 0 )
        {
            arr[3]++;

            a /= 5;
        }

        else
            break;
    }

    while(true)
    {
        if( b%2 == 0 )
        {
            brr[1]++;

            b /= 2;
        }
        else if( b%3 == 0 )
        {
            brr[2]++;

            b /= 3;
        }

        else if( b%5 == 0 )
        {
            brr[3]++;

            b /= 5;
        }

        else
            break;
    }

    //cout <<a <<' '<<b<<endl;

    if( a!= b )
        cout << -1;

    else
    {
        x += (max(arr[1],brr[1])-min(arr[1],brr[1]));
        x += (max(arr[2],brr[2])-min(arr[2],brr[2]));
        x += (max(arr[3],brr[3])-min(arr[3],brr[3]));

        cout << x;

    }






}


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

    long long int n;

    cin >> n;

    long long int i, j, a = -1, b =0 , c = 0, arr[n+1];


    for( i=0; i<n; i++)
    {
        cin >> arr[i];

        if( a == -1 )
            a = arr[i];
        else
            a = min(arr[i],a);
    }

    for( i=0; i<n; i++)
    {
       if( arr[i]>a)
            c++;
       else
           c=0;

       b = max(b,c);
    }
    for( i=0; i<n; i++)
    {
       if( arr[i]>a)
            c++;
       else
           break;

       b = max(b,c);
    }

     a = (long long ) a*n;
     a = a+b;

    cout << a;








}


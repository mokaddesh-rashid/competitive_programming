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

    int t, ca=1;

    cin >> t;

    while(t--)
    {
        long long int p, l, q, x=0, i, j, a, b, c;

    cin >> p >> l;

    //cout << p << ' '<< l <<endl;
    q = p - l;
    a = sqrt(q);

    long long int arr[2*a+1];

    //cout << q<<endl;

    for( i=1; i<= a; i++)
    {
        if( q%i == 0 )
        {
            b = i;
            c = q/i;

            if( b > l )
            {
                arr[x] = i;
                x++;
            }
            if( c > l && b != c )
            {
                arr[x] = c;
                x++;
            }
        }
    }

    sort(arr,arr+x);

    if(x==0)
        cout<<"Case "<<ca<<": impossible\n";

    else
    {
         cout<<"Case "<<ca<<": ";
         for( i=0; i<x; i++)
           {
               if( i < x-1 )
                cout <<arr[i] <<' ';
               else
                cout <<arr[i] << endl;
           }
    }
    ca++;

    }


}


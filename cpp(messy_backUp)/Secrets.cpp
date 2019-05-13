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

    long long int i, j, a=1, b=1, c=1;


    while( b<n )
    {
        b *= 3;

        if( n % b)
        {
            a= (n/b)+1;
            break;
        }

    }


    cout << a;






}


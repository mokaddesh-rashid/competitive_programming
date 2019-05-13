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

    long long int arr[100000+9]={0}, i, j, a, b, c, x=0, k;

    cin >> a >> b >> c;

    for( i=1; i<=100000 ;i++)
    {
        j = i;

        while(j<=100000)
        {
            arr[j]++;
            j += i;
        }
    }

    for( i=1; i<=a; i++)
        for( j=1; j<=b; j++)
           for( k=1; k<=c; k++)
    {
        x += arr[i*j*k];

        x %= (long long) 1073741824;
    }

    cout << x;





}


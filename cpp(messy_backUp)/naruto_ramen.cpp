#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t, ca=1;

    cin >> t;

    while( t-- )
    {
        int n;

    cin >>  n;

    int  i, j, x=0, a, b, k, d;


    for( i=0; i<n; i++)
    {
        cin >> a;

        x += a;
    }

    cin >> k >> d;

    x = x*d;

    x = max( x-k, 0);

    cout<<"Case "<<ca<<": "<< x<<endl;
    ca++;

    }



}



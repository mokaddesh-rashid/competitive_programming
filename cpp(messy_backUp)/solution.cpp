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
        int n;

    cin >>  n;

    int arr[100000+2] = { 0 }, i, j, x=0, a, b, maxx=-1;


    for( i=0; i<n; i++)
    {
        cin >> a;

        arr[a]++;
        arr[a/2]--;

        maxx = max( a, maxx);
    }

    for( i=0; i <= maxx ; i++)
    {
        x += arr[i];

        if(x < 0)
            x=0;
    }

    cout <<"Case "<<ca<<": "<< x <<endl;
    ca++;
    }



}


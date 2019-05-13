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

    int n, minn = 100001, a, b=0, i, x=0;

    cin >> n;

    for( i=0; i<n; i++)
    {
        cin >> a;

        minn = min(a,minn);
    }


    cin >> n;

    int arr[n+1], j,  y, z;

    for( i=0; i<n; i++)
    {
        cin >> arr[i];
    }



    sort(arr,arr+n,greater<int>());

    for( i=0; i<n; i++)
    {
        x += arr[i];
        b++;

        if(minn == b)
        {
            i += 2;
            b = 0;
        }
    }

    cout << x;





}


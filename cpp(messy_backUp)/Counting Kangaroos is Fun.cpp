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

    int n;

    cin>>n;

    int zer0[100000+1], arr[n+1], i, j, a, b, x=0, y, z, maxx=-1, minn=100000+1, m;

    for( i=0; i<n; i++)
    {
       cin >> arr[i];


    }

    sort(arr,arr+n);

    j=n/2;
    i=0;
    m=n;

    while(i<n/2&&j<n)
    {
        if(arr[i]*2<=arr[j])
        {
            m--;
            i++;
            j++;
        }

        else
        {
            j++;
        }
    }

    cout<<m;


}


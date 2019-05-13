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

    cin >> n;

    int arr[100000+5]={0} ,i ,j , a, b=1, maxx=1;

    for( i=0; i<n; i++)
    {
        cin >> a;

        arr[a] = i+1;
    }

    for( i=2; i<=n; i++)
    {
        if(arr[i]>arr[i-1])
            b++;

        else
           b = 1;

        maxx = max(maxx,b);
    }

    cout<<n-maxx;




}


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

    long long int i, j, n, m;

    cin >> n >> m;

    long long int arr[n+1], brr[m+1], x, y, a, b, c;

    for(i=0; i<n; i++)
    {
       cin >> arr[i];
    }

    sort(arr,arr+n);


    vector<long long int> v(arr,arr+n);
    vector<long long int>::iterator low,up;

    for( i=0; i<m; i++)
    {
        cin >> a;
        up= upper_bound (v.begin(), v.end(), a);

        cout <<  (up - v.begin()) << ' ';
    }





}


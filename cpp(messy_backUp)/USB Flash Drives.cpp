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


    int n,m;

    cin >> n >> m;

    int arr[n+1],i,j,a=0,b=0,c;

    for( i=0; i<n ; i++)
        cin >> arr[i];

    sort(arr,arr+n, greater<int>());

    while( a < m )
    {
        a += arr[b];
        b++;
    }
   // cout << a<<endl;
    cout << b;


}


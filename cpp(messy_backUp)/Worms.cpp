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

    long long int i, j, x=0, y, n, m, a;

    cin >> n;

    long long int arr[n+1];

    for( i=0; i<n; i++)
    {
        cin >> a;

        x += a;

        arr[i] = x;
    }


    vector<int> v(arr,arr+n);
    vector<int>::iterator low,up;
    cin >> m;

   for( i=0; i<m ; i++ )
   {
       cin >> y;

       up= std::upper_bound (v.begin(), v.end(), y-1);//upper_bound ( arr, arr+n, y-arr);

       cout << up - v.begin() +1 << endl;
   }

    return 0;

}

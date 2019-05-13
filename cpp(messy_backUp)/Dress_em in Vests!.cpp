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

    long long int n, m, x, y;

    cin >> n >> m >> x >> y;

    int arr[n+1] , brr[m+1], i, j, a=0, b=0, c=0, ans[m+1], wi[m+1], z=0;

    for( i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for( i=0; i<m; i++)
    {
        cin >> brr[i];
    }

    for( i=0; i<n; i++)
    {
        b = arr[i];

        while( a < m )
        {
            if( b + y < brr[a] )
                break;
            else if( b - x <= brr[a] && b + y >= brr[a] )
            {
                ans[c] = a+1;
                wi[c]  = i+1;
                c++;
                a++;
                break;
            }
            else
                a++;
        }


    }

    cout << c << endl;

    for( i=0 ; i<c; i++)
        cout << wi[i] << ' '<<ans[i]<<endl;





}


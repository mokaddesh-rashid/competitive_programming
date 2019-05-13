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

    long long int n, k, kk;

    cin >> n >> k;

    kk = k;

    long long int arr[n+1][4], i, j, a = 0, b, c, use[2222] = {0}, maxx=-1, pos, x=0, us[2222] = {0}, y=0;


    for( i=0; i<n ;i++)
    {
        for( j=0; j<3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for( i=0; i<n ;i++)
    {
        maxx = -1;
        pos = -1;
        for( j=0; j<n; j++)
        {
            if( arr[j][0] != a && arr[j][1] <= k && use[j] == 0 )
            {
                if( maxx < arr[j][2] )
                {
                    pos = j;
                    maxx = arr[j][2];
                }
            }
        }

        if( maxx != -1)
        {
           a = arr[pos][0];
           x++;
           k += maxx;
           use[pos]++;
        }
    }
    a = 1;

    for( i=0; i<n ;i++)
    {
        maxx = -1;
        pos = -1;
        for( j=0; j<n; j++)
        {
            if( arr[j][0] != a && arr[j][1] <= kk && us[j] == 0 )
            {
                if( maxx < arr[j][2] )
                {
                    pos = j;
                    maxx = arr[j][2];
                }
            }
        }

        if( maxx != -1)
        {
           a = arr[pos][0];
           y++;
           kk += maxx;
           us[pos]++;
        }
    }

    cout << max(x,y);



}

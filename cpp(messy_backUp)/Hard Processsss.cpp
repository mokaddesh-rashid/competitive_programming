#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m, st, k, l, a, b, c;

    cin >> n >> k ;

    int arr[n+1], brr[n+1];

    for( i=0; i<n; i++ )
    {
        cin >> arr[i];
    }

    for( i=0; i<n; i++)
    {
        if( arr[i] == 0 )
        {
            x++;
        }

        brr[i] = x;
        //cout << brr[i] << ' ';
    }

    //cout << endl;
    int maxx = 0;

    for( i=0; i<n; i++ )
    {

       if( i == 0 )
       {
           a = upper_bound( brr, brr+n, k ) - brr;
       }
       else
       {
           a = upper_bound( brr, brr+n, brr[i-1]+k ) - brr;
       }

       if( a-i > maxx )
       {
           maxx = a-i;
           st = i;
       }
      // cout << i << ' ' << a << endl;
    }

    a = 0;

    cout << maxx << endl;

    for( i=0; i<n; i++)
    {
        if( i == st )
        {
            a = 1;
        }

        if( a == 1 && arr[i] == 0 && k > 0 )
        {
            arr[i] = 1;
            k--;
        }

        cout << arr[i]  << ' ';
    }






    return 0;

}



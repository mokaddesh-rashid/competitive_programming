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


//set<long long >::iterator ii;

long long  arr[2000000], brr[2000000];



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long  i, j, x = 0, y, n, m, k, maxx = 0, ans = 0;

    cin >> n >> k ;



    for( i=0; i<n; i++ )
        cin >> arr[i];

    sort( arr, arr+n );

    for( i=0; i<n; i++ )
        {
            //cout << arr[i] << ' ';
            x += arr[i];
            brr[i] = x;

        }
    //9cout << endl;

    i = 0;

    while( i < n )
    {
        long long  up  = upper_bound( arr, arr+n, arr[i]) - arr;

        long long  st = 0, en = i, mid, a, b, low = n+1;

        while( st <= en )
        {
            mid = ( st+en ) / 2;
            a = ( i - mid )*arr[i];
            b = ( brr[i-1] - brr[mid-1] );

            if( a-b <= k )
            {
                low = min( mid, low );
                en = mid-1;
            }
            else
                st = mid+1;
           // cout << a << ' ' << b << ' ' << mid << endl;

        }
        if( low == n+1 )
            low = i;

        if( up - low > maxx )
        {
            maxx = up - low;
            ans = arr[i];
        }
        //cout << arr[i] << ' ' << up << ' ' << low << endl << endl << endl;

        i = up;


    }

    cout << maxx << ' ' << ans << endl;


    return 0;

}



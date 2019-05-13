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

int st[100000+10], arr[100000+10];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, z , t = 0;

    cin >> n ;

    for( i=0; i<n; i++ )
        cin >> arr[i];
    sort( arr, arr+n );
    x = 0;
    y = n/3;
    z = y+y;

    a = 0;
    b = z-1;
    c = n-1;

    while( a < y && b < y && c < n )
    {
        while( arr[a] == arr[b] )
        {
            b++;
        }
        while( arr[b] == arr[c] )
        {
            c++;
        }

        if( arr[a] < arr[b] && arr[b] < arr[c] )
            t++;
        a++;
        b++;
        c++;
    }

     cout << t << endl;
     a = 0;
     b = n/3;
     c = b+b;
     x = b;
     y = c;

     while( a < x && b < y && c < n )
    {
        while( arr[a] == arr[b] )
        {
            b++;
        }
        while( arr[b] == arr[c] )
        {
            c++;
        }

        if( arr[a] < arr[b] && arr[b] < arr[c] )
            cout << arr[c] << ' ' << arr[b] << ' ' << arr[a] << endl;
        a++;
        b++;
        c++;
    }



    return 0;

}



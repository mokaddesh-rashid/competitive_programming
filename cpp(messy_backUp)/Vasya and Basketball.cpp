#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define sl(n)       scanf("%I64d", &n)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //INP;
    //OUT;

    long long int i, j, x, y, n, m, mx = (long long) -1000000000000000, a, b, c, d, ss, ff;

    //cin >> n ;
          sl(n);
    int arr[n+1];

    for( i=0; i<n; i++)
        sl(arr[i]);

         sl(m);

    int brr[m+1];

    for( i=0; i<m; i++)
       sl(brr[i]);



    sort( arr, arr+n);
    sort( brr, brr+m);

    i = 0;
    j = 0;

    while( i < n && j < m )
    {

        if ( arr[i] > brr[j] )
            {
                while( arr[i] > brr[j] && j <  m )
            {
                j++;
            }

            }

        x = i;
        y = n - x;

        a = x*2 + y*3;
        //cout << x << ' ' << y << endl;

       // cout << a << ' ' << endl;

        x = j;
        y = m - x;

        b = x*2 + y*3;
       // cout << x << ' ' << y << endl;
       // cout << b << endl << endl;

        if( mx < a-b )
        {
            ff = a;
            ss = b;
            mx = a-b;
        }

        i++;



    }

    if( n*2 - m*2 > mx )
    {
        ff = n*2;
        ss = m*2;
    }

    pf("%lld:%lld", ff,ss);



    return 0;

}


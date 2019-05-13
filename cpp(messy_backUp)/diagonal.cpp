#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <limits>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int i, j, x, y, n, m, p, t, z;

    cin >> n >> p;

    int arr[n+1], brr[n+1], f[n+1], s[n+1], a=0, b=1, c;


    for( i=0; i<n; i++)
    {
        cin >> arr[i] >> brr[i];

        x = brr[i] - arr[i] + 1;

        y = arr[i] - 1;

        z = brr[i];

        y /=  p;
        z /= p;

        t = z - y;

        f[i] = t;
        s[i] = x-t;

        b *= x;

        //cout << f[i] << ' ' << s[i] <<endl;

    }

    a=0;

    for( i=0; i<n; i++)
    {
        if( i<n-1)
          {
              x = f[i]*( brr[i+1]-arr[i+1]+1);
              y = s[i]* f[i+1];
              //cout << x << ' ' <<y <<endl;
              a += x;
              a += y;
          }

          else
          {
              x = f[i]*( brr[0]-arr[0]+1);
              y = s[i]* f[0];
              //cout << x << ' ' <<y <<endl;
              a += x;
              a += y;

          }
    }


     //cout <<
     a *= 2000;
     a *= 2;
     //cout << a <<' ' << b<< endl;



    long double ans, dd;

    ans = a;

    dd = b;

    //cout << ans << ' ' << dd << endl;

    ans = ans/dd;

    //cout << ans << endl;


    cout.precision(7);
    cout <<  fixed << ans << endl;
   // cout << setprecision (7) << ans << endl;



    return 0;

}


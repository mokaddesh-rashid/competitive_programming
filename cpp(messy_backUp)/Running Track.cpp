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

    string s, t;

    cin >> s >> t;

    int n = s.size(), m=t.size(), i, j, a=0, b=0, x=0, arr[2222], brr[2222], y, z, bg, en, pos = 0, cou=0, maxx;

    while ( pos < m )
    {
    cou = 0;
    bg = -1;
    maxx = 0;
    y = -1;
    z = -1;
    x = pos;
    for( i=0; i<n; i++)
    {
        if( s[i] == t[x])
        {
            if( cou == 0 )
                bg = i+1;

            en = i+1;
            cou++;
            x++;
        }
        else if( s[i] == t[pos])
        {
            cou = 0;
            x = pos;

            if( cou == 0 )
                bg = i+1;

            en = i+1;
            cou++;
            x++;
        }
         else
            {

                cou = 0;
                x = pos;
            }

        if( cou > maxx )
        {
            y = bg;
            z = en;
            maxx = cou;
        }
    }

     x = pos;
     cou = 0;
    for( i=n-1; i>=0; i--)
    {
        if( s[i] == t[x])
        {
            if( cou == 0 )
                bg = i+1;

            en = i+1;
            cou++;
            x++;
        }
        else if( s[i] == t[pos])
        {
            cou = 0;
            x = pos;

            if( cou == 0 )
                bg = i+1;

            en = i+1;
            cou++;
            x++;
        }
        else
            {

                cou = 0;
                x = pos;
            }

        if( cou > maxx )
        {
            y = bg;
            z = en;
            maxx = cou;
        }
    }

    pos += maxx;
    //cout <<

    if( y == -1 )
    {
       b = 1;
       break;
    }
    else
    {
      arr[a] = y;
      brr[a] = z;
      a++;
    }
    }

    if( b == 1)
        cout <<-1;
    else
    {
        cout << a << endl;
        for( i=0; i<a; i++)
            cout<< arr[i] << ' '<<brr[i]<<endl;
    }






}

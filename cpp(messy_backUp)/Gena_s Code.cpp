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

    string  str, ans = "\0";

    //cout << ans.size();

    int i , n, a=0, b=0, c=0, x = 0, y, z, j, m, d, e;


    cin >> n;

    for( i=0; i<n; i++)
    {
        cin >> str;

        m = str.size();
        c = 0;
        d = 0;
        e = 0;

        for( j=0; j<m; j++)
         {
            if( j == 0 && str[j] == '0' )
            {
                b = 1;
            }
            else  if( str[j] == '0' )
                    c++;
            else if( str[j] == '1' )
                    d++;
            else
            {
                ans = str;
                e = 1;
                break;
            }

            if( d == 2 )
            {
                ans = str;
                e = 1;
                break;
            }
        }

        if( e == 0 )
            x += c;

    }

    if( b == 1 )
        cout << 0;
    else if( ans.size() == 0 )
    {
        cout << 1;

        while( x-- )
        {
            cout << 0;
        }
    }

    else
    {
        cout << ans;
        while( x-- )
        {
            cout << 0;
        }

    }




   return 0;
}


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

    string str, ss;

    cin >> str >> ss;

    int i, j, a=0, b=0, x=0, y=0, n=0, m, mm;

    n = max(str.size(),ss.size());

    m = str.size();
    mm = ss.size();
    a = m;
    b = mm;

    for( i=0; i<m; i++ )
    {
        if( str[i] != '0' )
           {
            a = i;
            break;
           }

    }
    for( i=0; i<mm; i++ )
    {
        if( ss[i] != '0' )
           {
            b = i;
            break;
           }
    }

    //cout << a <<' '<<b<<endl;
    for( i=0; i<n; i++, a++,b++ )
    {
        if( str[a] > ss[b] && x == 0)
            {

                x = 1;
            }
        if( str[a] < ss[b] && x == 0)
            {
                 //cout << str[a] <<' ' << ss[b];
                x = 2;
            }

        if( a == m && b == mm)
            break;
        else if( a == m )
        {
            x = 2;
            break;
        }
        else if( b == mm )
        {
            x = 1;
            break;
        }
    }

    if( x ==0 )
        cout << '=';
    else if( x == 1 )
        cout << '>';
    else
        cout << '<';






}


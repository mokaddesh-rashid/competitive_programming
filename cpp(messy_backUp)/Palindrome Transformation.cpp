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



    int i, j, a, b, c, x=0, y=0, n, m, d, s=-1, e=-1;

    cin >> n >> m;
    m--;

    string str;

    cin >> str;

    if(m >= str.size()/2 )
    {
        m = str.size() - m - 1 ;
    }

    //cout << m <<endl;


    for( i=0; i<str.size()/2; i++)
    {
        if( i < str.size() / 2 )
        {
        a = str[ i ] ;
        b = str[str.size()-i-1];

        c = max( a-b , b-a );

        d = 26-c;

        x += min(c,d);
        }

        if( s == -1 && a != b  )
            s = i;
        if( a != b )
            e = i;

         //cout << str[i] << ' ' << str[str.size()-i-1] << a <<' ' <<b<<' '<<c<<' '<<d<<endl;

    }
    // cout << x << endl;
     a = m - s  ;
     b = e - m ;

     if( s == -1 && e == -1)
         cout << x;
     else if( s < m && e == m)
         cout << x+m-s;
     else if(  e == m)
         cout << x;
     else if( m > e )
        cout << x+a;
     else if( m < s )
        cout << x+b;
     else
        cout << x+min(a,b)+min(a,b)+max(a,b);

   // cout << m - s -1 <<endl;
   // cout << e - m +1 <<endl;




}


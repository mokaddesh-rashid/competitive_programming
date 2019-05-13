#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

//set<int>::iterator ii;

using namespace std;

int n;
string str;

int direc( int x, int y )
{
    while( x < y )
    {
        x++;
        y--;
        if( y == -1 )
            y = n-1;
        if( x == n )
            x = 0;
        if( str[x] == 'h' )
            return 0;
        if( str[y] == 'h' )
            return 1;
    }

    return 0;
}

int main()
{

    ios::sync_with_stdio(false);

    int i, j, x = 0, y,  m, a, b, t, st = 0 , en = 0, l , r, c , d;

    cin >> n >> a >> b >> t ;

    cin >> str;

    while( t > 0 && x < n )
    {
       if( st == en )
       {
           //cout << 'h';
           if( str[st] == 'w' )
           {
               t -= (b+1);
           }
           else
           {
               t--;
           }

           st++;
           en--;
       }
       else if( str[st] == 'h' )
       {
           st++;
           t--;
       }
       else if( str[en] == 'h' )
       {
           en--;
           t--;
       }

       else
       {
            //cout << "HH";
           int di = direc( st, en);
            //cout << di << ' ' << t << endl;
           if( di == 0 )
           {
                while( t > 0 && x < n && str[st] != 'h' )
                {
                   t -= (b+1);
                   st++;
                   if( t >= 0 )
                       x++;
                   if( st == n )
                       st = 0;

                    t -= a;
                }
           }
           else
           {
               while( t > 0 && x < n && str[en] != 'h' )
                {
                   t -= (b+1);
                   en--;
                   if( t >= 0 )
                       x++;
                   if( en == -1 )
                      en = n-1;

                   t -= a;
                }
           }
       }

        if( en == -1 )
            en = n-1;
        if( st == n )
            st = 0;


       if( t >= 0 )
           x++;

       t -= a;
    }

    cout << x << endl;

    return 0;

}


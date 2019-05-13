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
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)


//set<int>::iterator ii;

int n, m, a, b, c;

int rec( int x , int y )
{
   if( x == 0 && y == a )
        return 1;
   if( x <= 0 )
        return 0;
   else
   {
       int temp = rec( x-1, y-1) + rec( x-1, y+1);

       return temp;
   }
}



int main()
{
    ios::sync_with_stdio(false);

   // INP;
    //OUT;

    int i, j;

    a = 0;
    b = 0;
    n = 0;

    string str;

    cin >> str;

    for( i=0; i<str.size(); i++)
    {
        if( str[i] == '+' )
            a++;
        else
            a--;
    }

     cin >> str;

    for( i=0; i<str.size(); i++)
    {
        if( str[i] == '+' )
            b++;
        else if( str[i] == '-' )
            b--;
        else
            n++;
    }

    //cout << n << ' ' << b << endl;

    int x , y = 1;
    x = rec( n, b);

    double d;



    for( i=0; i<n; i++)
          y *= 2;
    pf( "%.10lf",(double)x/y );
   // cout << (double)x/y ;







    return 0;

}



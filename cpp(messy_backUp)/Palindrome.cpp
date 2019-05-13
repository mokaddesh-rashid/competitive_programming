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
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000

string str;
//set<int>::iterator ii;

int chk( int x, int y )
{
    while( x < y )
    {
        if( str[x] != str[y] )
            return 0;

        x++;
        y--;
    }

        return 1;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a = 0;

    cin >> str;

    n = str.size();
    m = n-1;
    while( m >= 0 )
    {
       i = 0;

       while( i+m < n )
       {
           a = chk( i, i+m);

           if( a == 1 )
            break;
            i++;
       }

       if( a == 1 )
       {
           for( j=i; j<=i+m; j++)
            cout << str[j];
            break;
       }
       m--;

    }



    return 0;

}



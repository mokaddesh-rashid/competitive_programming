
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
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;

long long n;

long long rec( long long x ,long long z, long long y )
{
    if( y >= n && x == z)
        return y;
    if( n*1000 < y )
        return mx;
    else
    {
        if( y == 0 )
        {
            long long temp = min( rec( x+1, z, (long long)4) , rec( x, z+1,(long long)7) );
            return temp;
        }
        else
        {
             long long temp = min( rec( x+1, z, y*10+4) , rec( x, z+1,y*10+7) );
             return temp;
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long i, j, x, y, m;

    cin >> n ;

    x = rec( 0, 0 , 0);

    cout << x;



    return 0;

}



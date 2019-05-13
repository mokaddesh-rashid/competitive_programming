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
#define mod          1000000009


//set<int>::iterator ii;

int arr[11][11], n, t ;

int rec( int x, int y, int z )
{
    int ans= 0;
    if( t == 1 )
        {
            cout << "b";
            return 0;
        }
    if( z == n*n )
        return 1;
    if( x < 0 )
        return 0;
    if( x >= n )
        return 0;
    if( y < 0 )
        return 0;
    if( y >= n )
        return 0;
    if( arr[x][y] == 1 )
        return 0;

    else
    {
        arr[x][y] = 1;
        int temp = 0;
        temp = max( temp , rec( x-2,y-1,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x-2,y+1,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x-1,y-2,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x-1,y+2,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x+2,y+1,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x+2,y-1,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x+1,y+2,z+1) );
        t = max( t, temp );
        temp = max( temp , rec( x+1,y-2,z+1) );
        t = max( t, temp );

        arr[x][y] = 0;

        ans = temp;
        t = max( t, temp );

    }
    if( t == 1 )
    {
        char ch;

        ch = x+97;

        cout << ch<<y+1 << endl;
    }
    return ans;
}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    t = 0;
    int i, j, x, y,  m;

    cin >> n ;

    memset( arr, 0, sizeof(arr));

    x = rec( 0, 0, 0 );

    if( x == 0 )
        cout << "IMPOSSIBLE\n";

    return 0;

}



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

int n;

long long lower( long long arr[], long long st, long long en, long long val)
{
    long long mid;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        if( arr[mid] == val )
            en = mid - 1 ;

        else if( arr[mid] > val )
            en = mid - 1 ;

        else if( arr[mid] < val )
            st = mid + 1 ;
    }

    return st;
}

 string str;

int chk ( int i)
{
    int x = i;
    int y = i;

    while( x >= 0 && y <= n )
    {
        if( str[x] == '0' )
            return x;
        if( str[y] == '0' )
            return y;
        x--;
        y++;

    }

}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    long long  i, j, x = 0, y = 0, m, k, minn = 11111111, rm, a;

    cin >> n >> k ;



    cin >> str;

    long long arr[100000+10] = {0};

    rm = 0;

    while( y < n )
    {
        if( str[y] == '0' )
            rm++;

        arr[y] = rm;
        y++;

    }

    for( i=0; i<n; i++)
    {
        if( i == 0)
              x = lower( arr, 0, n-1, k+1 );
        else
              x = lower( arr, 0, n-1, arr[i-1]+k+1 );
       // cout << i << ' ' << x << ' ' << a << endl;

         if( ( arr[x] - arr[i-1] >= k || i == 0 ) && (x+i)/2 - i < minn )
         {
           a = chk((x+i)/2 );

         minn = min( minn, max( a-i, x-a) );
          a = chk((x+i)/2+1 );

         minn = min( minn, max( a-i, x-a) );


         }

    }


    cout << minn;




    return 0;

}

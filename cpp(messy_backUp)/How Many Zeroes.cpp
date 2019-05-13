
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

long long dp[20][20], arr[22], n;

string str;

long long rec( int x , int y, int z )
{
    if( x == n )
        return 0;

//    else if( z = 0 )
//    {
//        int temp = 0;
//
//        for( int i=0; i <=arr[x]; i++ )
//        {
//            if( arr[x] > i )
//            {
//                temp += rec( x+1, 1 );
//            }
//            else
//            {
//                temp += rec( x+1, 0 );
//
//            }
//        }
//        return temp;
//    }
//
       else
    {
        if( y == 1 )
        {
            int temp = 0;

        for( int i=0; i <=9; i++ )
        {
            if( i == 0 && z == 0 )
            {
                temp +=  ( rec( x+1, 1, 0 ) );
            }
            else if( i == 0 && x == 0 )
            {
                temp +=  ( 2 + rec( x+1, 1, 1 ) );
            }
            else
            {
                temp += rec( x+1, 1, 1 );

            }

        }

        return temp;

        }

        else
        {
            if( z == 0 )
            {
                int temp = 0;

        for( int i=0; i <=arr[x]; i++ )
        {
            if( arr[x] > i )
            {
                if( i == 0 )
                    temp +=  rec( x+1, 1, 0 ) ;
                else
                    temp += rec( x+1, 1, 1 );
            }
            else
            {
                temp += rec( x+1, 0, 1 );

            }

        }
            return temp;

            }
         else
         {
             int temp = 0;

        for( int i=0; i <=arr[x]; i++ )
        {
            if( arr[x] > i )
            {
                if( i == 0 )
                    temp += ( 1 + rec( x+1, 1, 1 ) );
                else
                    temp += rec( x+1, 1, 1 );
            }
            else
            {
                temp += rec( x+1, 0, 1 );

            }
        }

        return temp;

         }

        }
    }

}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, m;


    cin >> str;

    n = str.size();
    for( i=0; i<n ; i++)
    {
        arr[i] = str[i]-48;
    }

    x = rec( 0, 0, 0);
      cout << x;



    return 0;

}


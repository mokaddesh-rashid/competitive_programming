
#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str, ss;
long long int n , m, dp[60][60], l, dp2[60][60][66];


long long int rec(long long int x, long long int y)
{


    if( x == n )
    return 0;
    if (y == m)
    return 0;
    if( dp[x][y] != -1 )
       return dp[x][y];
    if( str[x] == ss[y] )
        {
            dp[x][y] = 1 + rec( x+1,y+1) ;
            return dp[x][y];
        }

    else
    {

          dp[x][y] = max( rec(x,y+1), rec(x+1,y) );
          return dp[x][y];

    }
}
long long int coun(long long int x, long long int y, long long int z)
{

    if( l == z && x == n && y == m )
        return 1;
    if( x == n + 1  )
        return 0;
    if( y == m + 1 )
        return 0;
    if( dp2[x][y][z] != -1 )
       return dp2[x][y][z];
    if( str[x] == ss[y] )
        {
            dp2[x][y][z] = coun( x+1,y+1,z+1) ;
            return dp2[x][y][z];
        }

    else
    {

          dp2[x][y][z] = coun(x,y+1,z+1) + coun(x+1,y,z+1) ;
          return dp2[x][y][z];

    }
}





int main()
{

    long long int x, a, b, c, d, t, ca=1;

    cin >> t;

    cin.ignore();

    while( t-- )

     {
         getline(cin, str) ;
         getline(cin, ss) ;
         n = str.size();
         m = ss.size();

         a = min(n,m);
         b = max(n,m);

     memset( dp,-1,sizeof(dp));
     memset( dp2,-1,sizeof(dp2));

     x = rec(0,0);

        a -= x;

        l = a+b;

     cout << "Case "<<ca<<": " << l <<' ';
     long long int xx;

     xx = coun(0,0,0);

     cout << xx <<endl;
     ca++;

     }
}

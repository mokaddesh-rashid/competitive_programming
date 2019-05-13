#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

long long int dp[1000], n, m;

string str;

int rec( int x )
{
    long long int a, maxx=0, t=1, bb;
    string chk;

    if( x == n )
        return 0;
    if( dp[x] != -1)
            return dp[x];


    else
    {

        while( x + t <= n )
        {

            chk.assign(str,x,t);
            a = atoi( chk.c_str());

            cout << chk << endl;

            if( a <= 2147483647 && a >= 0  )
                dp[x] = max( dp[x], rec(x+t)+a);
            else
                break;
            t++;
        }

        return dp[x];

    }
}

int main()
{
    ios::sync_with_stdio(false);

    int t;

    cin >> t;

    while( t-- )
    {
        cin >> str;

    n = str.size();

    long long int li = 1234, i, j, a, x, b;


     memset( dp,-1,sizeof(dp));

     x = rec(0);

     cout << x <<endl;

    }



    return 0;

}

/*
  a = atoi( str.c_str());
    cout << a;
for( i=0; i<str.size(); i++)
    {
        x = 0;

        for( j=i; j<str.size(); j++)
        {

        }
    }


//2,147,483,647 */


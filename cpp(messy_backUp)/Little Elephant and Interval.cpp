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


//set<int>::iterator ii;

string str;
int n;

long long  rec( int x , int y, int st)
{
    int ans = 0,i;

    if( x == n )
        return 0;
    else
    {
        if( st == 0 && y == 0 )
        {
            int a = str[x] - 48;

            for( i=0; i<=a; i++)
            {
               if( i<a )
               {
                 ans += rec( x+1,1,i);
               }
               else
                 ans += rec( x+1,0,i);
            }
        }
        else if( st == 0 )
        {

            for( i=0; i<=9; i++)
            {
                 ans += rec( x+1,1,i);
            }
        }
        else if( y == 0 )
        {
             int a = str[x] - 48;

            for( i=0; i<=a; i++)
            {
               if( i<a )
               {
                   if( i == st )
                     ans += ( 1 + rec( x+1,1,st) );
                   else
                     ans += rec( x+1,1,st);
               }

               else
               {
                   if( i == st )
                     ans += ( 1 + rec( x+1,0,st) );
                   else
                     ans += rec( x+1,0,st);
               }
            }

        }
        else
        {
             int a = 9;

            for( i=0; i<=a; i++)
            {

                   if( i == st )
                     ans += ( 1 + rec( x+1,1,st) );
                   else
                     ans += rec( x+1,1,st);
            }

        }

    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    cin >> str;

    n = str.size();

   int  x  = rec(0,0,0);

   cout << x;


    return 0;

}



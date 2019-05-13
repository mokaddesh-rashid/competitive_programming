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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

int level[100000], arr[100000];
int i, j, x, y, n, m, a = 0, l = 1, c, t , fu ;

void rec( int x , int v )
{
   if( v == 0 || x > m )
     return;

   if( arr[x] != fu )
   {
       arr[x] += v;
       return;
   }

   rec( x+level[x], v/2 );
   rec( x+level[x]+1, v/2 );

}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

   while( 1 )
   {
        cin >> n >> t ;

        m = n * ( n+1 );
        m /= 2;
        fu = pow( 2, n-1);
        for( i = 1; i<=m; i++ )
        {
            if( a == l )
            {
                l++;
                a = 0;
            }

            level[i] = l;
            a++;
        }

        for( i=0; i<t; i++)
            rec( 1, fu );
        a = 0;
        for( i=1; i<=m; i++)
            {
                if( arr[i] == fu )
                    a++;
            }
        //cout << fu << ' ' << arr[5] << endl;
        cout << m << ' ' << a << endl;
   }

    return 0;

}



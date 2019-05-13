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
#define


//set<int>::iterator ii;

int dp[110][110][2][11], n, n1, n2, k1, k2;

int rec( int x, int y, int z, int k )
{
    cout << x << " , " << y << " , " << z << " , " << k << "\n";
    if( x + y == n )
    {
        //cout << 'k' << endl;
        // cout << ' ' << 1 << endl;
        cout << x << " , " << y << "\n";
        return 1;
    }
    else
    {
        int ans = 0;
        if( x < n1 && y < n2 ) ///   two type soldier e ase
        {
            if( z == 0 )
            {
                if(  k < k1 ) /// any soldier can take next position
                {
                    int temp = 0;
                    temp = rec( x+1, y, 0, k+1 ) + rec( x, y+1, 1, 1 );
                    //return temp;
                    ans = temp;
                }
                else   /// only 2nd type soldier can take next position
                {
                    int temp = 0;
                    temp = rec( x, y+1, 1, 1 );
                    //return temp;
                    ans = temp;
                }
            }
            else
            {
                if(  k < k2 ) /// any soldier can take next position
                {
                    int temp = 0;
                    temp = rec( x+1, y, 0, 1 ) + rec( x, y+1, 1, k+1 );
                    //return  temp;
                    ans = temp;
                }

                else /// only 1st type soldier can take next position
                {
                    int temp = 0;
                    temp =  rec( x+1, y, 0, 1 );
                    //return temp;
                    ans = temp;
                }

            }
        }
        else if( y >= n2 && (x < n1)) /// second type soldier sesh
        {
                cout << "1 ho\n";
                if( z == 1 )
                {
                    int temp = 0;
                    temp = rec(x+1,y, 0, 1);
                    //return temp;
                    cout << "2 ho\n";
                    cout << "temp : " << temp << "\n";
                    ans = temp;
                }
                else
                {
                    if(  k < k1 )
                    {
                        int temp = 0;
                        temp = rec( x+1, y, 0, k+1 );
                        //return temp;
                        ans = temp;
                    }
                    else
                    {
                        return 0;
                    }
                }
        }
        else if( x >= n1 && (y < n2) ) /// first type soldier sesh
        {
            //cout << x << ' ' << y << ' ' <<  z << ' ' << k <<endl;


            if( z == 0)
            {
                int temp = 0;
                temp = rec(x, y+1, 1, 1);
                //return temp;
                ans = temp;
            }
            else
            {
                if(  k < k2 )
                {
                    int temp = 0;
                    temp = rec( x, y+1, 1, k+1 );
                    //return temp;
                    ans = temp;
                }
                else
                {
                    ans = 0;
                }
            }
        }
        //cout << "hi\n";
        cout << x << " , " << y << " , " << z << " , " << k << " : " << ans << "\n";
        return ans;
    }

    //return 0;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y;

    cin >> n1 >> n2 >> k1 >> k2 ;

    n = n1+n2;

    //x = rec( 0,0,0,0);
    //y = rec( 0,0,1,0);

   cout << rec( 0,0,0,0) << "\n";

    return 0;

}

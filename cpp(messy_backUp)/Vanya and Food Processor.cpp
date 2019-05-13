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
#define NL '\n


//set<int>::iterator ii;

LL arr[100010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, h, k, a, b, c, t = 0;

    cin >> n >> h >> k;

    for( i=0; i<n; i++ )
        cin >> arr[i];

    for( i=0; i<n; i++ )
    {
        x += arr[i];
        //cout << x << endl;
        while( x + arr[i+1] > h )
        {
            if( x <= k )
            {
                //cout << 'k';
                x = 0;
                t++;
            }
            else
            {
                t += ( x/k );
                //cout << 'k' << x/k << endl;
                x = x % k;


            }

        }


    }

    if( x > 0 )
    {
         while( x > 0 )
        {
            if( x <= k )
            {
               // cout << 'k';
                x = 0;
                t++;
            }
            else
            {
                t += ( x/k );
                //cout << 'k' << x/k << endl;
                x = x % k;


            }

        }
    }

    cout << t;





    return 0;

}



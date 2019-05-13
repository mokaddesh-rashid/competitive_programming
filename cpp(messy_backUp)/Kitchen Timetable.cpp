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
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n


//set<LL>::iterator ii;

LL arr[100010], brr[100010];
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL t;

    cin >> t;

    while( t-- )
    {
        LL i, j, x, y, n, m, a = 0, b, cnt;

        cin >> n ;

        for( i=0; i<n; i++ )
        {
            cin >> b;

            arr[i] = b - a;
            a = b;
        }
        for( i=0; i<n; i++ )
        {
            cin >> brr[i];
        }

        //sort( arr, arr + n, greater<LL>() );
        //sort( brr, brr + n, greater<LL>() );

        cnt = a = 0;
        for( i=0; i<n; i++ )
        {
            //cout << arr[i] << ' ' << brr[i] << endl;
            if( arr[i] >= brr[i] )
            {
                cnt++;
                //a++;
            }
        }

        cout << cnt << endl;
    }




    return 0;

}



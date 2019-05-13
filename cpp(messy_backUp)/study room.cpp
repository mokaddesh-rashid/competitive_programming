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

int arr[100010];


int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        int i, j, x, y, n, m, cnt  = 0;

        cin >> n >> m ;
        memset( arr, 0, sizeof( arr ) );
        for( i=0; i<m; i++ )
        {
            cin >> x;

            arr[x]++;
            arr[x-1]++;
            arr[x+1]++;
        }

        for( i=1; i<=n; i++ )
        {
            if( arr[i] != 0 )
                cnt++;
        }

        cout << "Case " << ca++ << ": " << cnt << endl;
    }



    return 0;

}


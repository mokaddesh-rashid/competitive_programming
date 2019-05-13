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
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int arr[1000001], cnt[1000001];

int loop( int n )
{
    for( int i=2; i<=n; i++ )
    {
        if( arr[i] == 1 && cnt[i] == 0 )
        {
            for(int j=i; j<=n; j += i )
            {
                cnt[j]++;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m, k, z = 1;

    cin >> n >> k ;

    for( i=0; i<n; i++ )
    {
        cin >> y;
        y = y%k;
        arr[y] = 1;
        if( y == 0 || y == 1 )
            z = 0;
    }
    loop( k );
    for( i=2; i<k; i++ )
    {
        //cout << i << ' ' << cnt[i] << endl;
        if( cnt[i] == 0 )
            x++;
    }
    //cout << x << ' ' << z << endl;

    if( x < 1 || z == 0 )
        cout << "Yes";
    else
        cout << "No";



    return 0;

}



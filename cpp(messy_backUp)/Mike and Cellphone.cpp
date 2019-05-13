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
int i, j, x, y = -1, n, m, arr[100001], di[100001], a, b, c;

int chk( int x )
{
    cout << x << endl;
    for(int i=1; i<n; i++ )
    {
        c = arr[i];
        while( c-- )
        {
            x += di[i];
        }
        cout << x << endl;
        if ( ( x <= 0 || x > 9 ) && x != 11 )
        {
            return 0;
        }
    }
    cout << endl << endl;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;



    cin >> n;

    string str;

    cin >> str;

    for( i=0; i<n; i++ )
    {
        x = str[i]-48;
        if( x == 0 )
            x = 11;
        if( x > y && i > 0 )
        {
            arr[i] = x-y;
            di[i] = 1;
            //cout << arr[i] << endl;
        }
        else if( i > 0 )
        {
            arr[i] = y-x;
            di[i] = -1;
            //cout << arr[i] << endl;
        }
        y = x;
    }
    b = 0;
    for( i=1; i<=9; i++ )
    {
        x = str[0]-48;

        if( x != i )
        {
            a = chk( i );
            //cout << i << ' ' << a << endl;
            b = max( a, b );
        }
    }

    if( b == 1 )
        cout << "NO";
    else
        cout << "YES";

    return 0;

}



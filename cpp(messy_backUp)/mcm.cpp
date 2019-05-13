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
#define mod          1000000007
#define LL           long long
#define NL '\n

LL s[100][100], m[100][100], p, n, arr[1000];

void mcm( )
{

    for( LL i=0; i<n; i++ )
        m[i][i] = 0;

    for( LL l=2; l<=n; l++ )
    {
        cout << l << " = \n";
        for( LL i=1; i<=n-l+1; i++ )
        {
            LL j = i + l - 1;
            cout << i << "," << j << " = ";
            m[i][j] = mx;

            for( LL k = i; k<=j-1; k++ )
            {
                //cout << ' ' << k << ' ';
                cout << m[i][k] << ' ' << m[k+1][j] << " " << j << endl;
                LL q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];

                if( q < m[i][j] )
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }

            cout << endl;
        }
    }

    return ;
}

void print( int i, int j )
{

    if( i == j )
        cout << 'A' << i << ' ' ;
    else
    {
        cout << '(' << ' ';
        print( i, s[i][j] );
        print( s[i][j]+1, j );
        cout << ')' << ' ';
    }

    return;
}


int main()
{
    ios::sync_with_stdio(false);


    inf;
    n = 6;
    p = n+1;

    for(int i=0; i<p; i++ )
        cin >> arr[i];

    mcm();
    cout << m[1][n] << endl;

        for(int i=1; i<=n; i++ )
            for( int j = 1; j <=n; j++ )
            {
                cout << s[i][j] << ' ';

                if( j == n )
                    cout << endl;

            }



    print( 1, n );



}

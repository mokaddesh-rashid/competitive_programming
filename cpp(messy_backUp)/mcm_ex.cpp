#include<iostream>
#include<cstring>


using namespace std;


int m[1001][1001], n, p, s[1001][1001], a[1000001];

void rec( )
{
    int l, i, j, k, t;
    memset( m, 0, sizeof(m) );

    for( l=2; l<=n; l++ )
    {
        cout << l << ' ' << n-l+1 << " = \n";
        for( i=1; i<=n-l+1; i++ )
        {
            j = l + i - 1;
            cout << i << ' ' << j << " ";
            m[i][j] = 11111111;
            for( k = i; k<= j-1; k++ )
            {
                cout << k << ' ';
                 t = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];

                if( t < m[i][j] )
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        cout << endl;
        }
    }
}


int main()
{
    n = 6;
    int i, j, p;

    for( i=0; i<=6; i++ )
        cin >> a[i];

    rec( );

    cout << m[1][n];

    return 0;
}

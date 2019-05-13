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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

int mat[111][111], arr[10010][10];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, d, q;

    cin >> n >> m >> q ;

    for( i=0; i<q; i++ )
    {
        cin >> arr[i][0];

        if( arr[i][0] == 1 || arr[i][0] == 2 )
        {
            cin >> arr[i][1];
        }

        else
        {
            cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
        }

    }


    for( i = q-1; i >= 0; i-- )
    {
        if( arr[i][0] == 1 )
        {
           a = arr[i][1]-1;
           b = mat[a][m-1];
           for( j=m-1; j>0; j-- )
           {
               mat[a][j] = mat[a][j-1];
           }
           mat[a][0] = b;
        }
        else if( arr[i][0] == 2 )
        {
           a = arr[i][1]-1;
           b = mat[n-1][a];
           c = mat[0][a];
           mat[0][a] =  mat[n-1][a];
           for( j=1; j<n; j++ )
           {
               d = mat[j][a];
               mat[j][a] = c;
               c = d;
           }
        }
        else if( arr[i][0] == 3 )
        {
            mat[arr[i][1]-1][arr[i][2]-1] = arr[i][3];
        }
    }

    for( i=0; i<n; i++ )
    {
        for( j=0; j<m; j++ )
            cout << mat[i][j] << ' ';

        cout << endl;
    }


    return 0;

}



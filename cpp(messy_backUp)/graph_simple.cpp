#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int mat[55][55]={0}, i, j, n, m, a, b, k, x, ans=1, use[55]={0};

    cin >> n >> m;

    for(i=0 ; i< m; i++)
    {
        cin >> a >> b;

        mat[a][b]++;
        mat[b][a]++;
    }

    for( i=1; i<=n; i++)
    {
        for( j=1; j<=n; j++)
        {
            if ( mat[i][j] == 1 )
            {
                for( k=0; k<=n; k++)
                {
                    if ( mat[j][k] == 1 )
                    {
                        mat[i][k] = 1;
                    }
                }
            }
        }
    }
    for( i=1; i<=n; i++)
    {
        for( j=1; j<=n; j++)
        {
            if ( mat[i][j] == 1 )
            {
                for( k=1; k<=n; k++)
                {
                    if ( mat[j][k] == 1 )
                    {
                        mat[i][k] = 1;
                    }
                }
            }
        }
    }
    x = 1;

    for( i=1; i<=n; i++)
    {

         for( j=1; j<=n; j++)
           {
               cout<<mat[i][j]<<' ';

           }


         cout<<endl;
    }





}



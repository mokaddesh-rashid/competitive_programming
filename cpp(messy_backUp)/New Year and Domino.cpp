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

    int arr[55][55] = {0}, i, j, a, n, m, ff[55][55] = {0}, ss[55][55] = {0};

    cin >> n >> m;

    string str[n];

    for( i=0; i<n; i++)
        cin >> str[i];

    for( i=0; i<n; i++)
    {
        a = 0;
        for( j=0; j<m; j++)
        {
           if( str[i][j] == '.' && str[i][j+1] == '.' && j < m-1)
           {
               a++;
           }
           ff[i][j] = a;
        }
    }
    for( i=0; i<m; i++)
    {
        a = 0;
        for( j=0; j<n-1; j++)
        {
           if( str[j][i] =='.' && str[j+1][i] == '.' && j < n-1)
           {
               a++;
           }
           ss[j][i] = a;
        }




    }

    int nn;

    cin >> nn;

    for( int ii=0; ii<nn; ii++)
    {
        int b,c,d,e, x=0, y, z, l, k, ou=0;

        cin >> b >> c >> d >> e;
        y = min(b,d);
        z = max(b,d);
        l = min(c,e);
        k = max(c,e);

        for( i=y-1; i<z; i++)
        {
              if( k!= 1)
                x =  ff[i][k-2];

            else
                x =0;
           // cout<< x << endl;
            if( l != 1)
                x -= ff[i][l-2];
            //cout<< x << endl << endl;

            ou += x;
        }



        for( i=l-1; i<k; i++)
        {
            //cout << i << ' ' << z-2 <<endl;
             if( z!= 1)
                 x =  ss[z-2][i];
             else
                x = 0;
            // cout<< x << endl ;

            if( y != 1)
                x -= ss[y-2][i];
               //cout<< x << endl << endl;

            ou += x;
        }
        cout << ou << endl;
    }












}


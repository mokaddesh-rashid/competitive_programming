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


    int i, j, x=0, y=0, n, m, a, b = -1, v, c;

    scanf( "%d %d", &n,&m);

    int arr[n+1], pos[n+1], next[n+1] ;



    for( i=0; i<n; i++)
    {

        scanf( "%d", &a);
        arr[i] = a;
        if( a != b )
        {

            x++;
            next[ x ] = i;
            b = a;
        }
          pos[i] = x;

    }

    next[ x ] = next[x-1]+1;

    next[ x+1 ] = n+1;


     for( i=0; i<m; i++ )
     {
         scanf( "%d %d %d", &a, &b, &v);
         //cin >> a >> b >> v;

         a--;
         b--;

         if( arr[a] != v )
            printf("%d\n",a+1);
         else if( next[pos[a]+1] <= b )
             printf("%d\n",next[pos[a]+1]+1);
         else
             printf("%d\n",-1);


     }

    return 0;

}

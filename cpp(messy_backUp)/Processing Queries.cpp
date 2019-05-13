#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

   // INP;
    //OUT;

    long long i, j, x = 0 , y = 0, n, m, d = 0, t = 0, mq = 0;

    cin >> n >> m ;

    long long ff[n+1], ss[n+1], arr[n+1];

    memset( arr, 0, sizeof(arr));

    for( i=0; i<n; i++)
       {
           cin >> ff[i] >> ss[i];

           if( x == i )
           {
               mq = max(ff[i],mq)+ss[i];

           }
           else if( ff[i] < mq )
           {
               if( i - x > m )
               {
                   ff[i] = 0;
                   ss[i] = 0;
               }


           }
           else if( ff[i] >= mq )
           {

               x++;
               while( ff[x] == 0 && x < i )
               {
                   x++;
               }
               //cout << i << ' ' << ff[x] << ' ' << ss[x] << ' ';
               mq = max(ff[x],mq)+ss[x];

           }

       // cout << mq << endl;


       }

       mq = 0;

       for( i=0; i<n; i++)
         {
             if( ss[i] == 0 )
                cout << -1 << ' ';
             else
             {
                 mq = max(mq,ff[i])+ss[i];
                 cout << mq << ' ';
             }
         }



    return 0;

}



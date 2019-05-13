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

string str[11];
int pos, pos2;
struct info
{
    int cnt, p1[10], p2[10], val;
} arr[15][15];

void max_pos ()
{
    int x = -1111;

    for(int i=0; i<10; i++ )
    {
        for(int j=0; j<10; j++ )
        {
            if( x < arr[i][j].cnt )
            {
                x = arr[i][j].cnt;
                pos = i;
                pos2 = j;
            }
        }

    }
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int ca;

    cin >> ca;

    while( ca-- )
    {
        memset( arr, 0, sizeof( arr ) );
        int i, j, x, y, n,  l, m, a, b, c = 0, v = 0;

    for( i=0; i<10; i++ )
        cin >> str[i];

    for( i=0; i<10; i++ )
    {
        for( j=0; j<10; j++ )
        {
            if( i != 0 && ( str[i-1][j-1] == 'g' ||  str[i-1][j] == 'g' ||  ( str[i-1][j+1] == 'g' && j != 9 ) ) )
                continue;
            else if( ( str[i][j-1] == 'g' && j != 0 ) ||  str[i][j] == 'g' ||  ( str[i][j+1] == 'g' && j != 9 ) )
                continue;
            else if( i != 9  && ( str[i+1][j-1] == 'g' ||  str[i+1][j] == 'g' ||  ( str[i+1][j+1] == 'g' && j != 9 )  ) )
                continue;
            else
            {
               for( l=i-1; l<=i+1; l++ )
               {
                   for( m = j-1; m<=j+1; m++ )
                   {

                     if(  l >=0 && m >= 0 && l < 10 && m < 10 && str[l][m] == 'e' )
                     {
                         arr[i][j].p1[arr[i][j].cnt] = l;
                         arr[i][j].p2[arr[i][j].cnt] = m;
                         arr[i][j].cnt++;
                         arr[i][j].val++;

                     }
                   }
               }


            }
        }
    }


     while( true )
     {
         max_pos();
         //cout << arr[pos][pos2].val << endl;
         if( arr[pos][pos2].cnt <= 0 )
            break;

         for(int k = 0; k < arr[pos][pos2].val; k++ )
         {
             a = arr[pos][pos2].p1[k];
             b = arr[pos][pos2].p2[k];
           if( a != -1 || b ! )
           {
                 for( i=0; i<10; i++ )
         {
             for( j=0; j<10; j++ )
             {
                if( i == pos && j == pos2 )
                    continue;
                else
                {
                   for( l = 0; l < arr[i][j].val; l++ )
                   {
                       if( arr[i][j].p1[l] == a && arr[i][j].p2[l] == b )
                       {
                           arr[i][j].p1[l] = -1;
                           arr[i][j].p2[l] = -1;
                           arr[i][j].cnt--;
                       }
                   }
                }
             }
         }

           }

         }
         v +=  arr[pos][pos2].cnt;
         arr[pos][pos2].cnt = 0;
         c++;
     }

     cout << v << ' ' << c << endl;
    }

    return 0;

}



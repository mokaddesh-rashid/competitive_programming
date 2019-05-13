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

string str, cmd;

int stk[6000000], pos[600000], use[600000], dir[600000];


int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, top = -1, p;

    cin >> n >> m >> p;
    p--;

    cin >> str ;

    cin >> cmd;

    for( i=0; i<n; i++ )
    {
        if( str[i] == '(' )
        {
            stk[++top] = i;
        }
        else
        {
            pos[stk[top]] = i;
            pos[i] = stk[top];
            dir[stk[top]] = 1;
            dir[i] = -1;
            top--;
        }
    }

    for( i=0; i<m; i++ )
    {
        if( cmd[i] == 'L' )
            p--;
        else if ( cmd[i] == 'R' )
            p++;
        else
        {

          if( dir[p] == 1 )
            {
                use[p] = 1;
                use[pos[p]] = -1;
                p = pos[p] + 1;

            }
          else
           {
                use[p] = -1;
                use[pos[p]] = 1;
                p = pos[p] + 1;
                p = pos[p] + 1;
           }

        }
    }
    int a = 0;
    for( i=0; i<n; i++ )
    {
      a += use[i];

      if( a == 0 )
            cout << str[i];
    }

    return 0;

}


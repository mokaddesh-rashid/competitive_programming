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
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'


//set<int>::iterator ii;
struct info
{
    int val, lev, sum, cnt, lft, rig;
}lar[300001] ;

struct info2
{
    int lev, val;
}arr[1000001];

int mat[1001][1001], st, stk[100000], top, len;

void bfs( int x, int lvl )
{
    lar[x].lev = lvl;
    lar[x].cnt = 1;
    while( top != -1 )
    {
       for(int i=1; i<=mat[x][0]; i++ )
    {
        if( lar[mat[x][i]].cnt == 0 )
              {
                  stk[top] = mat[x][i];
                  top++;
                  lar[mat[x][i]].lev = lvl+1;
                  lar[mat[x][i]].cnt++;
              }
    }

     top--;

     if( top == -1 )
        break;

     x = stk[top];
     lvl = lar[x].lev;

    }

}

void value( int x )
{
    cout << x << ' ';
    arr[len].lev = lar[x].lev;
    arr[len].val = x;

    if( lar[x].lft == 0 )
        lar[x].lft = len;
    lar[x].rig = len;
    len++;
}

void rec( int x )
{
    if( top == -1 && len != 0 )
       return;

    value( x );

    if( lar[x].cnt == 1 )
    {
      lar[x].cnt++;
      top++;
      stk[top] = x;
    }
    else
      lar[x].cnt++;


    if( mat[x][0] > 0 )
    {
        mat[x][0]--;
        rec( mat[x][mat[x][0]+1] );
    }
    else
    {
        if( lar[x].cnt == 2 )
        {
            value(x);
        }

        top--;

        if( top == -1 )
            return;
        else
            rec( stk[top] );
    }
}




int main()
{
    inf;
    //outf;
    ios::sync_with_stdio(false);

    int i, j, x, y, n, m;

    cin >> n;

    for( i=1; i<=n; i++ )
    {
        cin >> m;

        if( st == 0 && m != 0 )
            st = i;

        mat[i][0] = m;
        for( j=1; j<=m; j++ )
        {
            cin >> mat[i][j];
        }
    }

    top = 0;
    stk[top] = st;
    bfs( st, 1 );
    top = -1;
    len = 0;
    //cout << st;
    rec( st );

    cout << len;

    return 0;

}



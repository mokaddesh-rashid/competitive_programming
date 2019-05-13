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
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;
struct info
{
    int val, lev, sum, cnt, lft, rig, sz;
}lar[100001] ;

struct info2
{
    int lev, val;
}arr[1000001];

int st, stk[100000], top, len;
vector < int > mat[100001];

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
    cout << x ;
    arr[len].lev = lar[x].lev;
    arr[len].val = x;
    cout << '(' << len << ')' << ' ';
    if( lar[x].lft == 0 )
        lar[x].lft = len;
    lar[x].rig = len;
    len++;
}

void rec( int x )
{
    if( top == -1 && len != 1 )
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

struct info3
{
   LL p;

}tree[4*MAX];

void init(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cnd.p = b;
        return ;
    }


    init(lnd, b, (b+e)/2);
    init(rnd, ((b+e)/2)+1, e);

    if( arr[tree[lnd].p].lev < arr[tree[rnd].p].lev )
        cnd.p = tree[lnd].p;
    else
        cnd.p = tree[rnd].p;
}

LL query(LL idx, LL b, LL e, LL st, LL en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.p;

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);

    if( arr[lft].lev < arr[rgt].lev )
        return lft;
    else
        return rgt;
}


int main()
{
    //inf;
    //outf;
    //ios::sync_with_stdio(false);

    int t, ca = 1;

    sf( t );

    while( t-- )
    {
        memset( lar, 0, sizeof(lar) );
        memset( arr, 0, sizeof(arr) );

        int i, j, x, y, n, m, z;

        //cin >> n;
        sf( n );

        for( i=1; i<=n; i++ )
        {
            sf( m );
            //cin >> m;

            if( st == 0 && m != 0 )
                st = i;

            mat[i][0] = m;
            for( j=1; j<=m; j++ )
            {
                sf( mat[i][j] );
                //cin >> mat[i][j];
            }
        }

        top = 0;
        stk[top] = st;
        bfs( st, 1 );
        top = -1;
        len = 1;
        rec( st );
        arr[0].lev = len+1;
        init( 1, 1, len );
    //    cout << endl;
    //    for( i=1; i<=n; i++ )
    //    {
    //        cout << i << ' ' << lar[i].lft << ' ' << lar[i].rig << endl;
    //    }

        //cin >> z;
        sf( z );
        pf("Case %d: \n", ca++ );
        while( z-- )
        {
            //cin >> x >> y;
            sff( x, y );
           // cout << min ( lar[x].lft, lar[y].rig ) << ' ' <<lar[y].rig << endl;
            int a = query( 1, 1, len, min ( lar[x].lft, lar[y].rig ), max( lar[x].lft, lar[y].rig ) );
            //cout << arr[a].val << endl;
            pf("%d\n", arr[a].val );
        }

    }


    return 0;

}




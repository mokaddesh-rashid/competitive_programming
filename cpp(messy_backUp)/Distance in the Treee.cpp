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
#define cndd treee[idx]


//set<int>::iterator ii;
struct info
{
    int val, lev, sum, cnt, lft, rig, lf, ri;
}lar[100001] ;

struct info2
{
    int lev, val;
}arr[1000001];

vector <int> mat[100001], cost[100001];

int st, stk[100000], top, len, blen;

void bfs( int x, int lvl )
{

    int v = 0;
    lar[x].sum = 0;
    lar[x].lev = lvl;
    lar[x].cnt = 1;
    while( top != -1 )
    {
       ////cout << x << " =  ";
       for(int i=1; i<=mat[x][0]; i++ )
    {
        if( lar[mat[x][i]].cnt == 0 )
              {
                 // //cout << mat[x][i] << '(' << cost[x][i]+v <<')' << ' ';
                  stk[top] = mat[x][i];
                  top++;
                  lar[mat[x][i]].sum = v + cost[x][i];
                  lar[mat[x][i]].lev = lvl+1;
                  lar[mat[x][i]].cnt++;
              }
    }
    // //cout << endl;
     top--;

     if( top == -1 )
        break;

     x = stk[top];
     lvl = lar[x].lev;
     v = lar[x].sum;

    }

}

void value( int x )
{
    //cout << x ;
    arr[len].lev = lar[x].lev;
    arr[len].val = x;
    //cout << '(' << arr[len].val  << ')' << ' ';
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
      //valueb(x);
      lar[x].cnt++;
      top++;
      stk[top] = x;
    }
    else
      lar[x].cnt++;

    while( mat[x][0] > 0 && lar[mat[x][mat[x][0]]].lev < lar[x].lev )
    {
         mat[x][0] = mat[x][0]-1;
    }


    if( mat[x][0] > 0 )
    {
        mat[x][0] = mat[x][0]-1;
        rec( mat[x][mat[x][0]+1] );
    }
    else
    {
        //valueb(x);
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
        {
            //cout << b << ' ' << e << ' ' << cnd.p << endl;
            return cnd.p;
        }

    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);

    if( arr[lft].lev < arr[rgt].lev )
        {
            //cout << b << ' ' << e << ' ' << lft << endl;
            return lft;
        }
    else
    {
        //cout << b << ' ' << e << ' ' << rgt << endl;
        return rgt;
    }
}


int main()
{
    //inf;
    //outf;
    //ios::sync_with_stdio(false);


        int i, j, x, y, n, m, z, a, b, c;

        //cin >> n;
        sf( n );
        for( i=1; i<=n; i++ )
        {
            mat[i].clear();
            cost[i].clear();
            mat[i].push_back(0);
            cost[i].push_back(0);
            //sf( cost[i] );
        }

        for( i=1; i<n; i++ )
        {
            sff( a, b );
            sf( c );
            a++;
            b++;
            mat[a][0] = mat[a][0] + 1;
            mat[b][0] = mat[b][0] + 1;
            mat[a].push_back(b);
            mat[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);

        }

        top = 0;
        stk[top] = 1;
        bfs( 1, 1 );
       // //cout << endl;
        top = -1;
        blen = 1;
        len = 1;
        rec( 1 );
        //cout << endl;
        arr[0].lev = len+1;
        init( 1, 1, len );

        sf(m);

        //for( i=1; i<20; i++ )
            ////cout << i << ' ' << lar[i].val << endl;

        for( i=0; i<m; i++ )
        {
            //cin >> x >> y;
            sff( x, y);
            x++;
            y++;
           // //cout << min( lar[x].lft, lar[y].rig) << ' ' << max(lar[x].lft, lar[y].rig) << endl;
            a = query( 1, 1, len, min( lar[x].lft, lar[y].rig), max(lar[x].lft, lar[y].rig) );
            a = arr[a].val;
            pf("%d\n", lar[x].sum + lar[y].sum - lar[a].sum - lar[a].sum );
        }

    return 0;

}

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
#define stf(n)       scanf("%s", n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define LL long long
#define MAX 200005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)

struct Node{
    LL lazy, sum, tm;
    Node()
    {
        tm = lazy = sum = 0;
    }
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum = ( ( e - b + 1 ) * v );
    cnd.lazy = v;
    cnd.tm = 1;
}

void lazy_update(int idx, int b, int e)
{
    if( cnd.tm != 0 )
    {
        update_node(lnd, b, (b+e)/2, cnd.lazy);
        update_node(rnd, ((b+e)/2)+1, e, cnd.lazy);
    }
    cnd.lazy = 0;
    cnd.tm = 0;
}


LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cnd.sum;

    lazy_update(idx, b, e);
    LL lft = query(lnd, b, (b+e)/2, st, en);
    LL rgt = query(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    lazy_update(idx, b, e);
    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cnd.sum = tree[lnd].sum+tree[rnd].sum;

}

int arr[200001], brr[200001], cnt[200001];

int main()
{
   int t, ca = 1;

   sf( t );

   while( t-- )
   {
           memset( tree, 0, sizeof( tree ) );
           memset( cnt, 0, sizeof( cnt ) );
          int n, m , i, j, a, b, c, x, y, d, v=0;


           //cin >> n ;
           sf( n );

           m = n*2;

           for( i=0; i<n; i++ )
           {
               sff( arr[i], brr[i] );
               //cin >> arr[i] >> brr[i];
               //update( 1, 1, m+1, a, b, v)
           }
           for( i=0; i<n; i++ )
           {
               update( 1, 1, 200001, arr[i], brr[i], i+1 );
           }

           for( i=1; i<=200001; i++ )
           {
               x = query( 1, 1, 200001, i, i );
               cnt[x]++;
           }

           for( i=1; i<=200001; i++ )
           {
               if( cnt[i] != 0 )
                 v++;
           }

           pf("Case %d: %d\n", ca++, v );

       }

       return 0;


}



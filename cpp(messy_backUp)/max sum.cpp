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

int arr[1000000];

struct node
{
   int maxx, sum, mazz ;
} node[3*1000000];

void init(int x, int i, int j )
{
    if( i == j )
       {
           node[x].maxx = arr[j];
           node[x].sum = arr[j];
           return;
       }

    int lef = x * 2;
    int rig = x * 2 + 1;
    int mid = ( i + j ) / 2;
    init( lef, i, mid );
    init( rig, mid+1, j );

    node[x].maxx = max ( node[lef].maxx , node[rig].maxx );
    node[x].sum = max ( node[lef].maxx + node[rig].maxx , node[lef].sum );
    node[x].sum = max ( node[x].sum , node[rig].sum  );
    cout << node[x].sum << ' ' << i << ' ' << j << endl;


}

void update(int x, int i, int j, int val,int ind )
{
    if( ind < i || ind > j )
        return;
    if( i == j )
      {
           node[x].maxx = val;
           node[x].sum = val;
           return;
      }

    int lef = x * 2;
    int rig = x * 2 + 1;
    int mid = ( i + j ) / 2;
    update( lef, i, mid, val, ind );
    update( rig, mid+1, j, val, ind );

    node[x].maxx = max ( node[lef].maxx , node[rig].maxx );
    node[x].sum = max ( node[lef].maxx + node[rig].maxx , node[lef].sum );
    node[x].sum = max ( node[x].sum , node[rig].sum  );

}
int query(int x, int i, int j, int st, int en )
{
    if( i > en || j < st )
        return 0;
    if( i >= st && j <= en )
       return node[x].sum;

    int lef = x * 2;
    int rig = x * 2 + 1;
    int mid = ( i + j ) / 2;
    return max ( query( lef, i, mid, st, en ) , query( rig, mid+1, j, st, en ) );

}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;

    cin >> n ;


    for( i=1; i<=n; i++ )
        cin >> arr[i];

    init( 1, 1, n );

    while( true )
    {
       char ch;

       cin >> ch;

       if( ch == 'Q' )
       {
           cin >> x >> y;
           cout << query( 1, 1, n, x, y ) << endl;
       }

       else
       {
           cin >> x >> y;
           update( 1, 1, n, y, x );
       }
    }

    return 0;

}




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
struct info ///  ki type info save krbo
{
   int sum, prop;
} node[3*1000000];

void init(int x, int i, int j )
{
    if( i == j )
       {
           node[x].sum = arr[j]; /// leaf node
           return;
       }

    int lef = x * 2; /// left child
    int rig = x * 2 + 1; /// right child
    int mid = ( i + j ) / 2;
    init( lef, i, mid );
    init( rig, mid+1, j );

    node[x].sum = node[lef].sum + node[rig].sum; /// left and right child sum diye aitr sum

}

void update(int x, int i, int j, int val,int st, int en )
{
    if( i > en || j < st ) /// extra part drkr nai
        return ;
    if( i >= st && j <= en ) /// range update kora lagbe ai area r maje
       {
          node[x].sum += ( ( j - i + 1 ) * val );
          node[x].prop += val;
          return ;
       }

    int lef = x * 2;
    int rig = x * 2 + 1;
    int mid = ( i + j ) / 2;
    update( lef, i, mid, val, st, en );
    update( rig, mid+1, j, val, st, en );

    node[x].sum = node[lef].sum + node[rig].sum + ( ( j - i + 1 ) * node[x].prop );

}
int query(int x, int i, int j, int st, int en, int carry )
{
    if( i > en || j < st ) /// extra part drkr nai
        return 0;
    if( i >= st && j <= en ) /// range of are maje prse jr maje query kora lagbe ai area r maje
       return node[x].sum + ( ( j - i + 1 ) * carry );

    int lef = x * 2;
    int rig = x * 2 + 1;
    int mid = ( i + j ) / 2;
    return query( lef, i, mid, st, en, carry + node[x].prop ) + query( rig, mid+1, j, st, en,  carry + node[x].prop );

}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int n, x, y, v;

    update( 1, 1, n, v, x, y ); /// value need to add in the are

    y = query( 1, 1, n, x, x, 0 ) ;





    return 0;

}




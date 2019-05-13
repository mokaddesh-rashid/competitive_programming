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
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

int ff[100001], ss[100001], cost[100001];

void merge_it(int arr[], int xtra[], int start, int mid, int endd)
{
    int n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

    int arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1], i, j, k, maxx;

    maxx = max( n1, n2);

    for( i=0; i < maxx; i++)
    {
        if( n1 > i)
        {
            arr_1[i] = arr[start+i];
            xtra_1[i] = xtra[start+i];
        }

        if(n2 > i)
        {
            arr_2[i] = arr[mid+1+i];
            xtra_2[i] = xtra[mid+1+i];
        }
    }

    i=0;
    j=0;
    k=start;

    while(i<n1&&j<n2)
    {
        if(arr_1[i]<arr_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            i++;
            k++;
        }
        else if(arr_1[i]==arr_2[j]&&xtra_1[i]<xtra_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arr_2[j];
            xtra[k]=xtra_2[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            i++;
            k++;
    }

  while(j<n2)
  {
            arr[k]=arr_2[j];
            xtra[k]=xtra_2[j];
            j++;
            k++;
  }

}


int divide( int arr[], int xtra[], int start, int endd)
{
    int mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,xtra,start,mid);
        divide(arr,xtra,mid+1,endd);

        merge_it(arr,xtra,start,mid,endd);
    }
}
struct info
{
    int val, lev, sum, cnt, lft, rig, lf, ri;
}lar[100001] ;

struct info2
{
    int lev, val;
}arr[1000001];

info2 brr[1000001];

int mat[100001][3], st, stk[100000], top, len, blen;

void bfs( int x, int lvl )
{
    lar[x].lev = lvl;
    lar[x].cnt = 1;
    while( top != -1 )
    {
        int n = mat[x][1]+mat[x][0];
       // cout << x << ' ' << mat[x][1] << ' ' << mat[x][0] << " = ";

       for(int i=mat[x][1]; i<n; i++ )
    {
        if( lar[ss[i]].cnt == 0 )
              {
                 // cout << ss[i] << ' ';
                  stk[top] = ss[i];
                  top++;
                  lar[ss[i]].lev = lvl+1;
                  lar[ss[i]].cnt++;
              }
    }
    // cout << endl;
     top--;

     if( top == -1 )
        break;

     x = stk[top];
     lvl = lar[x].lev;

    }

}

void value( int x )
{
    //cout << x ;
    arr[len].lev = lar[x].lev;
    arr[len].val = x;
    //cout << '(' << len << ')' << ' ';
    if( lar[x].lft == 0 )
        lar[x].lft = len;
    lar[x].rig = len;
    len++;
}

void valueb( int x )
{
    //cout << x << ' ';
    brr[blen].lev = lar[x].lev;

    //cout << '(' << len << ')' << ' ';
    if( lar[x].lf == 0 )
        {
            lar[x].lf = blen;
            brr[blen].val = cost[x];
            //cout << '(' << cost[x] << ')' << ' ';
        }
    else
        {
            brr[blen].val = -1*cost[x];
            //cout << '(' << -1*cost[x] << ')' << ' ';
        }

    lar[x].ri = blen;
    blen++;
}

void rec( int x )
{
    if( top == -1 && len != 1 )
       return;

    value( x );

    if( lar[x].cnt == 1 )
    {
      //cout << x << ' ';
      valueb(x);
      lar[x].cnt++;
      top++;
      stk[top] = x;
    }
    else
      lar[x].cnt++;


    if( mat[x][0] > 0 )
    {
        mat[x][0]--;
        int n = mat[x][1]+mat[x][0];
        rec( ss[n] );
    }
    else
    {
       // cout << x <<  ' ';
        valueb(x);
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



struct Node1{
    LL lazy, sum;
    Node1()
    {
        lazy = sum = 0;
    }
};

Node1 treee[4*MAX];

void initt(LL idx, LL b, LL e )
{

    if( b == e )
    {
        cndd.sum = brr[b].val;
        return ;
    }


    initt(lnd, b, (b+e)/2);
    initt(rnd, ((b+e)/2)+1, e);
    cndd.sum =  treee[lnd].sum + treee[rnd].sum ;

    //cout << cnd.sum << ' ' << b <<  ' ' << e << endl;
}
LL queryy(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
        return cndd.sum;

    LL lft = queryy(lnd, b, (b+e)/2, st, en);
    LL rgt = queryy(rnd, ((b+e)/2)+1, e, st, en);
    return (lft+rgt);
}

void update_node(int idx, int b, int e, LL v)
{
    cndd.sum = v;
}

void update(int idx, int b, int e, int st, int en, int v)
{
    if(st > e || en < b ) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }

    update(lnd, b, (b+e)/2, st, en, v);
    update(rnd, ((b+e)/2)+1, e, st, en, v);
    cndd.sum = treee[lnd].sum+treee[rnd].sum;
}

int main()
{
    //ios::sync_with_stdio(false);

    inf;
    outf;
    int t, ca = 1;
    sf( t );

    while( t-- )
    {

    memset( arr, 0, sizeof(arr) );
    memset( brr, 0, sizeof(brr) );
    memset( lar, 0, sizeof(lar) );
    int i, j, x, y, n, m, a, b, c, z;

    //cin >> n ;
    sf( n );

    for( i=1; i<=n; i++ )
    {
        sf( cost[i] );
        //cin >> cost[i];
    }

    for( i=1; i<n; i++ )
    {
        sff( ff[i], ss[i] );
        //cin >> ff[i]  >> ss[i];
        ff[i]++;
        ss[i]++;
    }

    divide( ff, ss, 1, n-1 );

    //for( i=1; i<)
    st = 0;
    for( i=1; i<=n; i++ )
    {
        a = lower_bound( ff+1, ff+n+1, i ) - ff;
        b = upper_bound( ff+1, ff+n+1, i ) - ff;

        if( b - a > 0 && st == 0 )
           st = i;

        mat[i][0] = b - a;
        mat[i][1] = a;
    }

    top = 0;
    stk[top] = st;
    bfs( st, 1 );
    top = -1;
    //cout << lar[2].lev << endl;
    blen = 1;
    len = 1;
    rec( st );
    brr[0].lev = blen+1;
    arr[0].lev = len+1;
    init( 1, 1, len );
    initt( 1, 1, blen );
//    cout << endl;
//    for( i=1; i<=n*2; i++ )
//         cout << brr[i].val << ' ';
        //cout << lar[i].lf << ' ' <<lar[i].ri << endl;

    //cin >> m;
    pf("Case %d:\n", ca++ );
    sf( m );
    for( i=0; i<m; i++ )
    {
        //cin >> z >> x >> y;
        sf( z );
        sff( x, y );
        if( z == 0 )
        {
            x++;
            y++;
            a = query( 1, 1, len, min ( lar[x].lft, lar[y].rig ), max( lar[x].lft, lar[y].rig ) );
            a = arr[a].val ;
            b = queryy( 1, 1, blen, lar[a].lf, lar[x].lf );
            c = queryy( 1, 1, blen, lar[a].lf, lar[y].lf );
            //cout << b << endl << c << endl;
            //cout << b+c-cost[a] << endl;
            pf( "%d\n",b+c-cost[a] );
        }
        else
        {
            x++;
            //cout << x << ' ' << lar[x].lf << ' ' << lar[x].ri << endl;
            update( 1, 1, blen, lar[x].lf, lar[x].lf, y );
            update( 1, 1, blen, lar[x].ri, lar[x].ri, y );
            cost[x] = y;
        }

    }

    }
    return 0;

}

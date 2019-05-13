#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;
string str;
int n, m , l;

int vld( int x, int y )
{
    if( x < 0 || y < 0 || x >= n || y >= m ) return 0;
    else return 1;
}

int chk( int p, int x, int y )
{
    int a = 0, b = 0;

    if( p == l ) return 0;
    if( str[p] == '^' ) a--;
    else if( str[p] == 'V' ) a++;
    else if( str[p] == '<' ) b--;
    else if( str[p] == '>' ) b++;

    int c;
    c = vld( x+a, y+b );

    if( c == 0 ) return chk( p+1, x+a, y+b );

    return 1 + chk( p+1, x, y );
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

        int i, j, x = 0, y = 0, a , b, c, d, e;
        int v = 10000000;

        a = c = -10000000;
        b = d = 10000000;

        cin >> n >> m ;

        cin >> str;
        l = str.size();
        for( i=0; i<l; i++ )
        {
            if( str[i] == '^' ) x++;
            else if( str[i] == 'V' ) x--;
            else if( str[i] == '<' ) y++;
            else y--;

            a = max( a, x ), b = min( a, x );
            c = max( c, y ), d = max( d, y );
        }


        x = chk( 0, min( a, n-1 ), max( 0, m-c-1 ) );
        v = min( v, x );

        x = chk( 0, min( a, n-1 ), min( c, m-1 ) );
        v = min( v, x );

        e = min( n+c, n-1 );
        e = max( e, 0 );

        x = chk( 0, e, max( 0, m-c-1 ) );
        v = min( v, x );

        x = chk( 0, e, min( c, m-c-1 ) );
        v = min( v, x );


        cout << v << endl;
    }


    return 0;

}


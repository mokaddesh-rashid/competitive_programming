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

struct node
{
    int p, v;
};
set<node>::iterator it;

class compare
{
public:
    bool operator()( node x, node y )
    {
        return x.v > y.v;
    }
};

set< node, compare > ms;
node nd;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a, b, c;

    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> a;
        nd.v = a, nd.p = a;
        ms.insert( nd );
    }

    while( true )
    {
        it = ms.begin();
        nd = *it;
        ms.erase( ms.find( nd ) );

        c = a = b = nd.v;
        c = 0;
        //cout << b << endl;
        while( a > 1 )
        {
            node fn;
            if( fn == nd ) cout << "OK";
            b = a;
            a = a/2;
            it = ms.find( a );
            if( a !=  *it )
            {
               ms.insert( a );
               c = 1;
               break;
            }
        }
        if( c == 0 ) ms.insert( b );

        if( c == 0 ) break;

    }

    for( it = ms.begin(); it!=ms.end(); it++ )
        cout << *it << ' ';


    return 0;

}



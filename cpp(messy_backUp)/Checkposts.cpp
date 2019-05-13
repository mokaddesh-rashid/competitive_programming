#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> pr;

/*dir array
//8 moves
LL fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
LL fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
LL fx[]={+1,-1,+0,+0};
LL fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<LL>::iterator ii;

struct node
{
    LL v, pa, low, lev, cost;
}dfa[100010];

LL stk[100010], top, ins[100010], ti, mon, way;
vector<LL> mat[100010];

void tarzan( LL p )
{
    LL i, j, y;
    dfa[p].v = 1;
    dfa[p].low = dfa[p].lev = ++ti;
    ins[p] = 1;
    stk[++top] = p;

    for(LL i=0; i<mat[p].size(); i++ )
    {
        LL x = mat[p][i], y;
        if( dfa[x].v == 0 )
        {
            tarzan(x);
            dfa[p].low = min( dfa[x].low, dfa[p].low );
            //cout << p << ' ' << x  << ' ' << dfa[x].low << ' ' << dfa[p].low << endl;

        }
        else if( ins[x] == 1 ) dfa[p].low = min( dfa[x].lev, dfa[p].low );

    }
    //cout << p << ' ' << dfa[p].low <<  ' ' << dfa[p].lev << endl;
    if( dfa[p].low == dfa[p].lev )
    {
        LL l = maxx, c = 0;
        while( top > -1 )
        {
            y = stk[top];
            ins[y] = 0;
            top--;

            if( l > dfa[y].cost )
            {
                l = dfa[y].cost;
                c = 0;
            }
            if( l == dfa[y].cost ) c++;

            if( y == p ) break;
        }
        mon += l;

        if( way == 0 ) way = c;
        else way *= c;

        way %= mod;
        ///cout << endl;
    }
}




int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m;

    ti = 0;
    top = -1;
    cin >> n;

    for( i=1; i<=n; i++ )
    {
        cin >> x;
        dfa[i].cost = x;
    }

    cin >> m;
    for( i=0; i<m; i++ )
    {
        cin >> x >> y;
        mat[x].push_back( y );
       // mat[y].push_back( x );
    }

    for( i=1; i<=n; i++ )
    {
        if( dfa[i].v == 0 ) tarzan( i );
    }



    cout << mon << ' ' << way << endl;

    return 0;

}





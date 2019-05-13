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


//set<int>::iterator ii;

struct node
{
    LL v, pa, st, en, l;
}dfa[110];

vector<int> mat[110];

int pos, cy[110], ar[110], le, cnt[110], cl;

void circle( int x )
{
    int i = pos-1;
    cl = 1;

    while(true)
    {
        //cout << ar[i] << ' ';
        cy[cl] = ar[i], cl++;
        if( ar[i] == x ) break;
        i--;
    }

    //cout << endl;

}

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1, dfa[p].st = le, le++;
        ar[pos] = p, pos++;
        //cout << p << ' ';
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];

            if( dfa[x].v == 0 )  dfs(x);
            else if( dfa[x].st != 0 && dfa[x].en == 0 && ar[pos-2] != x )
                 circle( x );
        }
        dfa[p].en = le, le++;
        pos--;
        //cout << p << ' ';
    }
}


int road[110][5];

int fin( int x, int y )
{
    int re;
    for(int i=1; i<=100; i++ )
    {
        if( x == road[i][0] && y == road[i][1] )
            return 0;
        else if( y == road[i][0] && x == road[i][1] )
            re = road[i][2];
    }
    return re;
}

int chk( int x, int y )
{
    int a, b;
    for(int i=1; i<cl; i++ )
    {
        a = cy[i], b = cy[i+1];
        if( i+1 == cl ) b = cy[1];

        if( a == x && b == y ) return 0;
        if( b == x && a == y ) return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;
    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        memset( dfa, 0, sizeof(dfa) );
        memset( cy, 0, sizeof(cy) );
        memset( dfa, 0, sizeof(dfa) );

        int i, j, x, y, n, m, z;
        LL c = 0, d = 0;

        cin >> n;

        for( i=1; i<=n; i++ )
        {
            mat[i].clear();
        }
        for( i=1; i<=n; i++ )
        {
            cin >> x >> y >> z;
            road[i][0] = x, road[i][1] = y;
            road[i][2] = z;
            mat[x].push_back( y );
            mat[y].push_back( x );
        }

        le = pos = 1;
        dfs(1);

        for( i=1; i<cl; i++ )
        {
            if( i == cl-1 ) x = fin( cy[i], cy[1] );
            else x = fin( cy[i], cy[i+1] );
            c += x;
        }

        for( i=cl-1; i>0; i-- )
        {
            if( i == 1 ) x = fin( cy[1], cy[cl-1] );
            else x = fin( cy[i], cy[i-1] );
            d += x;
        }

        c = min( c, d );
        d = 0;

        for( i=1; i<=n; i++ )
        {
            x = chk( road[i][0], road[i][1] );
            c += (x*road[i][2]);
        }

        cout << "Case " << ca++ << ": " << c << endl;
    }

    return 0;

}



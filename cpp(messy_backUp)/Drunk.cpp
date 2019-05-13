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
#define pb push_back
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

struct node
{
    int v, pa, st, e;
}dfa[100010];

vector<int> mat[100010];
int cr;

void dfs( int p )
{
        dfa[p].v = 1;

        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                dfs(x);
            }
            else if( dfa[x].v == 1 && dfa[x].e == 0 )
                cr = 1;

        }

        dfa[p].e = 1;
}

set<string>ms;
set<string>::iterator it;

struct info
{
    public:
    string f, s;
};

info ar[100010];
vector<string> vs;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int t, ca = 1;

    cin >> t;

    while(t--)
    {
        memset( dfa, 0, sizeof( dfa ) );
        cr = 0;
        int i, j, x, y, n, m;
        string str;

        cin >> m;

        for( i=0; i<m; i++ )
        {
            cin >> ar[i].f >> ar[i].s;
            ms.insert( ar[i].f );
            ms.insert( ar[i].s );
        }

        for( it = ms.begin(); it != ms.end(); it++ )
        {
            str = *it;
            vs.pb( str );
        }

        int st, en, mid, z;

        z = vs.size()-1;

        for( i=0; i<=z+1; i++ )
            mat[i].clear();

        for( i=0; i<m; i++ )
        {
            str = ar[i].f;
            st = 0;
            en = z;

            while( st <= en )
            {
                mid = ( st+en )/2;
                if( vs[mid] == str ) break;
                else if( str < vs[mid] ) en = mid-1;
                else st = mid+1;

            }
            x = mid+1;

            str = ar[i].s;
            st = 0;
            en = z;

            while( st <= en )
            {
                mid = ( st+en )/2;
                if( vs[mid] == str ) break;
                else if( str < vs[mid] ) en = mid-1;
                else st = mid+1;

            }

            y = mid+1;

            mat[x].pb( y );


        }

        for( i=1; i<=z; i++ )
        {
            if( dfa[i].v == 0 ) dfs( i );
        }

        while( !ms.empty() )
        {
            ms.erase( ms.begin() );
        }
        vs.clear();

        if( cr == 0 ) cout << "Case " << ca++ << ": Yes\n";
        else cout << "Case " << ca++ << ": No\n";
    }

    return 0;

}




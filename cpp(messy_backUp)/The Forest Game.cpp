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


set<int,int>::iterator ii;
set<int,int> ms;

struct node
{
    LL v, pa, l, r;
}dfa[100010];

vector<int> mat[100010], paa[100010];
int pos, ar[100010], val[100010];

void dfs( int p )
{
    if( dfa[p].v == 0 )
    {
        dfa[p].v = 1;
        ar[pos] = val[p];
        dfa[p].l = pos, pos++;
       // cout << p << ' ';
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( dfa[x].v == 0 )
            {
                //cout << p << ' ' << x << endl;
                paa[p].push_back(x);
                dfa[x].l = dfa[p].l;
                dfa[x].pa = p;
                dfs(x);
            }
        }
        ar[pos] = 0;
        dfa[p].r = pos, pos++;
        //cout << p << ' ';
    }
}


int que[100010], he, re;

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, c = 0;

    cin >> n ;

    for( i=1; i<=n; i++ )
        cin >> val[i], c += val[i];

    for( i=2; i<=n; i++ )
    {
        x = i;
        cin >> y;

        mat[x].push_back( y );
        mat[y].push_back( x );
    }

    dfs(1);
    ms.insert( 1, 0 );


    while( !ms.empty() )
    {
        cout << he << ' ' << re << endl;
        x = que[he];

        for( i=0; i<paa[x].size(); i++ )
        {
            que[re] = paa[x][i];
            re++;
        }
        he++;

    }

    cout << c << endl;
    return 0;

}




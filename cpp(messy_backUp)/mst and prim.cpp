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
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

struct node
{
    LL x, y, v;
};

vector<int> mat[100010], cost[100010];
int vis[100010];

class compare
{
public:
    bool operator()( node f, node s )
    {
        if( f.v > s.v )
            return true;
        else
            return false;
    }
};

priority_queue< node, vector<node>, compare > mq;

void prim( int p )
{
    LL a = 0, b, c;
    while( a == 0 || !mq.empty() )
    {
        a = 1;
        node nd;
        vis[p]++;
        nd.x = p;
        b = p;
        //cout << p << " = ";
        for( int i=0; i<mat[p].size(); i++ )
        {
            nd.y = mat[p][i];
            nd.v = cost[p][i];
            if( vis[nd.y] == 0 )
            {
                //cout << nd.y << '(' << nd.v <<") ";
                mq.push(nd);
            }
        }
        //cout << endl << p << "  =  ";
        while( vis[p] == 1 && !mq.empty() )
        {
            b = mq.top().x;
            p = mq.top().y;
            c = mq.top().v;
            mq.pop();
            //cout << p << ' ' << b << ' ' << c << ", ";
        }
        //cout << endl << endl;
        if(!mq.empty())
        cout << endl << b << ' ' << p << ' ' << c << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);

    inf;
    //outf;

    int i, j, x, y, n, m, v;
    node nd;

    cin >> n >> m;

    for( i=0; i<m; i++ )
    {
        cin >> x >> y >> v;
        mat[x].push_back(y);
        cost[x].push_back(v);
        mat[y].push_back(x);
        cost[y].push_back(v);
    }

    prim(1);

    return 0;

}



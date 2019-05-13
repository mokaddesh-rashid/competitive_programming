#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y, v;
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
    int a = 0, b, c;
    while( a == 0 || !mq.empty() )
    {
        a = 1;
        node nd;
        vis[p]++;
        nd.x = p;
        b = p;

        for( int i=0; i<mat[p].size(); i++ )
        {
            nd.y = mat[p][i];
            nd.v = cost[p][i];
            if( vis[nd.y] == 0 ) mq.push(nd);
        }
        while( vis[p] == 1 && !mq.empty() )
        {
            b = mq.top().x;
            p = mq.top().y;
            c = mq.top().v;
            mq.pop();
        }
        if(!mq.empty())
        cout << endl << b << ' ' << p << ' ' << c << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
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



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
    int f, x, y;
};
int pa[100010];
vector<int>mat[100010],cost[100010];
class compare
{
public:
    bool operator()(node x, node y)
    {
        if( x.f > y.f )
            return true;
        else
            return false;
    }
};

priority_queue<node,vector<node>, compare> p_q;

int f_pa( int x )
{
    if( pa[x] == x ) return x;
    else
    {
        pa[x] = f_pa(pa[x]);
        return pa[x];
    }
}

int main()
{
    ios::sync_with_stdio(false);

    inf;
    //outf;

    int i, j, x, y, n, m, a, b, c, t = 0;

    cin >> n >> m ;
    node nd;
    for( i=1; i<=n; i++ )
    {
        pa[i] = i;
    }
    for( i=0; i<m; i++ )
    {
        cin >> nd.x >> nd.y >> nd.f;
        p_q.push(nd);
    }
    cout << endl << endl;
    for( i=0; i<m; i++ )
    {
        //cout << p_q.top().f << ' ' << p_q.top().x << ' ' << p_q.top().y << endl;
        a = p_q.top().x;
        b = p_q.top().y;
        c = p_q.top().f;

        x = f_pa(a);
        y = f_pa(b);

        if( x != y )
        {
            cout << a << ' ' << b << ' ' << c << endl;
            pa[y] = x;
            mat[a].push_back(b);
            cost[a].push_back(c);
            mat[b].push_back(a);
            cost[b].push_back(c);
            t += c;
        }

        p_q.pop();
    }

    cout << t << endl;

    return 0;

}



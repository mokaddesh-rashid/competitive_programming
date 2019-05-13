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
typedef pair<string,int> sp;


//set<int>::iterator ii;

vector<int> mat[100010];
int vis[100010], mx = 0, in[100010];

void dfs( int x , int y )
{
    mx = max( mx, y );
    if( vis[x] == 0 )
    {
        vis[x] = 1;
        cout << x << ' ';
        for( int i=0; i<mat[x].size(); i++ )
        {
            int z = mat[x][i];

            if( vis[z] == 0 )
                dfs( z, y+1 );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, ma;
    sp pp;
    set< sp > m_s;
    set< sp >::iterator it, ii;
    m_s.insert(make_pair("polycarp",1));

    cin >> n;
    ma = n+2;
    for(int i=2; i<ma; i++ )
    {
        //cout << i << ' ';
        string f, s, t;
        cin >> f >> s >> t;
        x = f.size();
        y = t.size();
        n = max( x, y );
        for( j=0; j<n; j++ )
        {
            if( j < x && f[j] < 'a' )
            {
                //cout << f[j];
                f[j] += 32;
            }
            if( j < y && t[j] < 'a' )
            {
                t[j] += 32;
            }
        }

            //cout << f << ' ' << t << endl;
            m_s.insert(make_pair( f, i ));
            it = m_s.lower_bound(make_pair(t,0));
            pp = *it;
            x = pp.second;
            y = i;
            //cout << x << ' ' << y << endl;
            mat[x].push_back(y);
            mat[y].push_back(x);
      // cout << n << endl;
    }

    dfs( 1, 1 );

    cout << mx;

    return 0;

}



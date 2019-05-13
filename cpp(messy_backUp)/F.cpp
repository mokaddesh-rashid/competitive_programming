#include <bits/stdc++.h>
#include <stdio.h>
#include <bits/stdtr1c++.h>

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 110
#define clr(ar) memset(ar, 0, sizeof(ar))
#define inf freopen("in.txt", "r", stdin)
#define F first
#define S second

using namespace std;

typedef pair<int,int> PR;

/// 2 SAT (1 based index for variables)
/// Each variable can have two possible values (true or false)
/// Variables must satisfy a system of constraints on pairs of variables

namespace sat{
    bool visited[MAX * 2];
    vector <int> adj[MAX * 2], rev[MAX * 2];
    int n, m, l, dfs_t[MAX * 2], order[MAX * 2], parent[MAX * 2];

    inline int neg(int x){
        return ((x) <= n ? (x + n) : (x - n));
    }

    /// Call init once
    void init(int nodes){
        n = nodes, m = nodes * 2;
        for (int i = 0; i < n * 2 + 1; i++){
            adj[i].clear();
            rev[i].clear();
        }
    }

    /// Add implication, if a then b
    inline void add_implication(int a, int b){
        if (a < 0) a = n - a;
        if (b < 0) b = n - b;

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    inline void add_or(int a, int b){
        add_implication(-a, b);
        add_implication(-b, a);
    }

    inline void add_xor(int a, int b){
       // cout << a << ' ' << b << endl;
        add_or(a, b);
        add_or(-a, -b);
    }

    inline void add_and(int a, int b){
        add_or(a, b);
        add_or(a, -b);
        add_or(-a, b);
    }

    inline void add_xnor(int a, int b){
        add_or(-a, b);
        add_or(a, -b);
    }

    inline void add_V_To_C(int a, int b){
        add_or(a, b);
    }

    inline void add_C_To_V(int a, int b){
        add_or(-a, -b);
    }

    /// force variable x to be true (if x is negative, force !x to be true)
    inline void force_true(int x){
        if (x < 0) x = n - x;
        add_implication(neg(x), x);
    }

    /// force variable x to be false (if x is negative, force !x to be false)
    inline void force_false(int x){
        if (x < 0) x = n - x;
        add_implication(x, neg(x));
    }

    inline void topsort(int i){
        visited[i] = true;
        int j, x, len = rev[i].size();

        for (j = 0; j < len; j++){
            x = rev[i][j];
            if (!visited[x]) topsort(x);
        }
        dfs_t[i] = ++l;
    }

    inline void dfs(int i, int p){
        parent[i] = p;
        visited[i] = true;
        int j, x, len = adj[i].size();

        for (j = 0; j < len; j++){
            x = adj[i][j];
            if (!visited[x]) dfs(x, p);
        }
    }

    void build(){
        int i, x;
        clr(visited);
        for (i = m, l = 0; i >= 1; i--){
            if (!visited[i]){
                topsort(i);
            }
            order[dfs_t[i]] = i;
        }

        clr(visited);
        for (i = m; i >= 1; i--){
            x = order[i];
            if (!visited[x]){
                dfs(x, x);
            }
        }
    }

    /// Returns true if the system is 2-satisfiable and returns the solution (nodes set to true) in vector res
     bool satisfy(){
        build();
        clr(visited);

        for (int i = 1; i <= m; i++){
            int x = order[i];
            if (parent[x] == parent[neg(x)]) return false;

            if (!visited[parent[x]]){
                visited[parent[x]] = true;
                visited[parent[neg(x)]] = false;
            }
        }
        return true;
    }
}

using namespace sat;

string str, typ;
char a, b;
int u, v, val[MAX], ara[MAX], lal;
struct info
{
    int u, a, v, b;
}up[MAX*MAX*4];

void update(int n, int m)
{
    init( n );
    FOR(i,1,m)
    {
        u = up[i].u; a = up[i].a; v = up[i].v; b = up[i].b;

        if(a == b)
        {
            if(a == 'V') force_false( u ), force_false( v );
            else force_true( u ), force_true( v );
        }
        else if(a == 'V') add_V_To_C(u, v);/// cout << u << ' ' << v << endl;
        else add_C_To_V(u, v);
    }
}

int rec(int p,int root)
{
    if(p == lal) return -1;
    if(val[p] == root) return p;
    else return rec(p + 1, root);
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);

    int n, m, c = -1;
    cin >> typ; lal = typ.size();
    FOR(i,0,(int)typ.size()) val[i] = ('V' != typ[i]);
    cin >> n >> m;

    FOR(i,1,m)
    {
        cin >> u >> a >> v >> b;
        up[i] = {u, a, v, b};
    }

    cin >> str;
    FOR(i,0,n-1) ara[i + 1] = str[i] - 'a';


    FOR(i,0,n)
    {
        int v = rec(ara[i + 1] + 1, !val[ ara[i + 1] ]);
        cout << i << ' ' << v << endl;
        if(v != -1 || i == n)
        {
            update(n, m);

            FOR(j,1,i)
            {
                if(!val[ ara[j] ]) force_false( j );
                else force_true( j );
            }

            if(i == n) continue;
            else if(!val[v]) force_false( i + 1 );
            else force_true( i + 1 );

            if(satisfy()) c = max(c, i);
        }
    }
    cout << c << endl;

    if(c == -1) cout << -1 << endl;
    else if(c == n) cout << str << endl;
    else
    {
        int v = rec(ara[c + 1] + 1, !val[ ara[c + 1] ]);
        FOR(i,c+2,n) ara[i] = 0;

        c += 2;
        int p = c;
        cout << p << endl;
        while(p <= n)
        {
            update(n, m);
            FOR(j,1,p)
            {
                if(!val[ ara[j] ]) force_false( j );
                else force_true( j );
            }

            if(satisfy()) p++;
            else ara[p] = rec(ara[p] + 1, !val[ ara[p] ]);
        }

        FOR(i,1,n)
        {
            char ch = ara[i] + 'a';
            cout << ch;
        }
    }



    return 0;
}

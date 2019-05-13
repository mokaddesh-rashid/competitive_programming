#include <bits/stdc++.h>
#include <stdio.h>
#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 400010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
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

    inline void add_00(int a, int b){
        add_or(a, -b);
    }
    inline void add_01(int a, int b){
        add_or(a, b);
    }
    inline void add_10(int a, int b){
        add_or(-a, -b);
    }
    inline void add_11(int a, int b){
        add_or(-a, b);
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

struct info
{
    int u, v;
    char a, b;
}que[MAX], y;
int n, m, ty[MAX], l, up[MAX], val[MAX];

int update(int c)
{
    sat::init( n );

    FOR(i,0,m-1)
    {
        y = que[i];
        if(y.a == 'V' && y.b == 'V') sat::add_00(y.u, y.v);
        else if(y.a == 'V' && y.b == 'C') sat::add_01(y.u, y.v);
        else if(y.a == 'C' && y.b == 'V') sat::add_10(y.u, y.v);
        else if(y.a == 'C' && y.b == 'C') sat::add_11(y.u, y.v);
    }

    FOR(i,1,c)
    {
        if(!ty[ val[i] ]) sat::force_false( i );
        else sat::force_true( i );
    }

    return sat::satisfy();
}

string str;

int rec(int p,int col)
{
    //cout << p  << ' ' << col  << endl;
    if(p == l) return l;
    if(ty[p] == col) return p;
    else return rec(p + 1, col);
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;

    LL n = (1<<24) * 24;
    cout << n << endl;


    return 0;
}


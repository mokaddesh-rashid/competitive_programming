#include <bits/stdc++.h>

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
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int n, m;
vector<int> mat[MAX];
string str;
int col[MAX];
map<PR,int> mopa;

PR getVal(int u,int v)
{
    if(u > v) swap(u, v);
    return MP(u, v);
}

int rec(int p,int root,int ty)
{
    ///cout << p << ' ' << root << ' ' << ty << endl;
    if(ty == 3) return mopa[getVal(p, root)];

    int temp = 0;

    if(ty == 0)
    {
        if(col[p] != 1) return 0;

        for(auto x : mat[p])
        if(col[x] == 1 && !temp) temp = max(temp, rec(x, root, 1));
    }
    else if(ty == 1)
    {
        for(auto x : mat[p])
            if(col[x] == 2 && !temp) temp = max(temp, rec(x, root, 2));
    }
    else if(ty == 2)
    {
        for(auto x : mat[p])
            if(col[x] == 2 && !temp) temp = max(temp, rec(x, root, 3));
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
   // inf;
    //outf;
    int a, b;

    cin >> n >> m;
    cin >> str;
    FOR(i,0,n-1)
    {
        int x = str[i] - 'A'; x++;
        col[i + 1] = x;
    }

    FOR(i,0,m-1)
    {
        cin >> a >> b;
        mopa[getVal(a, b)] = 1;
        mat[a].PB( b );
        mat[b].PB( a );
    }

    FOR(i,1,n)
    {
        if(rec(i, i, 0))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}

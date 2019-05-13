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


vector<int> mat[MAX];
vector<int> leaf;

int dfs(int p,int pa)
{
    int chao = 1, chi = 0;

    for(auto x : mat[p])
    {
        if(x != pa) chao = min(chao, dfs(x, p)), chi++;
    }

    if(p != pa && chi > 1) chao = 0;
    if(chi == 0) leaf.PB(p);

    return chao;
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    int n, a, b, c;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> a >> b;
        mat[a].PB(b);
        mat[b].PB(a);
    }

    a = 1; b = mat[a].size();
    FOR(i,1,n)
        if(mat[i].size() > b) a = i, b = mat[i].size();

    if(dfs(a, a) == 0)
    {
         cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        cout << leaf.size() << endl;
        for(auto x : leaf)
        {
            cout << a << ' ' << x << endl;
        }
    }



    return 0;
}

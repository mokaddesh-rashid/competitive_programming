
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
#define MAX 1010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


stack<int> stk;
vector<int> mat[MAX];
int ti, can[MAX][MAX], st[MAX], vis[MAX], en[MAX], fr, ase[MAX];

void dfs(int p,int pa)
{
    ///cout<<p<<' ';
    int k, s;
    k = st[p] = ++ti;

    FOR(i,0,(int)mat[p].size()-1)
    {
        int x = mat[p][i];
        if(!st[x])
        {
            stk.push(x); ase[x] = 1;
            dfs(x,p);
        }
        else if(x != pa)
        {
            if(k > st[x]) k = st[x], s = x;
        }
    }

    if(k != st[p])
    {

        while(!stk.empty() && ase[s] == 1)
        {
            ///cout<<1<<NL;
            int a = stk.top();
            if(a == s) break;
            else stk.pop(), ase[a] = 0;
        }
    }

    en[p] = ++ti;

}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i, j, n, m, q, a, b;

    cin>>n>>m>>q;

    FOR(i,0,n-1)
    {
        cin>>a>>b;
        mat[a].PB(b);
        mat[b].PB(a);
    }

    FOR(i,1,n)
    {
        mem(st,0); mem(en,0); ti = 1;
        mem(vis,0); mem(ase,0); ase[i] = 1;
        dfs(i,i);

        while(!stk.empty())
        {
            a = stk.top();
            can[i][a] = 1;
            stk.pop();
        }
    }

     FOR(i,0,q-1)
    {
        cin>>a>>b;
        if(a == b) can[a][b] = 1;
        cout<<can[a][b]<<NL;
    }
    return 0;
}



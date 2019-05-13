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

int chi[MAX], cnt;
vector<int> mat[MAX];

void dfs(int p,int pa)
{
    int can = 0;

    chi[p] = 1;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x = mat[p][i];
        if(x != pa)
        {
            dfs(x, p);
            chi[p] += chi[x];
            if(chi[x] % 2 == 0) cnt++;
        }
    }
    return;
}



int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;

    int n, x, y;

    cin >> n;
    FOR(i,1,n-1)
    {
        cin >> x >> y;
        mat[x].PB( y );
        mat[y].PB( x );
    }

    if(n%2)
    {
        cout << -1 << endl;
        return 0;
    }

    FOR(i,1,n)
    {
        if((int)mat[i].size() == 1)
        {
            dfs(i, i);
            cout << cnt << endl;
            return 0;
        }
    }

    return 0;
}


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

priority_queue<int> sota;
vector<int> dp[MAX][MAX];
int n, k, ko, ar[MAX], br[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL c = 0, v, a;
    cin >> n >> k >> ko;
    FOR(i, 0, n-1)
    {
        cin >> ar[i];
    }
    FOR(i, 0, n-1)
    {
        cin >> br[i];
        sota.push( abs(ar[i] - br[i]) );
    }
    k += ko;

    while(k--)
    {
        int v = sota.top(); sota.pop();
        if(v) sota.push( v - 1);
        else sota.push( 1 );
    }

    while(!sota.empty())
    {
        v = sota.top();
        ///cout << v << endl;
        sota.pop();
        c += (v * v);
    }

    cout << c << endl;

    return 0;
}


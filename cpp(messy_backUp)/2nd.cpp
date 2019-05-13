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
int col[MAX], dude[MAX][4], can[MAX];
stack<int> stk;

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int a, b;

    cin >> n >> m;
    cin >> str;
    FOR(i,0,n-1)
    {
        int x = str[i] - 'A';
        col[i + 1] = x;
    }

    FOR(i,0,m-1)
    {
        cin >> a >> b;

        mat[a].PB( b ); dude[a][ col[b] ]++;
        mat[b].PB( a ); dude[b][ col[a] ]++;
    }

    FOR(i,1,n)
    {
        if(dude[i][0] && dude[i][1]) continue;

        stk.push( i );
        can[i] = 1;
    }

    while(!stk.empty())
    {
        int p = stk.top(); stk.pop();

        for(auto x : mat[p])
        {
            if(can[x]) continue;

            dude[x][ col[p] ]--;
            if(dude[x][0] && dude[x][1]) continue;

            stk.push( x );
            can[x] = 1;
        }
    }

    FOR(i,1,n)
    {
        if(can[i]) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}

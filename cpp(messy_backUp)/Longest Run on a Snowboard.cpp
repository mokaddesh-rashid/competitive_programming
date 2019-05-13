#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/
//set<int>::iterator ii;
//cout << fixed;
//cout << setprecision(9) << f << '\n';

int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
int dp[101][101], n, m, ar[101][101];
string str;

int rec(int x, int y)
{
    int a, b, c=1;
    if(dp[x][y]!=-1) return dp[x][y];
    FOR(i,0,3)
    {
        a=x+fx[i]; b=y+fy[i];
        if(a<0||b<0||a>=n||b>=m) continue;
        else if(ar[a][b]<ar[x][y]) c=max(c,1+rec(a,b));
    }
    return dp[x][y]=c;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        mem(dp,-1);
        int i, j, x=0, y;
        cin>>str;
        cin>>n>>m;

        FOR(i,0,n-1)
        FOR(j,0,m-1)cin>>ar[i][j];

        FOR(i,0,n-1)
        FOR(j,0,m-1)
        {
            x=max(x,rec(i,j));
            //cout<<i<<' '<<j<<' '<<
        }

        cout<<str<<": "<<x<<endl;
    }
    return 0;
}



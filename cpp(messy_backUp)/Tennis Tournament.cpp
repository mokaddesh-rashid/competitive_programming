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
#define MX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


int cnt[MX];
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    ans.clear();
    ans.PB(0);
    int i,n,m,k,x,y,z;

    cin>>n>>k>>m;
    x=1<<m; z=1<<n;
    FOR(i,1,x-1) ans.PB(i);
    ans.PB(k);
    REV(i,z,x)
    {
        if(i==k) continue;
        ans.PB(i);
    }

    if(x-1>=k||(k==z&&m!=n)) cout<<-1;
    else FOR(i,1,z) cout<<ans[i]<<' ';
    return 0;
}



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
#define MAX 40
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL dp[MAX];

LL rec(LL p)
{
    if(p<=2) return 1;
    if(dp[p]!=-1) return dp[p];

    return dp[p]=rec(p-1)+rec(p-2)+rec(p-3);
}

void prin(LL p,LL k)
{
    ///cout<<p<<' '<<k<<' '<<rec(p-1)<<' '<<rec(p-2)<<' '<<rec(p-3)<<NL;
    if(p<=2)
    {
        char ch=p+'a';
        cout<<ch<<NL;
        return;
    }
    LL a=k;
    if(rec(p-1)>=a) return prin(p-1,a);
    else a-=rec(p-1);

    if(rec(p-2)>=a) return prin(p-2,a);
    else a-=rec(p-2);

    return prin(p-3,a);

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    mem(dp,-1);
    LL i,j,n,m,k;

    cin>>n>>k;

    if(rec(n)<k) cout<<-1<<NL;
    else prin(n,k);
    return 0;
}



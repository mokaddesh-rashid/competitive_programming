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
#define MAX 100010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX],br[MAX],cnt[MAX],n,k;

void up()
{
    REV(l,31,0)
    {
        int c=0;
        FOR(i,0,n-1)if(ar[i]&(1<<l)) c++;
        //cout<<c<<NL;
        if(c>=k)
            FOR(i,0,n-1)if(!(ar[i]&(1<<l))) ar[i]=0,cnt[i]=-1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int i,j,c=-1;

    cin>>n>>k;
    FOR(i,0,n-1)cin>>ar[i],br[i]=ar[i];
    up();

    FOR(i,0,n-1)
    {
        if(cnt[i]==0&&k>0)
        {
            ///cout<<br[i]<<' ';
            k--;
            if(c==-1)c=br[i];
            else c=c&br[i];
        }
    }
    cout<<c<<NL;
    return 0;
}



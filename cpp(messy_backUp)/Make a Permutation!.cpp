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

int cnt[MAX],ar[MAX],br[MAX],np;

int
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,p;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>ar[i];
        cnt[ar[i]]++;
    }
    FOR(i,1,n)
    {
        if(cnt[i]==0)br[np++]=i;
    }

    p=0;
    FOR(i,0,n-1)
    {
        if(cnt[ar[i]]>1&&ar[i]<br[p])
        {
            cnt[ar[i]]--;
            ar[i]=br[p];
            cnt[ar[i]]++;
        }
    }

    FOR(i,0,n-1)
    {
        if(cnt[ar[i]]>1)
        {
            cnt[ar[i]]--;
            ar[i]=br[p];p++;
            cnt[ar[i]]++;
        }
    }

    cout<<p<<NL;
    FOR(i,0,n-1)cout<<ar[i]<<' ';
    return 0;
}



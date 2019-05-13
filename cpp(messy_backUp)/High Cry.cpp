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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[MAX],prv[MAX],cnt[MAX],prm[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(prv,-1);
    int i,j,n,m,a,b,c;
    LL d=0;

    cin>>n;
    FOR(i,0,n-1)cin>>ar[i];

    FOR(i,0,n-1)
    {
        b=a=0; c=i;
        FOR(j,i,n-1)
        {
            a=a|ar[j];
            b=max(b,ar[j]);
            c=j;

            if(b<a)cnt[j]=1;
            else cnt[j]=0;

            if(prv[j]==a&&prm[j]==b)break;
            prv[j]=a;
            prm[j]=b;
        }
        REV(j,c,i) cnt[j]=cnt[j]+cnt[j+1];
        ///cout<<cnt[i]<<NL;
        d+=cnt[i];
    }

    cout<<d<<NL;
    return 0;
}



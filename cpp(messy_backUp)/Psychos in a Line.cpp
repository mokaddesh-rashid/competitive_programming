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
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz], br[sz], va[sz], da[sz],sk[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,p=0,q,a,b,c=0;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];

    while(true)
    {
        c=0;
        FOR(i,0,n-1)
        {
            if(i==0)
            {
                br[c]=ar[i];
                da[c]=va[i];
                if(ar[i]>ar[i+1]&&i+1<n) da[c]=max(da[c]+1,va[i+1]);
                c++;
            }
            else if(ar[i]>ar[i-1])
            {
                br[c]=ar[i];
                da[c]=va[i];
                if(ar[i]>ar[i+1]&&i+1<n) da[c]=max(da[c]+1,va[i+1]);
                c++;
            }
            if(ar[i]>ar[i+1]&&i+1<n) da[c]=max(da[c]+1,va[i+1]+1);
        }
        if(c==n) break;
        n=c; j=0;
        FOR(i,0,n-1)
        {
           if(i==0) ar[j]=br[i], va[j]=da[i], j++;
           else
           {
               if(ar[j-1]>br[i]&&br[i]<br[i+1])
               {
                   va[j-1]=max(va[j-1]+1,da[i]);
                   continue;
               }
               va[j]=da[i];
               ar[j]=br[i]; j++;
           }
        }
        n=j;
        ///FOR(i,0,n-1) cout<<ar[i]<<' ';
        ///cout<<NL;
       // p++;
    }
    FOR(i,0,n-1)
    {
        p=max(p,va[i]);
    }
    cout<<p<<NL;
    return 0;
}

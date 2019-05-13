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
#define sz 110
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

pr ar[sz];
int ans[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c=0,k;

    cin>>n>>m; k=m;
    FOR(i,0,n-1)
    {
        cin>>ar[i].F;
        ar[i].S=i;
    }
    sort(ar,ar+n);
    FOR(i,0,n-1)
    {
       a=ar[i].F/2+(ar[i].F%2);
       ans[ar[i].S]+=a;
       k-=a;
    }
    if(k>0)
    {
        REV(i,n-1,0)
        {
           if( k > ar[i].F-ans[ar[i].S] )
           {
               k -= (ar[i].F-ans[ar[i].S]);
               ans[ar[i].S]=ar[i].F;
           }
           else
           {
              ans[ar[i].S]+=k;
              k=0;
           }

        }
    }

    if(k!=0) cout<<-1<<NL;
    else
    {
        FOR(i,0,n-1) cout<<ans[i]<<' ';
    }
    return 0;
}


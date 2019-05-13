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
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int cnt[sz], ar[sz];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,c=0,p=0,q=n-1;

    cin>>n>>m; m--;
    FOR(i,0,n-1) cin>>ar[i];

    if(ar[m]!=0) c++;
    ar[m]=mod;
    sort(ar,ar+n); n--;

    FOR(i,0,n-1) cnt[ar[i]]++;

    FOR(j,1,n)
    {
      if(cnt[j]==0) break;
      else p++;
    }

    FOR(i,0,n-1)
    {
      ///cout<<p<<' '<<ar[i]<<NL;
       while(cnt[p+1]!=0)
       {
            p++;
       }
       if(ar[i]==0)
       {
          FOR(j,max(p,1),n)
          {
              if(cnt[j]==0)
              {
                  cnt[j]++;
                  p=j; c++;
                  break;
              }
          }
       }
       else
       {
           while(p<ar[i]&&i<n)
           {
              if(cnt[p+1]==0) n--, p++, c++;
              else p++;
           }
       }
    }
    cout<<c<<NL;
    return 0;
}



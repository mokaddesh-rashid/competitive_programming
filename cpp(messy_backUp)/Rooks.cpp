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

int ar[30];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(ar,0);
        LL i,j,a,b,c,x,y,z,n,m;

        cin>>n>>m;

        a=n; b=m; c=1;
        FOR(i,1,m)
        {
          x=a*a; j=2;
          while(x>1)
          {
              while(x>1&&x%j==0)
              {
                  x/=j;
                  ar[j]++;
                  //cout<<j<<'+';
              }
              j++;
          }
          a--;
        }
        FOR(i,1,m)
        {
          x=i; j=2;
          while(x>1)
          {
              while(x>1&&x%j==0)
              {
                  x/=j;
                  ar[j]--;
                  //cout<<j<<'-';
              }
              j++;
          }
        }
        c=1;
        FOR(i,2,30)
        {
            ///cout<<i<<' '<<ar[i]<<NL;
            FOR(j,0,ar[i]-1)
            {
                c*=i;
            }
        }
        if(n<m) c=0;
        cout<<"Case "<<tt<<": "<<c<<NL;
    }
    return 0;
}



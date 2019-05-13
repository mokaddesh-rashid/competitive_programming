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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[400010], cnt[1000100];
pr con[400010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x=1, y, n, m, a=0;
    LL c=0;
    cin>>n>>m;
    FOR(i,0,n-1) cin>>ar[i], con[i].F=ar[i], con[i].S=i;
    sort(con,con+n);
    FOR(i,0,n-1)
    {
        if(i>0&&con[i].F!=con[i-1].F) x++;
        ar[con[i].S]=x;
    }
    //FOR(i,0,n-1) cout<<ar[i]<<' ';
    i=j=0;
    while(i<n||j<n)
    {
        if(j<n&&a==0)
        {
           x=ar[j]; cnt[x]++;
           if(cnt[x]==m) a++;
           j++;
        }
        else
        {
          x=ar[i];
          if(cnt[x]==m)a--;
          cnt[x]--;
          i++;
        }
        if(a>0) c+=(n-j+1);
        //cout<<i<<' '<<j<<' '<<a<<NL;
    }
    cout<<c<<NL;
    return 0;
}



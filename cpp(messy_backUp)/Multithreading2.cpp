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

int ar[100010], cnt[100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x=0,y=1,n,m;
    LL a=0;
    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,n-1)
    {
        while(cnt[y]==1)
        {
            y++;
        }
       if(y==ar[i]) x++, y++;
       else
       {
           //cout<<x<<NL;
           a+=(x+1);
           x=0;
       }
       cnt[ar[i]]=1;
    }
    cout<<a<<NL;
    return 0;
}

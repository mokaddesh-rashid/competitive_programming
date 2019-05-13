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
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,a,b,c,n=0,m,x,y;
    x=1; y=1;
    while(x<10000000)
    {
       cout<<x<<' ';
       ar[n]=x;
       y*=2;
       x+=y;
    }
    cout<<NL;
    FOR(i,1,100)
    FOR(j,i,100)
    {
        x=i^j; y=__gcd(i,j);
        if(x==y) cout<<i<<' '<<j<<NL;
    }
    return 0;
}


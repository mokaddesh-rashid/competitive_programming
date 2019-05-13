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

string str;
int ar[100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m=0,k,a,b,c,d,e,f,wa;
    cin>>n>>k;
    cin>>str;
    FOR(i,0,n-1)
    {
        if(str[i]=='0') ar[m]=i+1, m++;
    }
    cout<<m<<NL;
    wa=n;
    FOR(i,0,m-k-1)
    {
        a=ar[i]; b=ar[i+k];
        c=(a+b)/2;
        d=lower_bound(ar,ar+m,c)-ar; e=max(d--,0); f=min(m-1,d++);

        x=max(abs(ar[d]-ar[i]),abs(ar[i+k]-ar[d]));
        wa=min(wa,x);

        d=e;
        x=max(abs(ar[d]-ar[i]),abs(ar[i+k]-ar[d]));
        wa=min(wa,x);

        d=f;
        x=max(abs(ar[d]-ar[i]),abs(ar[i+k]-ar[d]));
        wa=min(wa,x);
    }
    cout<<wa<<NL;
    return 0;
}



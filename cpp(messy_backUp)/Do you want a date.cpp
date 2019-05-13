#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<LL,LL> pr;

LL fin_max(LL arr[], LL N)
{
    //  sorting array in decreasing order
    ///sort(arr, arr + N, greater<LL>());

    LL sum = arr[0];
    for (LL i = 1; i < N; i++)
    {
        sum = 2 * sum + arr[i];
        sum%=mod;
    }

    return sum;
}

LL fin_min(LL arr[], LL N)
{
    ///sort(arr, arr + N);
    LL sum = arr[0];
    for (LL i = 1; i < N; i++)
    {
        sum = 2 * sum + arr[i];
        sum %= mod;
    }

    return sum;
}

LL ar[300010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL n,p,q,r,a,b,c,x,y,z,k;
    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];
    x=fin_max(ar,n);
    y=fin_min(ar,n);
    x+=mod;
    cout<<(x-y)%mod<<NL;
    return 0;
}

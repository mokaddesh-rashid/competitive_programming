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
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[100010],t;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,n,m,k,a,b,c,z=-1;
    cin>>n>>k;

    if(k>1000000)
    {
        cout<<-1<<NL;
        return 0;
    }
    a=(k+1)*k; a/=2;
    x=sqrt(n);

    FOR(i,1,x)
    {
       if(n%i==0)
       {
           ar[t]=i; t++;
           ar[t]=n/i; t++;
       }
    }
    sort(ar,ar+t);

    FOR(i,0,t-1)
    {
        b=ar[i]*a;
        if(b<=n)
        {
            //cout<<ar[i]<<NL;
            c=(n-b)%ar[i];
            if(c==0) z=ar[i];
        }
    }

    if(z!=-1)
    {
        a=0; b=z;
        FOR(i,0,k-2)
        {
           cout<<b<<' ';
           a+=b;
           b+=z;
        }
        cout<<n-a<<NL;
    }
    else cout<<z<<NL;
    return 0;
}

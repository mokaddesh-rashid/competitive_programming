#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
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

vector<LL>mv;
LL l, r, c;
LL ar[55];
void rec(LL n,LL a,LL b,int p)
{
    //cout<<n<<' '<<a<<' '<<b<<endl;
    LL x, y, z;
    x=(a+b)/2;
    if(a>r||b<l) return;
    //cout<<n<<' '<<a<<' '<<b<<endl;
    if(n==0||n==1)
    {
        if(n==1) c++;
        return;
    }
    rec(n/2,a,a+ar[p-1]-1,p-1);
    rec(n%2,a+ar[p-1],a+ar[p-1],p-1);
    rec(n/2,a+ar[p-1]+1,b,p-1);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    c=0;
    FOR(t,1,51)
    {
        if(t==1) ar[t]=1;
        else ar[t]=ar[t-1]+ar[t-1]+1;
    }
    LL n, i, j, x, y, z, a, b;
    cin>>n;
    x=log(n)/log(2); x++;
    a=1; b=ar[x];
    cin>>l>>r;
    rec(n,a,b, x);
    cout<<c<<NL;
    return 0;
}



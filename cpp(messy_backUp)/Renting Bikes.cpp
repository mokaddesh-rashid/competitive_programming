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

LL ar[sz],cr[sz],n,m,c;

LL chk(LL v)
{
    LL i,j,a,x,y,z,ol[sz];

    x=c; y=0; j=0;
    REV(i,v-1,0)
    {
        y+=cr[i];
        if(ar[j]<cr[i]) x-=(cr[i]-ar[j]), y-=(cr[i]-ar[j]);
        j++;
    }
    if(x<0) return -1;
    else return max((LL)0,y-x);
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,a,b,z,s=0,t=0,st,en,mid;

    cin>>n>>m>>c;
    FOR(i,0,n-1) cin>>ar[i];
    FOR(i,0,m-1) cin>>cr[i];

    sort(ar,ar+n,greater<LL>());
    sort(cr,cr+m);

    st=0; en=min(n,m);
    while(st<=en)
    {
        mid=(st+en)>>1;
        x=chk(mid);
        ///cout<<mid<<' '<<x<<NL;
        if(x<0) en=mid-1;
        else
        {
            st=mid+1;
            if(mid>s)
            {
                s=mid;
                t=x;
            }
        }
    }

    cout<<s<<' '<<t<<NL;
    return 0;
}



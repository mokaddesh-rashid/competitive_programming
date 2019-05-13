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

LL n,s,ar[sz];

LL chk(LL v)
{
   LL a,b,c=0,d,x,y,z,val[sz];

   FOR(i,0,n-1)
   {
       val[i]=ar[i]+(i+1)*v;
   }
   sort(val,val+n);
   FOR(i,0,v-1) c+=val[i];

   if(c<=s) return c;
   else return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,x,y,m,st,en,mid,z,a,b=0,c=0;

    cin>>n>>s;
    FOR(i,0,n-1) cin>>ar[i];

    st=1; en=n;

    while(st<=en)
    {
        mid=(st+en)/2;

        a=chk(mid);

        if(a!=-1)
        {
            if(mid>c) c=mid, b=a;
            st=mid+1;
        }
        else en=mid-1;
    }

    cout<<c<<' '<<b<<NL;
    return 0;
}



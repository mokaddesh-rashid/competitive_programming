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
#define sz 200010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL ar[sz],blah;
LL n,l,A,B;

LL chk(LL v)
{
   LL a,b,c=0,x,y,z;
   FOR(i,0,n-1)
   {
       x=abs(v-ar[i]);
       c+=x; v+=l;
   }
   v-=l;
   if(v<=B) return c;
}

int main()
{
    ios::sync_with_stdio(false);
//    inf;
//    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i,j,x,y,z=maxx;
        LL a,b,c,st,en,mid1, mx=0, mid2,p,q;

        cin>>n>>l>>A>>B;
        FOR(i,0,n-1) cin>>ar[i];
        sort(ar,ar+n);

        st=A; en=B-(n*l);
        FOR(i,0,100)
        {
            mid1=st+(en-st)/3; mid2=en-(en-st)/3;

            b=chk(mid1); c=chk(mid2);
            z=min(z,b); z=min(z,c);

            if(b<c) en=mid2;
            else st=mid1;
        }
        cout<<z<<NL;
    }
}

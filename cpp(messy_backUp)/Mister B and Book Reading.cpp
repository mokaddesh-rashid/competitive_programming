#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
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
#define sz 2000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

LL ar[sz], n, id[sz];

LL chk(int p)
{
    LL a,b,c=0,m=p+n-1;

    LL j=1;
    FOR(i,p,m)
    {
       c+=abs(ar[i]-j);
       j++;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i,j,st,mid1,en,mid2;
        LL x=maxx,a,b,c,id,y;

        cin>>n;
        FOR(i,0,n-1)
        {
           cin>>ar[i];
           ar[i+n]=ar[i];
        }

        st=1; en=n;
        while(st<=en)
        {
            y=(en-st)/3;
            mid1=st+y; mid2=mid1+y;
            a=chk(mid1);
            b=chk(mid2);
            ///cout<<mid1<<' '<<mid2<<' '<<a<<' '<<b<<NL;
            if(a<b) en=mid2-1;
            else st=mid1+1;
            if(b<x)
            {
               x=b;
               id=mid2;
            }
            if(a<x)
            {
                x=a;
                id=mid1;
            }
        }
//        FOR(i,max(id-50,(LL)0),id+50)
//        {
//            if(i>n) break;
//            a=chk(i);
//            if(a<x)
//            {
//                x=a;
//                id=i;
//            }
//        }
        cout<<x<<' '<<n-id<<NL;
    }
    return 0;
}



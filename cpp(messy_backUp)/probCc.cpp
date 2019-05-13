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
typedef pair<LL,LL> pr;


set<pr>::iterator ii;
set<pr>ms;

LL ar[100010], nd[10000];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    while(!ms.empty())
    {
        ms.erase(ms.begin());
    }
    LL i, j, x=0, y, n, m=0, c=0, a, b, k, d=1;
    cin>>n>>k;
    FOR(i,0,n-1) cin>>ar[i];
    if(k==-1)
    {
      nd[0]=1;
      nd[1]=-1;
      m=2;
    }
    else if(k==1)
    {
      nd[0]=1;
      m=1;
    }
    else
    {
        m=0;a=1;
        while(true)
        {
           //cout<<"OK"<<NL;
           nd[m]=a;
           m++; a*=k;
           if(a>100000000000000||m>52||a<-100000000000000) break;
        }
    }
    pr chk;
    x=0;
    ms.insert(MK((LL)0,(LL)1));
    FOR(i,0,n-1)
    {
        x+=ar[i];
        FOR(j,0,m-1)
        {
            a=x-nd[j];
            ii=ms.lower_bound(MK(a,0));
            chk=*ii;
            if(ii==ms.end()) continue;
            //if(chk.F==a)cout<<a<<' '<<chk.F<<' '<<chk.S<<NL;
            if(chk.F==a) c+= chk.S;
        }
        ii=ms.lower_bound(MK(x,0));
        chk=*ii;
        //cout<<x<<' '<<chk.F<<' '<<chk.S<<NL;
        if(x==chk.F&&ms.end()!=ii)
        {
            a=chk.S;
            ms.erase(ii);
            //cout<<chk.F<<' '<<chk.S<<NL;
            ms.insert(MK(x,a+1));
        }
        else
        {
            //cout<<x<<'k'<<1<<NL;
            ms.insert(MK(x,1));
        }
    }
    cout<<c<<NL;
    return 0;
}



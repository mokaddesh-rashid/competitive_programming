#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
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
typedef pair<LL,LL> pr;

pr ar[100010];
LL n, k, px, py;
LL up()
{
    LL mn=1, mx=n;
    FOR(i,0,k-1)
    {
        if(py==ar[i].S&&px>ar[i].F) mn=max(mn,ar[i].F+1);
        if(py==ar[i].S&&px<ar[i].F) mx=min(mx,ar[i].F-1);
    }
    //cout<<mn<<' '<<mx<<endl;
    return (px-mn)+(mx-px);
}
LL side_up()
{
    LL mn=1, mx=n;
    FOR(i,0,k-1)
    {
        if(px==ar[i].F&&py>ar[i].S) mn=max(mn,ar[i].S+1);
        if(px==ar[i].F&&py<ar[i].S) mx=min(mx,ar[i].S-1);
    }
    //cout<<mn<<' '<<mx<<endl;
    return (py-mn)+(mx-py);
}
LL con_up()
{
    LL a, b, c=10000000, d=10000000, x, y, re=0;
    ///left up con
    FOR(i,0,k-1)
    {
      a=ar[i].F; b=ar[i].S;
      if((a<px&&b<py)&&(px-a)==(py-b)&&(px-a-1)<d)
      {
          d=px-a-1;
      }
    }
    if(d==10000000) d=min(px,py)-1;
    re+=d;
    //cout<<d<<endl;
    ///rig up con
    d=10000000;
    FOR(i,0,k-1)
    {
      a=ar[i].F; b=ar[i].S;
      if((a<px&&b>py)&&(px-a)==(b-py)&&(px-a-1)<d)
      {
          d=px-a-1;
      }
    }
    if(d==10000000) d=min(px-1,n-py);
    re+=d;
    //cout<<d<<endl;
    ///rig dw con
    d=10000000;
    FOR(i,0,k-1)
    {
      a=ar[i].F; b=ar[i].S;
      if((a>px&&b<py)&&(a-px)==(py-b)&&(py-b-1)<d)
      {
          d=py-b-1;
      }
    }
    if(d==10000000) d=min(py-1,n-px);
    re+=d;
    //cout<<d<<endl;
    ///lft dw
    d=10000000;
    FOR(i,0,k-1)
    {
      a=ar[i].F; b=ar[i].S;
      if((a>px&&b>py)&&(a-px)==(b-py)&&(a-px-1)<d)
      {
          d=a-px-1;
      }
    }
    if(d==10000000) d=min(n-px,n-py);
    re+=d;
    //cout<<d<<endl;
    return re;

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i, j, x=0, y;
    cin>>n>>k;
    cin>>px>>py;
    FOR(i,0,k-1) cin>>ar[i].F>>ar[i].S;
    x = up();
    //cout<<x<<endl;
    x += side_up();
    //cout<<x<<endl;
    x += con_up();
    cout<<x<<endl;
    return 0;
}



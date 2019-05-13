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
#define sz 1000010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

vector<int> mat[sz];
int in[sz],ans[sz],tk[sz],f,s;
pr ar[sz];
struct node
{
    int l, r, p;
}qr[sz];
int block;

class compare
{
public:
    bool operator()( node f, node s )
    {
      if( f.l/block != s.l/block ) return f.l/block < s.l/block;
      return f.r < s.r;
    }
};

void up(int x,int a,int b)
{
    int c,d;
    if((x<a||x>b)&&tk[x]==1)
    {
        c=ar[x].F; d=ar[x].S;
        if(in[c]==1) f--;
        if(in[d]==1) f--;

        if(in[c]==2) s--;
        if(in[d]==2) s--;

        in[c]--; in[d]--; tk[x]=0;
    }
    if((a<=x&&x<=b)&&tk[x]==0)
    {
        c=ar[x].F; d=ar[x].S;
        if(in[c]==0) f++;
        if(in[d]==0) f++;

        if(in[c]==1) s++;
        if(in[d]==1) s++;

        in[c]++; in[d]++; tk[x]=1;
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,n,m,a,b,c=0,q;

    sff(n,m);///cin>>n>>m;
    FOR(i,0,m-1) sff(ar[i].F,ar[i].S);
    sf(q);///cin>>q;
    ///cout<<"OWK:"<<q<<NL;
    FOR(i,0,q-1)
    {
        sff(qr[i].l,qr[i].r);
        qr[i].l--; qr[i].r--;
        qr[i].p=i;
    }
    block=sqrt(m);
    sort(qr,qr+q,compare());

    x=y=0; a=b=0; f=s=0;
    FOR(i,0,q-1)
    {
        a=qr[i].l; b=qr[i].r;
        ///cout<<a<<' '<<b<<NL;
        while(true)
        {
            up(x,a,b);
            if(x==a) break;
            else if(x>a) x--;
            else x++;
        }
        while(true)
        {
            up(y,a,b);
            if(y==b) break;
            else if(y>b) y--;
            else y++;
        }
        c=qr[i].p;
        if(f==s) ans[c]=1;///,cout<<"yes"<<NL;
        else ans[c]=0;///,cout<<"no"<<NL;
        ///cout<<c<<' '<<f<<' '<<s<<' '<<x<<' '<<y<<NL;
    }
    FOR(i,0,q-1)
    {
        if(ans[i]==1) pf("Yes\n");
        else pf("No\n");
    }
    return 0;
}



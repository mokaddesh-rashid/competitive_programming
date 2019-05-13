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

vector<int> tim[sz];

int nex(int p,int c)
{
    int i,j,n,x,y,st,en,mid,a,b;

    n=tim[p].size();

    st=0; en=n-1; x=-1;
    while(st<=en)
    {
        mid=(st+en)>>1;
        if(tim[p][mid]==c)
        {
          x=mid;
          break;
        }
        else if(tim[p][mid]<c) st=mid+1;
        else en=mid-1;
    }

    if(x==-1) return x;

    st=x; en=n-1; y=x;
    while(st<=en)
    {
        mid=(st+en)>>1;
        a=tim[p][mid]; b=tim[p][x];
        cout<<a<<' '<<b<<' '<<mid<<' '<<x<<NL;
        if(a-b==mid-x)
        {
            st=mid+1;
            y=max(y,tim[p][mid]);
        }
        else en=mid-1;
    }

    return y;

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c,k;
    cin>>n;
    FOR(i,1,n)
    {
        cin>>k;
        FOR(j,1,k)
        {
            cin>>a;
            if(tim[i].size()==0)tim[i].PB(a);
            else if(a!=tim[i][(int)tim[i].size()-1]) tim[i].PB(a);
        }
    }

    FOR(i,1,100)
    {
        cin>>a>>c;
        cout<<nex(a,c)<<NL;
    }
    return 0;
}



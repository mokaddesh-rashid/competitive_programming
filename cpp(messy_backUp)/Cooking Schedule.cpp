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

int on[1000010], ze[1000010],n,m,eo[1000010],ez[1000010];
string str;

int chk(int x)
{
    //mem(eo,0); mem(ez,0);
    int a,b,c=0,d,p=-1;
    FOR(i,0,n-1)
    {
        if(p>i) continue;
        else if(i+x>=n) break;
        if(i==0) a=on[x], b=ze[x];
        else
        {
            a=on[x+i]-on[i-1]; b=ze[x+i]-ze[i-1];
        }
        if(a>x)
        {
            on[x+i]+=1; ze[x+i]-=1;
            p=x+i;
            c++;
        }
        else if(b>x)
        {
            on[x+i]-=1; ze[x+i]+=1;
            p=x+i;
            c++;
        }
    }
    if(c>m) return 0;
    else return 1;
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
        int i,j,x=0,y=0,z,st,en,mid,a,b,c;

        cin>>n>>m;
        cin>>str;
        FOR(i,0,n-1)
        {
            if(str[i]=='0') x++;
            else y++;
            on[i]=y; ze[i]=x;
        }
        st=1; a=en=n;
        while(st<=en)
        {
            mid=(st+en)/2;
            x=chk(mid);
            if(x==1) en=mid-1, a=min(a,mid);
            else st=mid+1;
        }
        cout<<a<<NL;
    }
    return 0;
}

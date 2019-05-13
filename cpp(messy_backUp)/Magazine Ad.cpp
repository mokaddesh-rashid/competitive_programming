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

string str;
int ar[100010],t,k,n;

int chk(int v)
{
    int a,b,c=0;
    int x=0;
    while(x<n)
    {
        a=lower_bound(ar,ar+t,x+v)-ar;
        c++;
        b=ar[a];
        if(a==t) break;
        if(b-x>v) a--;
        x=ar[a];
    }
    if(c>k) return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x,y,m,st=0,en,mid,a,b,c;

    cin>>k;

    cin.ignore();
    getline(cin,str);
    n=str.size();

    ar[0]=0; t=1;
    FOR(i,0,n-1)
    {
       if(str[i]==' '||str[i]=='-') ar[t]=i+1, st=max(ar[t]-ar[t-1],st), t++;
    }
    ar[t]=n; st=max(ar[t]-ar[t-1],st); t++;

    c=en=n;
    while(st<=en)
    {
        mid=(st+en)/2;
        a=chk(mid);
        if(a==1) en=mid-1, c=min(c,mid);
        else st=mid+1;
    }
    cout<<c<<NL;

    return 0;
}

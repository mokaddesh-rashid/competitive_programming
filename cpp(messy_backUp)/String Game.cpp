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
typedef pair<int,int> pr;

string s, t;
int ar[200010], cnt[200010];

int chk(int v)
{
    mem(cnt,0);
    FOR(i,0,v) cnt[ar[i]]=1;
    int i,j,n,m,a,b,c;
    n=s.size(); m=t.size();
    j=0;
    FOR(i,0,n-1)
    {
        if(cnt[i]==0&&s[i]==t[j]) j++;
        if(j==m) return 1;
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,x=-1,y,n,m,a,b,c;
    cin>>s>>t;
    n=s.size();
    FOR(i,0,n-1)
    {
        cin>>a; a--;
        ar[i]=a;
    }
    int st=0, mid, en=n-1;
    while(st<=en)
    {
        mid=(st+en)/2;
        y=chk(mid);
        //cout<<mid<<' '<<y<<NL;
        if(y==1) st=mid+1, x=max(x,mid);
        else en=mid-1;
    }
    cout<<x+1;
    return 0;
}



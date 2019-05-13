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
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[1000010],cnt[1000010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        mem(cnt,0);
        int i,j,a,b,c,x,y,z,n,m;
        a=b=c=x=y=0;
        cin>>n>>m;
        FOR(i,0,n-1)
        {
            cin>>z; a=0;
            FOR(j,0,z-1)
            {
                cin>>x;
                if(cnt[x]==0) a=1,c++,cnt[x]=1;
            }
            if(a==0) y=1;
        }
        cout<<c<<NL;
        if(c!=m) cout<<"sad"<<NL;
        else if(y==1) cout<<"some"<<NL;
        else cout<<"all"<<NL;
    }
    return 0;
}




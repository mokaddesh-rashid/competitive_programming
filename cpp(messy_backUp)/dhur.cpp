#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
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
typedef pair<int,int> pr;

int n,ar[100][10], vis[100], ans, stk[1000], top;

void rec(int x)
{
    if(top==3)
    {
        int a, b, c, d;
        a=stk[0]; b=stk[1]; c=stk[2];
        //cout<<a<<' '<<b<<' '<<c<<endl;
        if(ar[a][0]==-1||ar[b][1]==-1||ar[c][2]==-1) return;
        d=ar[a][0]+ar[b][1]+ar[c][2];
        ans=min(ans,d);
        return;
    }

    FOR(i,1,n)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            stk[top]=i; top++;
            rec(i);
            top--;
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    ans=1000000;
    mem(ar,-1);
    int i, j, x, y, m, a, b, c;
    cin>>n>>m;
    string str;
    FOR(i,1,n)
    {
        a=b=c=-1;
        cin>>str;
        x=str.size();
        FOR(j,0,x-1)
        {
            if(str[j]>='a'&&str[j]<='z'&&a==-1) a=j;
            if(str[j]>='0'&&str[j]<='9'&&b==-1) b=j;
            if((str[j]=='#'||str[j]=='*'||str[j]=='&')&&c==-1) c=j;
        }
        y=1;
        REV(j,x-1,0)
        {
            if(str[j]>='a'&&str[j]<='z') a=min(y,a);
            if(str[j]>='0'&&str[j]<='9') b=min(y,b);
            if(str[j]=='#'||str[j]=='*'||str[j]=='&') c=min(y,c);
            y++;
        }
        //cout<<a<<' '<<b<<' '<<c<<endl<<endl;
        ar[i][0]=a; ar[i][1]=b; ar[i][2]=c;
    }
    rec(1);
    cout<<ans<<endl;
    return 0;
}



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
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LL,LL> pr;

struct node
{
    LL sum, way;
    node()
    {
        sum=way=0;
    }
};
node dp[17][35000];
LL n, mx, ar[20], lim;

node rec(LL p, LL bt)
{
    node lele, temp;
    LL pap=p-1;
    if(bt==lim)
    {
        lele.sum=n+n+ar[pap];
        lele.way=1;
        return lele;
    }
    if(dp[p][bt].sum!=-1)return dp[p][bt];
    FOR(i,0,n-1)
    {
        LL a=(bt&(1<<i));
        if(a==0)
        {
            LL bit=bt|(1<<i);
            if(p==0)
            {
                lele = rec(i+1,bit);
                lele.sum=ar[i]+lele.sum;
                if(lele.sum>temp.sum) temp=lele;
                else if(lele.sum==temp.sum) temp.way+=lele.way;
            }
            else
            {
                LL y=max(ar[pap]-ar[i],ar[i]-ar[pap]);
                lele = rec(i+1,bit);
                lele.sum=y+lele.sum;
                if(lele.sum>temp.sum) temp=lele;
                else if(lele.sum==temp.sum) temp.way+=lele.way;
            }
        }
    }
    return dp[p][bt]=temp;
}

int main()
{
    ios::sync_with_stdio(false);
    while(true)
    {
        mem(dp,-1);
        lim=0;
        LL i, j, x, y;
        cin >> n;
        if(n==0)break;
        FOR(i,0,n-1) lim=lim|(1<<i);
        FOR(i,0,n-1) cin>>ar[i];
        node shimlin=rec(0,0);
        cout<<shimlin.sum<<' '<<shimlin.way<<endl;
    }
    return 0;
}

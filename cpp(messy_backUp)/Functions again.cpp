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

int ar[200010], sm[200010], sp[200010];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i, j, x, y, n, m,a=0,b=0,c=0,d;
        cin>>n;
        FOR(i,0,n-1)
        {
            cin>>ar[i];
            if(i>0) sm[i]=abs(ar[i]-ar[i-1]);
            //cout<<sm[i]<<' ';
        }
        //cout<<NL;
        x=0;
        FOR(i,1,n-1)
        {
            if(i%2)x+=sm[i];
            else x-=sm[i];
            x=max((LL)0,x);
            c=max(c,x);
        }
        x=0;
        FOR(i,1,n-1)
        {
            if(i%2==0)x+=sm[i];
            else x-=sm[i];
            x=max((LL)0,x);
            c=max(c,x);
        }
        cout<<c<<NL;
    }
    return 0;
}



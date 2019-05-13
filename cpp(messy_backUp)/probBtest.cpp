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

int ar[10010];

int retMax(int st,int en)
{
    int mx;
    FOR(i,st,en)
    {
        if(st==i) mx=ar[i];
        else mx=max(ar[i],mx);
    }
    FOR(i,st,en)
    {
        if(mx==ar[i]) return i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        int i, j, x, y, n, m, a, b, c, d;
        cin>>n;
        FOR(i,1,n) cin>>ar[i];
        if(n<11) cout<<"Case "<<tt<<": go home!"<<NL;
        else
        {
            cout<<"Case "<<tt<<": ";
            a=1;b=n-10;
            FOR(i,1,11)
            {
                a=retMax(a,b);
                cout<<ar[a]<<' ';
                a++;
                b++;
            }
            cout<<NL;
        }
    }
    return 0;
}



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

string str;
LL ar[1000010], en, pos[1000];

LL add(LL x, LL a)
{
    LL z=1;
    while(z<=a)
    {
        z*=10;
        x*=10;
    }
    x+=a;
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        LL i, j, x, y, n, m, a, b, c;
        cin>>a>>n>>m;
        en=0; x=a;
        while(true)
        {
            //cout<<x<<' ';
            x%=m;
            //cout<<x<<endl;
            if(x==ar[0]) break;
            ar[en]=x; en++;
            if(en==n) break;
            x=add(x,a);
        }
        if(en==0) ar[0]=0, n=1;
        else if(n%en==0) n=en;
        else n=n%en;
        cout<<ar[n-1]<<endl;
    }
    return 0;
}
/*
5
3 29541 26129
31 27813 29174
98 6077 20215
98 8213 23992
69 5601 23392
*/

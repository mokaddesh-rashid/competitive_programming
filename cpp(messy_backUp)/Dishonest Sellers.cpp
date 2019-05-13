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

class Compare
{
public:
    bool operator()(pr x, pr y)
    {
        return (x.F-x.S)<(y.F-y.S);
    }
};
pr ar[100010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x=0, y, n, m, k;
    LL c=0;
    cin>>n>>k;
    FOR(i,0,n-1) cin>>ar[i].F;
    FOR(i,0,n-1) cin>>ar[i].S;
    sort(ar,ar+n,Compare());
    FOR(i,0,n-1)
    {
        //cout<<ar[i].F<<' '<<ar[i].S<<NL;
        if(i<k) c+=ar[i].F;
        else c+=(min(ar[i].F,ar[i].S));
    }
    cout<<c<<NL;
    return 0;
}
/*
5 3
3 4 7 10 3
4 5 5 12 5
*/


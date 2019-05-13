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

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, c=0, b, a;
    n=10000;
    FOR(i,2,10000)
    {
        a=log(i)/log(2);
        FOR(j,i,10000)
        {
            b=log(j)/log(2);
            if(a+1<b) break;

            x=__gcd(i,j); y=i^j;
            if(x==y) c++;
            if((x==y)&&(a<b)) cout<<i<<' '<<j<<NL;

        }
    }
    cout<<c<<NL;
    return 0;
}



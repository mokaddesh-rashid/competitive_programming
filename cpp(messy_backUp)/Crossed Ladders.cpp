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

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int t;
    cin >> t;
    FOR(tt,0,t-1)
    {
        int i, j;
        long double a, b, c, ad, ae, de, g, s, p, cmp, e , f, chk, low, high, mid, x, y, z;

        cin >> x >> y >> c;

        low = 0;
        high = x;
        FOR(i,0,100)
        {
            mid = (low+high)/2;
            a = (x*x)-(mid*mid); b = (y*y)-(mid*mid);
            a = sqrt(a); b = sqrt(b);
            z = (a*b)/(a+b);
            if( z > c ) low = mid;
            else high = mid;
        }
        cout << "Case " << tt+1 <<": ";
        cout << fixed;
        cout << setprecision(9) << mid << endl;
    }
    return 0;
}


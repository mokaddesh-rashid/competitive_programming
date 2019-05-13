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
        int i, j, x, y, n, m;
        long double a, b, c, ad, ae, de, g, s, p, cmp, e , f, chk, low, high, mid;

        cin >> a >> b >> c >> cmp;

        p = (a+b+c)/2;
        s = p*(p-a)*(p-b)*(p-c);
        s = sqrt(s);

        low = 0;
        high = a;
        FOR(i,0,100)
        {
            ad = mid =(low+high)/2;
            ae = (b*mid)/a;
            de = (c*mid)/a;
            p = (ad+ae+de)/2;
            g = p*(p-ad)*(p-ae)*(p-de);
            g = sqrt(g);
            f = (s-g);
            chk = g/f;

            if( chk > cmp ) high = mid;
            else low = mid;

        }
        cout << "Case " << tt+1 <<": ";
        cout << fixed;
        cout << setprecision(9) << mid << endl;
    }
    return 0;
}


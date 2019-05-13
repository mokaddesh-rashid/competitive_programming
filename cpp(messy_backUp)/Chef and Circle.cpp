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
#define LD           long double
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<LD,LD> pr;

LD ar[1000010], aq[100010];
pr pp[1000];
int main()
{
    ios::sync_with_stdio(false);
    int i, j, n, m, chk = 0, p;
    LD a, b, c, d, e, x, y;
    cin>>n>>m;
    FOR(i,0,n-1) cin>>pp[i].F>>pp[i].S;
    FOR(i,0,n-1)
    {
        FOR(j,0,n-1)
        {
            x = (LD)((pp[i].F+pp[j].F)/2);
            y = (LD)((pp[i].S+pp[j].S)/2);
            p = 0;
            cout << endl << x << ' ' << y << endl;
            FOR(k,0,n-1)
            {
               a = (x-pp[k].F)*(x-pp[k].F);
               b = (y-pp[k].S)*(y-pp[k].S);
               cout << a << 'k' << b << endl;
               d = sqrt(a+b);
               aq[p] = d; p++;
            }
            sort(aq, aq+n);
            FOR(k,0,n-1) cout << aq[k] << ' ';
            cout << endl;
            if(chk==0) e = aq[m-1], chk = 1;
            else e = min( e,aq[m-1]);
        }
    }
    cout << e << endl;
    return 0;
}



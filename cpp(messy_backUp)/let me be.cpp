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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL            unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 300010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;


pr ar[MAX], in[MAX];
LL sum[MAX], prin;


int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n, a, b;
    LL c = 0, d, e;

    sf(n);//cin >> n >> a >> b;
    sff(a, b);
    FOR(i,0,n-1)
    {
        sff(ar[i].F, ar[i].S);
        ///cin >> ar[i].F >> ar[i].S;
        if(ar[i].F > ar[i].S) in[i].F = ar[i].F - ar[i].S;
        else  in[i].F = 0;
        in[i].S = i;
    }

    sort(in, in + n, greater<pr>());

    FOR(i,0,n-1)
    {
        int p = in[i].S;

        if(i < b) c += max(ar[p].F, ar[p].S);
        else c += ar[p].S;
    }

    d = prin = c;
    ///cout << prin << endl;

    if(b)
    FOR(i,0,n-1)
    {
        int p = in[i].S;

        if(i < b)
        {
            c -= max(ar[p].F, ar[p].S);
            e = ar[p].F;
            FOR(j,1,a)
            {
                e = e + e;
            }
            c += e;
            prin = max(prin, c);
        }
        else
        {
            c -= ar[p].S;

            int po = in[b - 1].S;
            c -= max(ar[po].F, ar[po].S);
            c += ar[po].S;

            e = ar[p].F;
            FOR(j,1,a)
            {
                e = e + e;
            }
            c += e;
            prin = max(prin, c);
        }

       ///cout << e << ' ' << c << endl;
        c = d;
    }

    cout << prin << endl;

    return 0;
}


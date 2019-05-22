#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define inf         freopen("54", "r", stdin)
#define outf        freopen("05.b", "w", stdout)

typedef long long LL;
typedef long double LD;

const int MAX = 100020;
LL n, bptr, fptr, sum[MAX], ara[MAX];

///for maximum answer and slopes are coming in sorted order
///apio2014 split the sequence

class solBag
{
    public:
    int start, i;
    LL preVal, slope;
    LD x1, y1, x2, y2;


    solBag() {}
    solBag(LL ss,LL pp,LL cc){
        start = ss;  preVal = pp; slope = cc;
        x1 = start; y1 = getCost( x1 );
        x2 = (1e9); y2 = getCost( x2 );
    }
    LL getCost(LL p){
        LL d = p - start;
        return preVal + d * slope;
    }

    LD crossEach(solBag &P) ///given two point of each line find the intersection point of two line
    {
        LD up = (x1 - P.x1)*(P.y1 - P.y2) - (y1 - P.y1) * (P.x1 - P.x2);
        LD down = (x1 - x2)*(P.y1 - P.y2) - (y1 - y2) * (P.x1 - P.x2);

        LD t = up / down;

        return x1 + t*(x2 - x1);
    }
};

solBag bag[MAX];
LL dp[MAX];
int rev[MAX][205];

int main()
{
    inf;
    //outf;
    int v, k;
    LL prevMin = 0;

    scanf("%d %d", &n, &k);
    FOR(i,1,n) scanf("%d", &ara[i]);
    FOR(i,1,n) sum[i] = sum[i - 1] + ara[i];

    FOR(l,1,k)
    {
        bptr = fptr = 0;
        FOR(i,1,n)
        {
            int v = sum[i];
            solBag newItem = solBag(v, dp[i], v); newItem.i = i;

            while(bptr - fptr >= 2 && bag[bptr - 2].crossEach( bag[bptr - 1] ) >= bag[bptr - 2].crossEach( newItem ))
                bptr--;
            bag[bptr++] = newItem;
            while(fptr + 1 < bptr && bag[fptr].getCost( v ) <=  bag[fptr + 1].getCost( v ))
                fptr++;

            dp[i] = bag[fptr].getCost(v);
            rev[i][l] = bag[fptr].i;
        }
    }

    LL prin = 0;
    printf("%lld\n", dp[n]);
    for(int i = k, p = n; i >= 1; i--)
    {
        int np = rev[p][i];
        prin += (sum[p] - sum[np]) * sum[np];
        printf("%d ", np);
        p = np;
    }
    printf("\n");
    return 0;
}

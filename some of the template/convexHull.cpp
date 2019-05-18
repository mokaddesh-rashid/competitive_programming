#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)

typedef long long LL;
typedef long double LD;

const LL MAX = 1000020;
int n, cost;

///Convex hull for a equation that define cost like (a - b) * (a - b) + c where a and c is known
/// and solBag is for minimizing cost
///https://open.kattis.com/problems/coveredwalkway
class solBag
{
    public:
    int start; LL preVal;
    LD x1, y1, x2, y2;


    solBag() {}
    solBag(LL ss,LL pp){
        start = ss;  preVal = pp;
        x1 = start; y1 = getCost( x1 );
        x2 = (1e9); y2 = getCost( x2 );
    }
    LL getCost(LL p){
        LL d = p - start;
        return preVal + d * d;
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
int bptr, fptr;

int main()
{

    int v;
    LL prevMin = 0;

    scanf("%d %d", &n, &cost);
    FOR(i,0,n-1){

        scanf("%d", &v);

        solBag newItem = solBag(v, (prevMin + cost));

        while(bptr - fptr >= 2 && bag[bptr - 2].crossEach( bag[bptr - 1] ) >= bag[bptr - 2].crossEach( newItem ))
            bptr--;
        bag[bptr++] = newItem;
        while(fptr + 1 < bptr && bag[fptr].getCost( v ) >=  bag[fptr + 1].getCost( v ))
            fptr++;

        prevMin = bag[fptr].getCost(v);
    }

    printf("%lld", prevMin);
    return 0;
}

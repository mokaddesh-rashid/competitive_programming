#include <bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out2.txt", "w", stdout)

typedef long long LL;
typedef long double LD;

///https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3134
const int MAX = 200020;
int n;
class solBag
{
    public:
    int startDay;
    LL preVal, cost, slope;
    LD x1, y1, x2, y2;


    solBag() {}
    solBag(LL ss,LL pp,LL cc)
    {
        startDay = ss;  preVal = pp; slope = cc;

        x1 = startDay; y1 = getCost( x1 );
        x2 = (1e9) + 5; y2 = getCost( x2 );
    }
    LL getCost(LL pDay)
    {
        LL d = pDay - startDay;
        return preVal + d * slope;
    }

    LD crossEach(solBag &P)
    {
        LD up = (x1 - P.x1)*(P.y1 - P.y2) - (y1 - P.y1) * (P.x1 - P.x2);
        LD down = (x1 - x2)*(P.y1 - P.y2) - (y1 - y2) * (P.x1 - P.x2);

        LD t = up / down;
        return x1 + t*(x2 - x1);
    }
};

class Machine
{
public:
    int d, p, r, g;
} mac[MAX];
vector<solBag> bag;

const int IT_MAX = (1<<18);
int bit[IT_MAX + 5];

void update(int p,int v)
{
    for(; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int query(int p)
{
    int ret = 0;
    for(; p; p -= p & (-p)) ret += bit[p];
    return ret;
}
int boro(int v)
{
    if(bit[IT_MAX] <= v) return -1;
    int can = 0, pos = 0;
    for(int i = 17; i >= 0; i--)
    {
        int newPos = (pos | (1 << i));

        if(can + bit[newPos] <= v)
        {
            can += bit[newPos];
            pos = newPos;
        }
    }
    return pos + 1;
}

vector<int> slopeId;
solBag bitBag[MAX];
int ase[MAX];

void del(int mid)
{
    ase[mid] = 0;
    bitBag[mid] = solBag(0, 0, 0);
    update(mid, -1);
}

int cntaa;
void maxProfit(LL &prevMax,int d)
{
    int x = bit[IT_MAX];
    while(bit[IT_MAX] >= 2)
    {
        int p = boro(0);
        int chi = boro( query(p) );

        if(bitBag[p].getCost( d ) < bitBag[chi].getCost( d )) del(p);
        else break;
    }

    FOR(i,0,bit[IT_MAX]-1)
    {
        int p = boro(i);
        prevMax = max(prevMax, bitBag[p].getCost(d));
        break;
    }
}

int chk(int up,int mid,int down) ///checking if slope(up) < slope(mid) < slope(down) -> intersection(up, mid) < intersection(up, down)
{
    solBag upore = bitBag[up], majhe = bitBag[mid], niche = bitBag[down];
    if(upore.crossEach( niche ) <= upore.crossEach(majhe)) del(mid); ///delete as condition is broke
    return ase[mid]; ///delete kora hole ase->mid 0 hobe or 1
}

int lastDay;
void add(solBag &myItem,int sid,int d)
{
    if(!ase[sid] || myItem.getCost(d) >= bitBag[sid].getCost(d))
    {
        bitBag[sid] =  myItem;
        if(!ase[sid]) update(sid, 1);
        ase[sid] = 1;
    }
    else return;

    int m = query( sid );
    if(m != 1 && m != bit[IT_MAX]) ///am i a valid insertion
    {
        int u = boro(m-2), d = boro(m);
        if(!chk(u, sid, d)) return; /// i am not a valid insertion so go back
    }

    while((query(sid) + 2) <= bit[IT_MAX]) /// check condition me, first and second immediate bigger slope
    {
        int m = boro( query( sid ) ), d = boro( query( m ) );
        if(chk(sid, m, d)) break; ///in case of current mid is not deleted  break
    }

    while(query( sid ) >= 3) /// check condition me, first and second immediate smaller slope
    {
        int m = boro( query(sid) - 2 ), u = boro( query(m) - 2 );
        if(chk(u, m, sid)) break;
    }
}

int main()
{
//    inf;
//    outf;
    for(int tt = 1; ;tt++)
    {
        int n;
        LL prevMax, lastDay;

        scanf("%d %lld %lld", &n, &prevMax , &lastDay);
        if(n == 0 && prevMax == 0 && lastDay == 0) return 0;

        FOR(i,0,n-1)
        scanf("%d %d %d %d", &mac[i].d, &mac[i].p, &mac[i].r, &mac[i].g);
        sort(mac, mac + n, [](Machine x,Machine y)
             {
                return x.d < y.d;
             });

        slopeId.clear();
        FOR(i,0,n-1) slopeId.push_back( mac[i].g );///types of slope can be
        sort(slopeId.begin(), slopeId.end());///slope need to be converted into 1-n to use bit

        memset(ase, 0, sizeof(ase));
        memset(bit, 0, sizeof(bit));
        FOR(i,0,n-1)
        {
            int d = mac[i].d, p = mac[i].p, r = mac[i].r, g = mac[i].g;
            int sid = lower_bound(slopeId.begin(), slopeId.end(), g) - slopeId.begin(); sid++;

            maxProfit(prevMax, d - 1);
            if(prevMax < p) continue; ///current max profit machine r price theke kom

            solBag myItem = solBag(d, (prevMax - p + r), g);
            add(myItem, sid, d);
        }

        maxProfit(prevMax, lastDay);
        printf("Case %d: %lld\n", tt, prevMax);
    }

    return 0;
}


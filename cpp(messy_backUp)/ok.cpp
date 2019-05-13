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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define sesh first
#define shuru second
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pii;


const int IT_MAX = 1 << 20;
const int INF = -1;

int bit[IT_MAX + 10];
int in[IT_MAX + 10];
void update(int p, int v) ///change value of position p to v
{
	int dv = v - in[p];
	in[p] = v;
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
int query(int p)
{
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}
int largerpos(int v)
{
	if (bit[IT_MAX] <= v) return INF;

	int p = 0;
	int s = 0;
	for (int i = 17; i >= 0; i--) {
		if (s + bit[p + (1 << i)] <= v) {
			s += bit[p + (1 << i)];
			p |= (1 << i);
		}
	}
	return p + 1;
}

int n, q;
pii ara[MAX];

int getVal(int l,int r)
{
    int sum = query(l - 1), ret = 0, p;

    while(true)
    {
        p = largerpos( sum );
        if(p == -1 || p > r) return ret;
        ret++; update(p, 0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
   // inf;
    //outf;

    int tc;

    sf(tc);
    FOR(tt,1,tc)
    {
        sff(n, q);///cin >> n >> q;
        FOR(i,0,q-1) sff(ara[i].shuru, ara[i].sesh);
        sort(ara, ara + q);
        FOR(i,1,n) update(i, 1);

        int prin = 0;

        FOR(i,0,q-1)
        {
            int l = ara[i].shuru, r = ara[i].sesh;

            if(!i) prin = getVal(l, r);
            else prin = min(prin, getVal(l, r));
        }

        pf("Case #%d: %d\n", tt, prin);
    }
    return 0;
}


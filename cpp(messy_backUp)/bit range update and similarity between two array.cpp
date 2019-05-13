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
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int ar[MAX], tree[20][MAX];
int ole[MAX], col[MAX], shuru[MAX], dude, val[MAX];

void mergeIt(int b, int e, int l, int r, int lev)
{
    int x = b, y = r;

    for(int p = b; b <= e || l <= r; p++)
    {
        if(b > e || (tree[lev + 1][l] <= tree[lev + 1][b] && l <= r))
        {
            tree[lev][p] = tree[lev + 1][l];
            l++;
        }
        else
        {
            tree[lev][p] = tree[lev + 1][b];
            b++;
        }
    }
    return;
}

void divide(int b, int e,int lev)
{
    if(b < e)
    {
        int mid = (b + e)>>1;

        divide(b, mid, lev + 1);
        divide(mid + 1, e, lev + 1);

        mergeIt(b, mid, mid + 1, e, lev);
    }
    else tree[lev][b] = ar[b];
    return;
}

int query(int lev,int b,int e,int st,int en,int v)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e)
    {
        int up = upper_bound(tree[lev] + b, tree[lev] + e + 1, v) - tree[lev];
        int low = lower_bound(tree[lev] + b, tree[lev] + e + 1, v) - tree[lev];

        return up - low;
    }

    int mid = (b + e)>>1;
    return query(lev + 1, b, mid, st, en, v) + query(lev + 1, mid + 1, e, st, en, v);
}

const int IT_MAX = 1 << 18;
const int INF = -1;

int bit[2][IT_MAX + 10];
void updateBit(int lev,int p,int dv) ///change value of position p to v
{
	for (; p <= IT_MAX; p += p & (-p)) bit[lev][p] += dv;
}
int queryBit(int lev,int p)
{
	int rv = 0;
	if(!p) return 0;
	for (; p; p -= p & (-p)) rv += bit[lev][p];
	return rv;
}
int largerpos(int lev,int v)
{
	if (bit[lev][IT_MAX] <= v) return INF;

	int p = 0;
	int s = 0;
	for (int i = 17; i >= 0; i--) {
		if (s + bit[lev][p + (1 << i)] <= v) {
			s += bit[lev][p + (1 << i)];
			p |= (1 << i);
		}
	}
	return p + 1;
}


int main()
{
    //inf;
//    outf;
    int tc;

    sf(tc);
    FOR(tt,1,tc)
    {
        int q, l, r, v, u, cp, nc, n;
        int chao = 0; mem(bit, 0); mem(val, 0);

        sff(n, q);
        FOR(i,1,n) sf(ole[i]); ///updates will be on ole
        FOR(i,1,n) sf(ar[i]); /// ar will always remain contant
        divide(1, n, 0);

        FOR(i,1,n) if(ole[i] == ar[i]) chao++, updateBit(0, i, 1);

        FOR(oo,0,q-1)
        {
            sfff(l, r, nc);
            l ^= chao; r ^= chao; nc ^= chao;

            while(true)
            {
                int nv = queryBit(0, l - 1);
                int v = largerpos(0,  nv);

                if(v == -1 || v > r) break;
                chao--;

                updateBit(0, v, -1);
            }

            while(true)
            {
                int nv = queryBit(1, l - 1);
                dude = largerpos(1, nv);

                if(dude == -1) break;
                u = shuru[ dude ]; v = dude;
                if(u > r) break;

                updateBit(1, dude, -1);
                cp = col[v]; chao -= val[v];

                if(u < l)
                {
                    updateBit(1, l - 1, 1);
                    col[l - 1] = cp; shuru[l - 1] = u; val[l - 1] = query(0, 1, n, u, l - 1, cp);
                    chao += val[l - 1];
                }
                if(v > r)
                {
                    updateBit(1, v, 1);
                    col[v] = cp; shuru[v] = r + 1; val[v] = query(0, 1, n, r + 1, v, cp);
                    chao += val[v];
                }

            }

            updateBit(1, r, 1);
            col[r] = nc; shuru[r] = l;  val[r] = query(0, 1, n, l, r, nc);
            chao += val[r];

            printf("%d\n", chao); ///number of positions where ar[i] == ole[i]
        }

    }
    return 0;
}



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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int IT_MAX = 1 << 18;
const int INF = -1;

LL bit[2][IT_MAX + 10];
LL in[2][IT_MAX + 10];
void update(int lev,int p, LL v) ///change value of position p to v
{
	LL dv = v - in[lev][p];
	in[lev][p] = v;
	for (; p <= IT_MAX; p += p & (-p)) bit[lev][p] += dv;
}
LL query(int lev,int p)
{
    if(!p) return 0;

	LL rv = 0;
	for (; p; p -= p & (-p)) rv += bit[lev][p];
	return rv;
}

int largerpos(LL v)
{
	if (bit[0][IT_MAX] <= v) return INF;

	LL p = 0;
	LL s = 0;
	for (int i = 17; i >= 0; i--) {
		if (s + bit[0][p + (1 << i)] <= v) {
			s += bit[0][p + (1 << i)];
			p |= (1 << i);
		}
	}
	return p + 1;
}

int cnt = 0;
LL n, T, prin = 0;

void jump()
{
    LL st = 1, en = T, mid, can = 0;
    LL hs = query(0, n);
    LL isAct = query(1, n);

    while(st <= en)
    {
        mid = (st + en)>>1;

        LL needT = hs * mid;
        if(needT % hs == 0 && needT % mid == 0 && needT <= T) can = max(can, mid), st = mid + 1;
        else en = mid - 1;

    }

    T -= (can * hs);
    prin += (can * isAct);
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;
    LL val;

    cin >> n >> T; cnt = n;
    FOR(i,1,n)
    {
        cin >> val;
        update(0, i, val);
        update(1, i, 1);
    }

    while(query(0, n))
    {
        jump( );
        while(true)
        {
            int p = largerpos( T );
            if(p == -1) break;

            update(0, p, 0);
            update(1, p, 0);
        }
    }

    cout << prin << endl;

    return 0;
}



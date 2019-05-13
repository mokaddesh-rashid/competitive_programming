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

LL bit[IT_MAX + 10];
LL in[IT_MAX + 10];
void update(int p, LL v) ///change value of position p to v
{
	LL dv = v - in[p];
	in[p] = v;
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
LL query(int p)
{
	LL rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}
int largerpos(LL v)
{
	if (bit[IT_MAX] <= v) return INF;

	LL p = 0;
	LL s = 0;
	for (int i = 17; i >= 0; i--) {
		if (s + bit[p + (1 << i)] <= v) {
			s += bit[p + (1 << i)];
			p |= (1 << i);
		}
	}
	return p + 1;
}

int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;
    int n, q, p, v;

    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> v;
        update(i, v);
    }

    FOR(tt, 1, q)
    {
        cin >> p >> v;
        update(p, v);

        if(in[1] == 0)
        {
            cout << 1 << endl;
            continue;
        }

        LL Voo = in[1];
        int show = -1, p;

        while(show == -1)
        {
            p = largerpos( Voo + Voo - 1 );
            if(p == INF) break;

            if(in[p] == query(p - 1)) show = p;

            Voo = query( p );
        }

        cout << show << endl;
    }

    return 0;
}


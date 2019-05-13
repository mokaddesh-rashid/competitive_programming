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
const LL INF = (LL)100000000000000000;

LL bit[2][IT_MAX + 10];
void update(int lev,int p, LL dv) ///change value of position p to v
{
	if(lev) for (; p <= IT_MAX; p += p & (-p)) bit[lev][p] = max(bit[lev][p], dv);
	else for (; p <= IT_MAX; p += p & (-p)) bit[lev][p] = min(bit[lev][p], dv);
}

int largerpos(LL v)
{
    int lev = 1;
	if (bit[lev][IT_MAX] <= v) return -1;

	LL p = 0;
	LL s = 0;
	for (int i = 17; i >= 0; i--) {
		if (max(s, bit[lev][p + (1 << i)]) <= v) {
			s = max(s, bit[lev][p + (1 << i)]);
			p |= (1 << i);
		}
	}
	return p + 1;
}

int smallerpos(LL v)
{
    int lev = 0;

	if (bit[lev][IT_MAX] >= v) return -1;

	LL p = 0;
	LL s = INF;
	for (int i = 17; i >= 0; i--)
    {
		if (min(s, bit[lev][p + (1 << i)]) >= v)
		{
			s = min(s, bit[lev][p + (1 << i)]);
			p |= (1 << i);
		}
	}
	return p + 1;
}


int ara[MAX], go[MAX][2], id[MAX], dp[MAX];

int rec(int p)
{
    if(p == -1) return 0;

    if(dp[p] != -1) return dp[p];
    return dp[p] = max(rec(go[p][0]), rec(go[p][1])) + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int n, d;

    cin >> n >> d;
    FOR(i,1,n) cin >> ara[i];
    FOR(i,0,IT_MAX) bit[0][i] = INF;

    REV(i,n,1)
    {
        go[i][0] =  largerpos(ara[i] + d - 1); go[i][1] =  smallerpos(ara[i] - d + 1);
        update(0, i, ara[i]);
        update(1, i, ara[i]);
    }

    mem(dp, -1);
    int prin = 0;
    FOR(i,1,n) prin = max(prin, rec(i));
    cout << prin << endl;

    return 0;
}



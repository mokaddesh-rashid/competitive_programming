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

const int IT_MAX = 1 << 18;
const int INF = -1;

int bit[IT_MAX + 10];
void update(int p,int dv) ///change value of position p to v
{
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
int query(int p)
{
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}
int id[MAX], nId;
void add(int v) {id[nId] = v; nId++;}
void sortId(){sort(id, id + nId);}
int getId(int v){return lower_bound(id, id + nId, v) - id;}

int n, ara[MAX];
LL k;

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    add( 0 );

    cin >> n >> k;
    FOR(i,0,n-1) cin >> ara[i], add( ara[i] );
    sortId();
    FOR(i,0,n-1) ara[i] = getId( ara[i] );

    LL prin = 0, cntInv = 0;
    int j = 0;

    FOR(i,0,n-1)
    {
        while(j < n)
        {
            int v = (query(MAX) - query( ara[j] ));

            if(cntInv + v > k) break;

            cntInv += v;
            update(ara[j], 1);
            j++;
        }
        cout << i + 1 << ' ' << j << ' ' << (j - i - 1)  << ' ' << cntInv << endl;
        prin  += (j - i - 1);
        cntInv -= query(ara[i] - 1);
        update(ara[i], -1);
    }

    cout << prin << endl;

    return 0;
}

/*
7 3
1 7 6 4 9 5 3
*/


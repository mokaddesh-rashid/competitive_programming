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
#define MAX 1000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int ar[MAX], n, p, val[MAX], uni[MAX], id[MAX], go[MAX];
vector<int> mat[MAX];
vector<PR> Q[MAX];

int bit[MAX];
void update(int i,int val)
{
	while(i<=n)
	{
		bit[i]=max(bit[i],val);
		i=i+(i&(-i));
	}
}
int query(int i)
{
	int ret=0;
	while(i)
	{
		ret=max(ret,bit[i]);
		i=i-(i&(-i));
	}
	return ret;
}

void rec(int p,int v)
{
    //cout << p << ' ' << v << endl;
    if(val[p] >= v) return;
    val[p] = v; update(p, v);

    for(auto x : mat[p])  rec(x, v + 1);
}

int prin[MAX];

int main()
{
    ///ios::sync_with_stdio(false);
    ///inf;
    //outf;

    int tc;

    sf(tc);

    FOR(tt,1,tc)
    {
        int q, l, r, c;
        mem(uni, 0); mem(id, 0); mem(go, 0);

        sff(n, q);
        FOR(i,1,n) sf(ar[i]), uni[ ar[i] ] = 1;

        c = 0;
        FOR(i,1,MAX-1)
        {
            if(uni[i]) c++;
            id[i] = c;
        }
        FOR(i,1,n) ar[i] = id[ ar[i] ];
        FOR(i,0,n) go[i] = n + 1;

        REV(i,n,1)
        {
            int mina = n + 1;
            FOR(j,ar[i]+1,c + 1)
            {
                if(mina < go[j]) continue;

                mat[ i ].PB( go[j] );
                mina = min(mina, go[j]);
            }
            go[ ar[i] ] = i;
        }

        FOR(i,1,q)
        {
            sff(l, r);
            Q[l].PB( MP(r, i) );
        }
        REV(i,n,1)
        {
            rec(i, 1);
            for(auto x : Q[i])
                prin[ x.S ] = query( x.F );
        }

        FOR(i,1,q) pf("%d\n", prin[i]);
        clean(Q, n); clean(mat, n);
    }
    return 0;
}

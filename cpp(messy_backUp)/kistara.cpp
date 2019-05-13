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

int bit[MAX];
void update(int i,int val)
{
	while(i<=MAX-1)
	{
		bit[i]=bit[i]+val;
		i=i+(i&(-i));
	}
}
int query(int i)
{
	int ret=0;
	while(i)
	{
		ret=ret+bit[i];
		i=i-(i&(-i));
	}
	return ret;
}

PR ran[MAX];
int n, q;
vector<int> que[MAX], chng[MAX];
vector<PR> offLine[MAX];
int prin[MAX];

int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    ///outf;
    int x, a;

    sff(n, q);///cin >> n >> q;
    FOR(i,0,n-1) sff(ran[i].F, ran[i].S);///cin >> ran[i].F >> ran[i].S;
    FOR(i,0,q-1)
    {
        sf(x);///cin >> x;
        int p = 1;
        FOR(l,1,x)
        {
            sf(a);///cin >> a;
            que[i].PB( a );

            if(p <= a - 1) offLine[p].PB( MP(a - 1, i) );
            p = a + 1;
        }
        offLine[p].PB( MP(MAX - 1, i) );
    }

    FOR(i,0,n-1)
    {
        update(ran[i].S, 1);
        chng[ran[i].F].PB( ran[i].S );
    }

    FOR(i,1,MAX-1)
    {
        int j = 0;
        for(auto x : offLine[i])
        {
            prin[ x.S ] -= query(x.F);
            j++;
        }

        for(auto x : chng[i])
        {
            update(x, -1);
        }
    }

    FOR(i,0,q-1) pf("%d\n",prin[i] + n);

    return 0;
}


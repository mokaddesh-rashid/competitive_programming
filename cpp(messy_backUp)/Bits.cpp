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
#define MAX (1<<18)
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

LL bit[MAX];
void update(int i,LL val)
{
	while(i<=MAX)
	{
		bit[i]=(bit[i]+val);
		i=i+(i&(-i));
	}
}
LL query(int i)
{
	LL ret=0;
	while(i)
	{
		ret=(ret+bit[i]);
		i=i-(i&(-i));
	}
	return ret;
}

int bit_search(LL v)
{
	LL sum = 0;
	int pos = 0;
	int LOGN = log(MAX) / log(2);
	LOGN++;

	for(int i=LOGN; i>=0; i--)
	{
		if(pos + (1 << i) < MAX && sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}

int val[MAX];
int main()
{
    ios::sync_with_stdio(false);
   /// inf;
    //outf;
    int n, q, p, v;

    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> val[i];
        update(i, val[i]);
    }

    FOR(tt, 1, q)
    {
        cin >> p >> v;

        update(p, val[p] * -1);
        val[p] = v;
        update(p, val[p]);

        if(val[1] == 0)
        {
            cout << 1 << endl;
            continue;
        }

        LL Voo = val[1];
        int show = -1, p;

        while(show == -1)
        {
            p = bit_search( Voo + Voo - 1 );
            if(p > n) break;
            else if(val[p] == query(p - 1)) show = p;

            if(Voo == 1) Voo++;
            else Voo = query( p );
        }

        cout << show << endl;
    }

    return 0;
}

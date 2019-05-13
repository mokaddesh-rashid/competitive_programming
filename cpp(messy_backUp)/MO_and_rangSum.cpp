#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define PB push_back
#define F first
#define S second
#define X first.first
#define C first.second
#define L second.first
#define R second.second
#define MP make_pair

typedef pair<int,int> pii;
typedef pair<pii,pii> pi4;
typedef long long LL;

const int MAX = 300005;

map<LL,int> mopa;
int getId(LL p)
{
    if(mopa[p] == 0) mopa[p] = mopa.size();
    return mopa[p];
}

struct node
{
    int l, r, p;
}qr[MAX];
int block;
class cmp
{
public:
    bool operator()( node f, node s )
    {
      if( f.l/block != s.l/block ) return f.l/block < s.l/block;
      return f.r < s.r;
    }
};


LL prin = 0;
int ara[MAX], ty[MAX], n, samne[MAX], pise[MAX], cnt[MAX];
LL val[MAX], show[MAX];

void addLeft(int p)
{
    prin += cnt[ samne[p - 1] ];
    cnt[ val[p - 1] ]++;
}
void delLeft(int p)
{
    cnt[ val[p - 1] ]--;
    prin -= cnt[ samne[p - 1] ];
}

void addRight(int p)
{
   /// cout << p << " khuj " << pise[p] << ' ' << endl;
    prin += cnt[ pise[p] ];
    cnt[ val[p] ]++;
   // cout << "added '" << val[p] << "' " << ' ' << prin << endl;
}

void delRight(int p)
{
    cnt[ val[p] ]--;
    prin -= cnt[ pise[p] ];
}

int main()
{
    ios::sync_with_stdio(false);
 //   inf;
//    outf;
    int n, k, q;

    cin >> n >> k; block = sqrt(n);
    FOR(i,1,n) cin >> ty[i];
    FOR(i,1,n) cin >> ara[i];

    LL c = 0; getId( 0 );
    FOR(i,1,n)
    {
        if(ty[i] == 1) c += ara[i];
        else c -= ara[i];

        val[i] = c; getId( val[i] );
    }

    FOR(i,0,n)
    {
        samne[i] = getId( val[i] + k );
        pise[i] = getId( val[i] - k );
        val[i] = getId( val[i] );
    }

    cin >> q;
    FOR(i,0,q-1) cin >> qr[i].l >> qr[i].r, qr[i].p = i;
    sort(qr, qr + q, cmp());

    int x, y, l, r, p;

    x = 1; addLeft(1); y = 0;
    FOR(i,0,q-1)
    {
        l = qr[i].l; r = qr[i].r; p = qr[i].p;

        while(x > l) addLeft(--x);
        while(y < r) addRight(++y);
        while(x < l) delLeft(x++);
        while(y > r) delRight(y--);

        show[p] = prin;
    }

    FOR(i,0,q-1) cout << show[i] << endl;
    return 0;
}


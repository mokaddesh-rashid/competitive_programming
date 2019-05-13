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
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

vector<int> pos[200010], val[200010];
int ar[200020], cnt[200010], ooh[200020], prv[200010];
pr info[200020];
class compare
{
public:
    bool operator()(int x, int y)
    {
        return ooh[x] > ooh[y];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    mem(ooh,-1);mem(prv,-1);
    int i, j, x, y, n, m, lp = -1, k, a, b, c, d;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> info[i].F >> info[i].S;
        ooh[info[i].F] = i;
        pos[info[i].F].PB(i);
        val[info[i].F].PB(info[i].S);
    }
    REV(i,n-1,0)
    {
        x = info[i].F;
        if( cnt[x] == 0 )
        {
           cnt[x]++;
           if( lp != -1 ) prv[lp] =  i;
           lp = i;
        }
    }

    cin >> m;
    while(m--)
    {
       cin >> k;
       FOR(i,0,k-1) cin >> ar[i];
       sort( ar, ar+k, compare() );
       x = 0;
       y = n-1;
       while( y != -1 && ar[x] == info[y].F )
       {
           x++;
           y = prv[y];
       }
       a = x; b = prv[y];
       while( b != -1 && ar[a] == info[b].F )
       {
           a++;
           b = prv[b];
       }
       if( y == -1 ) cout << "0 0" << endl;
       else
       {
           x = info[y].F;
           vector<int>::iterator low;
           low=lower_bound (pos[x].begin(), pos[x].end(), b );
           int p = low-pos[x].begin();
           cout << x << ' ' << val[x][p] << endl;
       }
    }
    return 0;

}



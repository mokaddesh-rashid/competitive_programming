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

struct node
{
    int x, y, v;
};
node pos[1000010];
class compare
{
public:
    bool operator()(node f, node s)
    {
        return f.v<s.v;
    }
};
int ar[1000100], p;
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i, j, x, y, n, m, a, b, c, d, z, cnt = 0, ex, da = 0;
    cin >> n >> m;
    FOR(i,0,n-1)
    {
        cin >> a;
        if( a < 0 ) a = 1, cnt++;
        else a = 0;
        ar[i] = a;
    }
    if( cnt > m ) da = -1;
    ex = m-cnt;
    x = y = -1;
    z = 0;
    FOR(i,0,n-1)
    {
        if( ar[i] == 0 &&  x != -1 && i == n-1 )
       {
          // cout << x << ' ' << i-x << endl;
           pos[p].x = x;
           pos[p].y = i;
           pos[p].v = i-x;
           x = i;
           p++;
           z = 0;
       }
       else if( ar[i] == 0 ) z++;
       else if( ar[i] == 1 && ( z == 0 || x == -1 ) ) x = i, z = 0;
       else if( ar[i] == 1 &&  z != 0 )
       {
        //   cout << x << ' ' << i-x << endl;
           pos[p].x = x;
           pos[p].y = i;
           pos[p].v = i-x-1;
           x = i;
           p++;
           z = 0;
       }

    }
    sort(pos,pos+p,compare() );
    FOR(i,0,p-1)
    {
        //cout << pos
        FOR(j,pos[i].x,pos[i].y)
        {
            if( pos[i].v == pos[i+1].v && (pos[i].x == 0 || pos[i].y == n-1 )) swap( pos[i], pos[i+1] );
            if( ex > 0 && ar[j] == 0 ) ar[j] = 1, ex--;
        }
    }

    x = 0;
    cnt = 0;
    FOR(i,0,n-1)
    {
       //cout << ar[i] << ' ';
       if( x != ar[i] ) cnt++;
       x = ar[i];
    }
    if( da == -1 ) cout << da;
    else cout << cnt << endl;
    return 0;
}



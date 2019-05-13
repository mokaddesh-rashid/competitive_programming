#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
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
typedef pair<int,int> p_i;


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x, y, n, m, a, b, l = 0, r = 0, k, z;

    cin >> a >> b >> x >> y >> k;

    if( a >= x && b <= y )
        l = a, r = b;
    else if( x >= a && y <= b )
        l = x, r = y;
    else if( a <= x && b >= x && b <= y  )
        l = x, r = b;
    else if( x <= a && a <= y && y <= b )
        l = a, r = y;
    //cout << l << ' ' << r << endl;
    z = 0;
    if( l != 0 && r != 0 )
    z = r-l+1;
    if( k >=l && k <= r )
        z--;

    cout << max( (LL)0, z );




    return 0;

}


